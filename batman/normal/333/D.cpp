#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1010)


ll n,m,a[N][N],now[N],cnt;
bool mark[N][N];

bool check(ll x)
{
	memset(mark,0,sizeof mark);
	for(int i=0;i<n;i++)
	{
		cnt=0;
		for(int j=0;j<m;j++)
			if(a[i][j]>=x)
			{
				for(int k=0;k<cnt;k++)
				{
					if(mark[now[k]][j])
						return 1;
					mark[now[k]][j]=1;
				}
				now[cnt++]=j;
			}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	ll l=0,r=1e9+1;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l<<"\n";
	return 0;
}