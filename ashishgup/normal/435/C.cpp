#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e3+5;
const int offset=1e3;

int n;
int a[N], x[N], y[N];
char ans[N][N];

int32_t main()
{
	IOS;
	cin>>n;
	int cur=1, ymax=0, ymin=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=offset, y=1;
	int xmin=N, xmax=0;
	for(int i=1;i<=n;i++)
	{
		char ch='/';
		int changex=-1;
		if(i%2==0)
		{
			ch='\\';
			changex=+1;
		}
		for(int j=1;j<=a[i];j++)
		{
			ans[x][y]=ch;
			xmin=min(xmin, x);
			xmax=max(xmax, x);
			x+=changex;
			y++;
		}
		x-=changex;
	}
	for(int i=xmin;i<=xmax;i++)
	{
		for(int j=1;j<y;j++)
		{
		    if(ans[i][j]!=ans[0][0])
			    cout<<ans[i][j];
			else
			    cout<<" ";
		}
		if(i!=xmax)
			cout<<endl;
	}
}