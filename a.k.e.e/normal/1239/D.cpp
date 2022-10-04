#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
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
const int MAXN=1000005;

int n;
vector<int> G[MAXN];
int dfn[MAXN],low[MAXN],cnt,sccno[MAXN],scccnt;
stack<int> s;
void dfs(int u)
{
	dfn[u]=low[u]=++cnt;
	s.push(u);
	for(auto v:G[u])
		if(!dfn[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!sccno[v])
			low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u])
	{
		scccnt++;
		while(true)
		{
			u=s.top();
			s.pop();
			sccno[u]=scccnt;
			if(dfn[u]==low[u])break;
		}
	}
}
bool vis[MAXN];
void solve()
{
	int E,u,v;
	readint(n);readint(E);
	scccnt=cnt=0;
	enum(i,1,n)
	{
		G[i].clear();
		dfn[i]=low[i]=sccno[i]=vis[i]=0;
	}
	while(!s.empty())s.pop();
	while(E--)
	{
		readint(u);readint(v);
		if(u!=v)G[u].pb(v);
	}
	enum(i,1,n)
		if(!dfn[i])dfs(i);
	if(scccnt==1){printf("No\n");return;}
	printf("Yes\n");
	enum(i,1,n)
		for(auto v:G[i])
			if(sccno[v]!=sccno[i])
				vis[sccno[i]]=1;
	enum(i,1,scccnt)
		if(!vis[i])
		{
			int res=0;
			enum(j,1,n)if(sccno[j]==i)++res;
			printf("%d %d\n",res,n-res);
			enum(j,1,n)if(sccno[j]==i)printf("%d ",j);printf("\n");
			enum(j,1,n)if(sccno[j]!=i)printf("%d ",j);printf("\n");
			break;
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	int T;readint(T);
	while(T--)solve();
    return 0;
}