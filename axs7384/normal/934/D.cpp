#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt,a[10000];
signed main()
{
	cin>>n>>m;
	a[0]=n;
	while (a[cnt]>=m||a[cnt]<0)
	{
		int x=a[cnt]/m,y=a[cnt]%m;
		if (y<0)
		{
			--x;
			y+=m;
		}
		a[cnt]=y;
		a[++cnt]=-x;
	}
	cout<<cnt+1<<'\n';
	for (int i=0;i<=cnt;++i)
		cout<<a[i]<<' ';
}