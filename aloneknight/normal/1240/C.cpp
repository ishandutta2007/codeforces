#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
const int N=500005;
int n,k;ll f[N][2];
vector<pii>G[N];
vector<ll>V;
void dfs(int x,int p)
{
	ll S=0,s1=0,s2=0;
	for(int i=0;i<G[x].size();i++)
	{
		int y=G[x][i].Y;if(y==p)continue;
		dfs(y,x);S+=f[y][1];
	}
	V.clear();
	for(int i=0;i<G[x].size();i++)
	{
		int y=G[x][i].Y,w=G[x][i].X;if(y==p)continue;
		ll t=f[y][0]+w-f[y][1];if(t>0)V.pb(t);
	}
	sort(V.begin(),V.end());reverse(V.begin(),V.end());
	for(int i=0;i<k-1&&i<V.size();i++)s1+=V[i];
	for(int i=0;i<k&&i<V.size();i++)s2+=V[i];
	f[x][0]=S+s1;f[x][1]=S+s2;
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1,u,v,w;i<n;i++)scanf("%d%d%d",&u,&v,&w),G[u].pb(mp(w,v)),G[v].pb(mp(w,u));
		dfs(1,0);printf("%lld\n",f[1][1]);
		for(int i=1;i<=n;i++)G[i].clear();
	}
	return 0;
}