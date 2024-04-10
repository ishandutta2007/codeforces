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
const int MAXN=500005;

int n,b[MAXN];
vector<int> G[MAXN],a[MAXN];
int vis[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v,x;
	readint(n),readint(E);
	while(E--)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	for(int i=1;i<=n;++i)readint(b[i]),a[b[i]].pb(i);
	for(int i=1;i<=n;++i)
		for(auto j:a[i])
		{
			for(auto k:G[j])
			{
				if(b[j]==b[k])return 0*printf("-1\n");
				vis[b[k]]=j;
			}
			for(int k=1;k<i;++k)
				if(vis[k]!=j)return 0*printf("-1\n");
		}
	for(int i=1;i<=n;++i)
		for(int j:a[i])
			printf("%d ",j);
	return 0;
}