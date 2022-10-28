#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;


struct point
{
	int x, y;
};

int n, ans=0;
point a[N], b[N];
map<pair<int, int>, int> m;

int get(int x1, int y1, int x2, int y2)
{
	return __gcd(abs(y2-y1), abs(x2-x1)) + 1;
}

pair<int, int> intersect(point a, point b, point c, point d)
{
	int a1=b.y-a.y;
	int b1=a.x-b.x;
	int c1=a1 * a.x  + b1 * a.y;

	int a2=d.y-c.y;
	int b2=c.x-d.x;
	int c2=a2 * c.x + b2 * c.y;

	int determinant = a1 * b2 - a2 * b1;
	if(determinant==0)
		return {-1e9, -1e9};
	else
	{
		if((b2*c1 - b1*c2)%determinant!=0 || (a1*c2 - a2*c1)%determinant!=0)
			return {-1e9, -1e9};
		int x=(b2*c1 - b1*c2)/determinant;
		int y=(a1*c2 - a2*c1)/determinant;
		if(x<min(a.x, b.x) || x>max(a.x, b.x))
			return {-1e9, -1e9};
		if(y<min(a.y, b.y) || y>max(a.y, b.y))
			return {-1e9, -1e9};
		if(x<min(c.x, d.x) || x>max(c.x, d.x))
			return {-1e9, -1e9};
		if(y<min(c.y, d.y) || y>max(c.y, d.y))
			return {-1e9, -1e9};
		return {x, y};
	}
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
		ans+=get(a[i].x, a[i].y, b[i].x, b[i].y);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			pair<int, int> p = intersect(a[i], b[i], a[j], b[j]);
			m[p]++;
		}
	}
	for(auto &it:m)
	{
		if(it.first.first<-1e6)
			continue;
		for(int k=1;;k++)
		{
			if(k*(k+1)/2 == it.second)
			{
				ans-=k;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}