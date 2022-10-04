#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
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
const int MAXN=2005;

int n,root,c[MAXN],a[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];
int tow(int x)
{
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			--x;
			if(!x)return i;
		}
	return 0;
}
int size[MAXN];
void dfs(int u)
{
	a[u]=tow(c[u]+1);
	vis[a[u]]=1;
	size[u]=1;
	for(auto v:G[u])
	{
		dfs(v);
		size[u]+=size[v];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u;
	readint(n);
	for(int i=1;i<=n;++i)
	{
		readint(u),readint(c[i]);
		if(u)G[u].pb(i);
		else root=i;
	}
	dfs(root);
	for(int i=1;i<=n;++i)
		if(c[i]>=size[i])return 0*printf("NO\n");
	printf("YES\n");
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}