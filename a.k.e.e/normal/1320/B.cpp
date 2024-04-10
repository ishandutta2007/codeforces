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

int n,m,a[MAXN],dis[MAXN],to[MAXN],q[MAXN];
vector<int> G[MAXN];
void bfs(int src)
{
	memset(dis,0x3f,sizeof(dis));
	dis[src]=0;
	int front=1,rear=0;
	q[++rear]=src;
	while(front<=rear)
	{
		int u=q[front++];
		for(auto v:G[u])
			if(dis[v]>dis[u]+1)dis[v]=dis[u]+1,q[++rear]=v,to[v]=1;
			else if(dis[v]==dis[u]+1)++to[v];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v;
	readint(n),readint(E);
	while(E--)readint(u),readint(v),G[v].pb(u);
	readint(m);
	for(int i=1;i<=m;++i)readint(a[i]);
	bfs(a[m]);
	int Min=0,Max=0;
	for(int i=1;i<m;++i)
		if(dis[a[i]]<dis[a[i+1]]+1)++Min,++Max;
		else if(to[a[i]]>=2)++Max;
	printf("%d %d\n",Min,Max);
	return 0;
}