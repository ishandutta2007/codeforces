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
const int MAXN=100005;

int n,k1,k2,tmin,tmax,l[MAXN],r[MAXN],col[MAXN];
vector<int> G[MAXN];
void dfs(int u)
{
	if(col[u]==3)exit(0*printf("IMPOSSIBLE\n"));
	int t=col[u]^3;
	for(auto v:G[u])
	{
		if(t==col[v])continue;
		col[v]|=t;
		dfs(v);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v;
	k2=1<<30;
	readint(tmin),readint(tmax),readint(n),readint(E);
	for(int i=1;i<=n;++i)
	{
		readint(l[i]),readint(r[i]);
		chkmax(k1,l[i]);chkmin(k2,r[i]);
	}
	if(k1+k2<tmin)k1=tmin-k2;
	else if(k1+k2>tmax)k2=tmax-k1;
	if(k1<0 || k2<0)exit(0*printf("IMPOSSIBLE\n"));
	while(E--)
	{
		readint(u),readint(v);
		G[u].pb(v);G[v].pb(u);
	}
	for(int i=1;i<=n;++i)
	{
		if(k1<l[i] || k1>r[i])col[i]|=2;
		if(k2<l[i] || k2>r[i])col[i]|=1;
		if(col[i]==3)exit(0*printf("IMPOSSIBLE\n"));
		if(col[i])dfs(i);
	}
	for(int i=1;i<=n;++i)
		if(!col[i])
		{
			col[i]=1;
			dfs(i);
		}
	printf("POSSIBLE\n");
	printf("%d %d\n",k1,k2);
	for(int i=1;i<=n;++i)
		printf("%d",col[i]);
	return 0;
}