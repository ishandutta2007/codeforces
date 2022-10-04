#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005;

int n,m,size[MAXN],dep[MAXN],res[MAXN];
vector<int> G[MAXN];
void dfs(int u,int pa)
{
	size[u]=1;
	for(auto v:G[u])
		if(v!=pa)
		{
			dep[v]=dep[u]+1;
			dfs(v,u);
			size[u]+=size[v];
		}
	res[u]=dep[u]-size[u];
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n),readint(m);
	for(int i=1;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	dep[1]=1,dfs(1,-1);
	sort(res+1,res+n+1);
	ll ans=0;
	for(int i=n;i>n-m;--i)ans+=res[i];
	cout<<ans<<endl;
	return 0;
}