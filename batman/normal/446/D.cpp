#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)550)

ll n,m,k,n0,n1,pos[N],ed[N][N];
ld A[N][N],dp[N][N],ans[1][N];
pair <bool,ll> a[N];
ld ex[N][N];

void mul(ld x[N][N],ld y[N][N],bool pp)
{
	for(int i=0;i<1+(n1-1)*pp;i++)
		for(int j=0;j<n1;j++)
		{
			ex[i][j]=0;
			for(int k=0;k<n1;k++)
				ex[i][j]+=x[i][k]*y[k][j];
		}
	for(int i=0;i<1+(n1-1)*pp;i++)
		for(int j=0;j<n1;j++)
			x[i][j]=ex[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;k-=2;
	for(int i=0;i<n;i++)
		cin>>a[i].first,a[i].second=i,n0+=(a[i].first==0);
	sort(a,a+n);
	for(int i=0;i<n;i++)pos[a[i].second]=i;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;v--;u--;
		A[pos[v]][pos[v]]--;A[pos[u]][pos[u]]--;
		ed[pos[v]][pos[u]]++;ed[pos[u]][pos[v]]++;
		if(!a[pos[v]].first)A[pos[v]][pos[u]]++;
		if(!a[pos[u]].first)A[pos[u]][pos[v]]++;
	}
	for(int i=0;i<n0;i++)
	{
		for(int j=i;j<n0;j++)
			if(A[j][i])
			{
				for(int k=0;k<n;k++)swap(A[j][k],A[i][k]);
				break;
			}
		for(int j=0;j<n0;j++)
		{
			if(i==j)continue;
			ld ex=A[j][i]/A[i][i];
			for(int k=0;k<n;k++)A[j][k]-=A[i][k]*ex;
		}
	}
	for(int i=n0;i<n;i++)
	{
		for(int j=0;j<n0;j++)dp[j][i]=-A[j][i]/A[j][j];
		ans[0][i-n0]=dp[0][i];
		for(int j=n0;j<n;j++)
		{
			ll deg=0;
			for(int k=0;k<n;k++)
			{
				deg+=ed[j][k];
				if(k<n0)dp[j][i]+=dp[k][i]*ed[j][k];
				else if(k==i)dp[j][i]+=ed[j][k];
			}
			dp[j][i]/=deg;
		}
	}
	n1=n-n0;
	for(int i=0;i<n1;i++)
		for(int j=0;j<n1;j++)
			dp[i][j]=dp[i+n0][j+n0];
	for(int i=0;i<30;i++)
	{
		if((k&(1<<i)))mul(ans,dp,0);
		mul(dp,dp,1);
	}
	for(int i=0;i<n1;i++)
		if(a[i+n0].second==n-1)
			return cout<<fixed<<setprecision(15)<<ans[0][i]<<"\n",0;
	return 0;
}