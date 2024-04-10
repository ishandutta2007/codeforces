#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=4e5+5;

struct Point
{
	int x, y, store, orient;

	Point operator -(Point p)
	{
		return {x-p.x, y-p.y};
	}

	int dist()
	{
		return x*x + y*y;
	}
};

bool by_x(Point &a, Point &b)
{
	return a.x < b.x;
}

bool by_y(Point &a, Point &b)
{
	return a.y < b.y;
}

int n, ans=1e18;
Point pt[N];
map<int, int> idx1, idx2, o1, o2;
vector<int> opp={0, 4, 3, 2, 1};

int solve(int L, int R)
{
	if(L==R)
		return 1e18;
	int M=(L+R)/2;
	sort(pt+L, pt+R+1, by_x);
	int d=min(solve(L, M), solve(M+1, R));
	int midx=pt[L+(R-L+1)/2].x;
	vector<Point> v;
	for(int i=L;i<=R;i++)
	{
		if(Point{pt[i].x-midx, 0}.dist()<d)
		{
			v.push_back(pt[i]);
		}
	}
	sort(v.begin(), v.end(), by_y);
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(Point{0, v[i].y-v[j].y}.dist()>d)
				break;
			if(v[i].store==v[j].store)
				continue;
			int cur=(v[i]-v[j]).dist();
			idx1[cur]=v[i].store;
			idx2[cur]=v[j].store;
			o1[cur]=v[i].orient;
			o2[cur]=v[j].orient;
			d=min(d, (v[i]-v[j]).dist());
		}
	}
	return d;
}   

int dx[4]={1, -1, 1, -1};
int dy[4]={1, 1, -1, -1};

int32_t main()
{
	IOS;	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int idx=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x, y;
		cin>>x>>y;
		for(int j=0;j<4;j++)
		{
			pt[idx]={x*dx[j], y*dy[j], i, j+1};
			idx++;
		}
	}
	idx--;
	int ans=solve(1, idx);
	cout<<idx1[ans]<<" "<<o1[ans]<<" "<<idx2[ans]<<" "<<opp[o2[ans]];
	return 0;
}