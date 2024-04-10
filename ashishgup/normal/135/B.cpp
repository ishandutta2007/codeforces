#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

struct point
{
	int x, y, idx;
};

//Finds squared euclidean distance between two points
int dist(point &a, point &b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

//Checks if angle ABC is a right angle
int isOrthogonal(point &a, point &b, point &c)
{
	return (b.x-a.x) * (b.x-c.x) + (b.y-a.y) * (b.y-c.y) == 0;
}

//Checks if ABCD form a rectangle (in that order)
int isRectangle(point &a, point &b, point &c, point &d)
{
	return isOrthogonal(a, b, c) && isOrthogonal(b, c, d) && isOrthogonal(c, d, a);
}

//Checks if ABCD form a rectangle, in any orientation
int isRectangleAnyOrder(point &a, point &b, point &c, point &d)
{
	return isRectangle(a, b, c, d) || isRectangle(b, c, a, d) | isRectangle(c, a, b, d);
}

//Checks if ABCD form a square (in that order)
int isSquare(point &a, point &b, point &c, point &d)
{
	return isRectangle(a, b, c, d) && dist(a, b) == dist(b, c);
}

//Checks if ABCD form a square, in any orientation
int isSquareAnyOrder(point &a, point &b, point &c, point &d)
{
	return isSquare(a, b, c, d) || isSquare(b, c, a, d) | isSquare(c, a, b, d);
}

point a[10];

int32_t main()
{
	IOS;
	int n=8;
	for(int i=0;i<8;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].idx=i+1;
	}
	for(int i=0;i<(1<<8);i++)
	{
		if(__builtin_popcount(i)!=4)
			continue;
		vector<point> p, q;
		for(int j=0;j<8;j++)
		{ 
			if(i>>j & 1)
				p.push_back(a[j]);
			else
				q.push_back(a[j]);
		}
		if(isRectangleAnyOrder(p[0], p[1], p[2], p[3]) && isSquareAnyOrder(q[0], q[1], q[2], q[3]))
		{
			cout<<"YES"<<endl;
			for(auto &it:q)
				cout<<it.idx<<" ";
			cout<<endl;
			for(auto &it:p)
				cout<<it.idx<<" ";
			cout<<endl;
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}