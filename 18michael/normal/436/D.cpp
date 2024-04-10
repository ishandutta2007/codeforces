#include<bits/stdc++.h>
using namespace std;
int n,m,mx=0;
int a[100002],b[2002],prea[200002],preb[200002],R[200002],tmp[200002],pos[2002];
int dp[2][200002],t[2][2002];
inline void upd(int &x,int y)
{
	if(y>x)x=y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),prea[a[i]]=1,mx=max(mx,a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]),preb[b[i]]=1,t[1][i]=n;
	sort(a+1,a+n+1),sort(b+1,b+m+1),++mx;
	for(int i=mx,x=mx;~i;R[i]=x,--i)if(prea[i] && !prea[i+1])x=i;
	for(int i=1;i<=mx;++i)prea[i]+=prea[i-1],preb[i]+=preb[i-1];
	for(int i=1;i<=mx;++i)
	{
		upd(tmp[i],tmp[i-1]);
		if(prea[i]==prea[i-1])upd(dp[1][i],tmp[i]);
		else if(i==R[i])
		{
			for(int j=0;j<=m;++j)
			{
				for(;t[0][j]<=i && preb[i]-preb[i-prea[i]+prea[t[0][j]]]>=j;++t[0][j])if(!t[0][j] || prea[t[0][j]]==prea[t[0][j]-1])pos[j]=t[0][j];
				upd(dp[0][i],dp[1][pos[j]]+preb[i]-preb[i-prea[i]+prea[pos[j]]]);
			}
			for(int j=0;j<=m;++j)
			{
				for(;a[t[1][j]]+1>i && preb[i+t[1][j]-prea[i]]>=j;--t[1][j]);
				if(preb[i+t[1][j]-prea[i]]<j && t[1][j]<n)++t[1][j];
				upd(tmp[max(a[t[1][j]]+1,i)],dp[0][i]+preb[i+t[1][j]-prea[i]]-preb[i]);
			}
		}
	}
	return 0&printf("%d",dp[1][mx]);
}