#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

struct data
{
	int len, dot, cross;

	data() {}

	data(int len, int dot, int cross) : len(len), dot(dot), cross(cross) {}

	bool operator ==(const data &d) const
	{
		return (len==d.len && dot==d.dot && cross==d.cross);
	}

	bool operator !=(const data &d) const
	{
		return (len!=d.len || dot!=d.dot || cross!=d.cross);
	}
};

struct point
{
	int x, y;

	point () {}

	point(int x, int y) : x(x), y(y) {}

	void operator =(const point &p)
	{
		x=p.x, y=p.y;
	}

	point operator +(const point&p) const
	{
		point pt(x + p.x, y + p.y);
		return pt;
	}

	point operator -(const point&p) const
	{
		point pt(x - p.x, y - p.y);
		return pt;
	}

	int crossProduct(const point &p) const
	{	
		return x * p.y - y * p.x;
	}	

	int dotProduct(const point &p) const
	{
		return x * p.x + y * p.y;
	}

	int dist()
	{
		return x*x + y*y;
	}
};

bool comp(point &p1, point &p2)
{
	if(p1.x!=p2.x)
		return p1.x<p2.x;
	return p1.y<p2.y;
}

bool cw(point &a, point &b, point &c)
{
	int area=a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	return area<0;
}

bool ccw(point &a, point &b, point &c)
{
	int area=a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	return area>0;
}

vector<point> convex_hull(vector<point> &v)
{
	if(v.size()==1)
		return v;

	sort(v.begin(), v.end(), comp);

	point p1=v[0], p2=v.back();

	vector<point> up, down;
	up.push_back(p1);
	down.push_back(p1);

	for(int i=1;i<v.size();i++)
	{
		if(i==v.size()-1 || cw(p1, v[i], p2))
		{
			while(up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], v[i]))
				up.pop_back();
			up.push_back(v[i]);
		}
		if(i==v.size()-1 || ccw(p1, v[i], p2))
		{
			while(down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], v[i]))
				down.pop_back();
			down.push_back(v[i]);
		}
	}

	for(int i=down.size()-2;i>0;i--)
		up.push_back(down[i]);

	return up;
}

vector<int> prefix_function(vector<data> &v) 
{
	int n = (int)v.size();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && v[i] != v[j])
			j = pi[j-1];
		if (v[i] == v[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

void find_occurences(vector<data> &text, vector<data> &pattern)
{
	vector<data> v=pattern;
	v.push_back(data(-1, -1, -1));
	for(auto &it:text)
		v.push_back(it);
	int sz1=text.size(), sz2=pattern.size();
	vector<int> lps=prefix_function(v);
	for(int i=sz2+1;i<=sz1+sz2;i++)
	{
		if(lps[i]==sz2)
		{
			cout<<"YES";
			exit(0);
		}
	}
}

int n, m;
vector<point> poly1, poly2, hull1, hull2;
vector<data> v1, v2; 

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x, y;
		cin>>x>>y;
		point p(x, y);
		poly1.push_back(p);
	}
	for(int i=1;i<=m;i++)
	{
		int x, y;
		cin>>x>>y;
		point p(x, y);
		poly2.push_back(p);
	}
	hull1=convex_hull(poly1);
	hull2=convex_hull(poly2);
	if(hull1.size()!=hull2.size())
	{
		cout<<"NO";
		return 0;
	}
	int sz=hull1.size();
	for(int i=0;i<sz;i++)
	{
		data cur;
		point a=hull1[i], b=hull1[(i+1)%sz], c=hull1[(i+2)%sz];
		cur.len=(b-a).dist();
		cur.dot=(b-a).dotProduct(c-b);
		cur.cross=(b-a).crossProduct(c-b);
		v1.push_back(cur);
	}
	for(int i=0;i<sz;i++)
		v1.push_back(v1[i]);
	for(int i=0;i<sz;i++)
	{
		data cur;
		point a=hull2[i], b=hull2[(i+1)%sz], c=hull2[(i+2)%sz];
		cur.len=(b-a).dist();
		cur.dot=(b-a).dotProduct(c-b);
		cur.cross=(b-a).crossProduct(c-b);
		v2.push_back(cur);
	}
	find_occurences(v1, v2);
	cout<<"NO";
	return 0;
}