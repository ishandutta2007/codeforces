#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=2000005;

int n,deg[MAXN];
vector<int> G[MAXN];
char s[MAXN];
inline void addEdge(int u,int v){G[u].pb(v);G[v].pb(u);++deg[u];++deg[v];}
bool solve()
{
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=4*n;i++){G[i].clear();deg[i]=0;}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addEdge(u,v);
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='W')
		{
			addEdge(i,++n);
			addEdge(n,n+1);
			addEdge(n,n+2);
			n+=2;
		}
	
	if(n<=2)return 0;
	u=v=0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]>=4)return 1;
		if(deg[i]==3)
		{
			if(v)return 1;
			else if(u)v=i;
			else u=i;
		}
	}
	int cnt;
	if(u)
	{
		cnt=0;
		for(int i=0;i<G[u].size();i++)
			if(deg[G[u][i]]>=2)++cnt;
		if(cnt>=2)return 1;
	}
	if(v)
	{
		cnt=0;
		for(int i=0;i<G[v].size();i++)
			if(deg[G[v][i]]>=2)++cnt;
		if(cnt>=2)return 1;
	}
	if(!v)return 0;
	return n&1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    while(T--)printf(solve()?"White\n":"Draw\n");
    return 0;
}