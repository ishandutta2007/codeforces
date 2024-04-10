#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

const int N=1e5+5;

int n;
int ans[N];
pair<pair<int, int>, int> a[N];

int dist(int x, int y)
{
	return (x*x + y*y);
}

int32_t main()
{
	IOS;
	srand(time(0));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x.x>>a[i].x.y;
		a[i].y=i;
	}
	while(1)
	{
		int curx=0, cury=0;
		for(int i=1;i<=n;i++)
		{
			if(dist(curx+a[i].x.x, cury+a[i].x.y) <= dist(curx-a[i].x.x, cury-a[i].x.y))
			{
				curx+=a[i].x.x;
				cury+=a[i].x.y;
				ans[a[i].y]=1;
			}
			else
			{
				curx-=a[i].x.x;
				cury-=a[i].x.y;
				ans[a[i].y]=-1;
			}
		}
		if(dist(curx, cury)<=(225 * 1e10))
			break;
		random_shuffle(a+1, a+n+1);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}