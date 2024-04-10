#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define c first
#define v second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(register int i=(x);i<=(y);++i)
#define try(i,x,y) for(register int i=(x);i>=(y);--i)
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=500005;
 
int n,k;
vector<pii> G[MAXN];
ll f[MAXN],g[MAXN],tmp[MAXN<<1|1];
int cnt;
void dfs(int u,int pa)
{
	f[u]=g[u]=0;
	int cnt=0;
	for(auto p:G[u])
		if(p.v!=pa)
		{
			dfs(p.v,u);
			f[u]+=f[p.v];g[u]+=f[p.v];
		}
	int l=cnt+1;
	for(auto p:G[u])
		if(p.v!=pa && g[p.v]+p.c-f[p.v]>0)tmp[++cnt]=g[p.v]+p.c-f[p.v];
	int r=cnt;
	if(l>r)return;
	sort(tmp+l,tmp+r+1);
	enum(i,l,r)
	{
		if(r-i+1<=k)f[u]+=tmp[i];
		if(r-i+1<=k-1)g[u]+=tmp[i];
	}
}
void solve()
{
	cnt=0;
	int u,v,c;
	readint(n);readint(k);
	enum(i,1,n)G[i].clear();
	enum(i,1,n-1)
	{
		readint(u);readint(v);readint(c);
		G[u].pb(mp(c,v));G[v].pb(mp(c,u));
	}
	dfs(1,-1);
//enum(i,1,n)cerr<<f[i]<<" ";cerr<<endl;
	printf("%lld\n",f[1]);
}
 
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
    return 0;
}