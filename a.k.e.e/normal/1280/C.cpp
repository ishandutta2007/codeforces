#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005;

int n;
ll Min,Max;
vector<pii> G[MAXN];
int size[MAXN];
void dfs(int u,int pa)
{
	size[u]=1;
	for(auto p:G[u])
	{
		int v=p.x,c=p.y;
		if(v==pa)continue;
		dfs(v,u);
		size[u]+=size[v];
		if(size[v]&1)Min+=c;
		Max+=1ll*c*min(size[v],n-size[v]);
	}
}
void solve()
{
	Min=Max=0;
	int u,v,c;
	readint(n);n*=2;
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v),readint(c);
		G[u].pb(mp(v,c)),G[v].pb(mp(u,c));
	}
	dfs(1,-1);
	cout<<Min<<" "<<Max<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}