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

int n,m;
int a[MAXN];
vector<int> G[MAXN];
int dis1[MAXN],dis2[MAXN];
int q[MAXN];
void bfs(int src,int *dis)
{
	int front=1,rear=0;
	for(int i=1;i<=n;++i)dis[i]=1<<30;
	dis[src]=0;
	q[++rear]=src;
	while(front<=rear)
	{
		int u=q[front++];
		for(auto v:G[u])
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q[++rear]=v;
			}
	}
}

pii pr[MAXN];
int suf[MAXN],sec[MAXN];
bool check(int mid)
{
	for(int i=1;i<=m;++i)
	{
		int t=lower_bound(pr+1,pr+m+1,mp(mid-pr[i].y+1,0))-pr,uu=suf[t];
		if(i>=t && suf[t]==pr[i].y)uu=sec[t];
		if(pr[i].x+uu>=mid)return 1;
	}
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v;
	readint(n),readint(E),readint(m);
	for(int i=1;i<=m;++i)readint(a[i]);
	while(E--)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	bfs(1,dis1);
	bfs(n,dis2);
	for(int i=1;i<=m;++i)pr[i]=mp(dis1[a[i]],dis2[a[i]]);
	sort(pr+1,pr+m+1);
	suf[m+1]=sec[m+1]=-1<<30;
	for(int i=m;i;--i)
	{
		suf[i]=max(suf[i+1],pr[i].y);
		if(suf[i]==suf[i+1])sec[i]=max(pr[i].y,sec[i+1]);
		else sec[i]=max(suf[i+1],sec[i+1]);
	}
	int L=1,R=dis1[n],mid,ans=0;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid-1))L=mid+1,ans=mid;
		else R=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}