#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005,P=1e9+7;
int n,cc[N];ll ans,a[N],w[N][45],s[N][45];
vector<int>g[N];
void dfs(int x,int p)
{
	cc[x]=cc[p]+1;int tt=0;
	for(int i=1;i<cc[x];i++)w[x][i]=__gcd(w[p][i],a[x]),s[x][i]=s[p][i];
	w[x][cc[x]]=a[x];s[x][cc[x]]=1;
	for(int i=1,j=1;i<=cc[x];i=j)
	{
		while(j<=cc[x]&&w[x][i]==w[x][j])j++;
		int ss=0;for(int k=i;k<j;k++)ss+=s[x][k];
		w[x][++tt]=w[x][i];s[x][tt]=ss;
	}
	cc[x]=tt;
	for(int i=1;i<=tt;i++)ans=(ans+w[x][i]*s[x][i]%P)%P;
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=p)dfs(g[x][i],x);
}
int main()
{
	scanf("%d",&n);int tt=n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	cc[0]=0;dfs(1,0);printf("%lld\n",ans);return 0;
}