#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e15;
int n,m,K;
const int N=505;
ll f[N][N];
int p[N],v[N];
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	for (int i=1;i<=n;++i)
		scanf("%d",&v[i]);
	for (int i=1;i<=n+1;++i)
		for (int j=1;j<=n+1;++j)
			f[i][j]=inf;
	f[1][1]=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=i;++j)
			for (int k=i+1;k<=n;++k)
				f[k][j+1]=min(f[k][j+1],f[i][j]+(ll)v[i]*(p[k]-p[i]));
	ll ans=inf;
	int q=n-K;
	for (int i=q;i<=n;++i)
		for (int j=q;j<=n;++j)
				ans=min(ans,f[i][j]+max(0ll,(ll)v[i]*(m-p[i])));
	cout<<ans;
	return 0;
}