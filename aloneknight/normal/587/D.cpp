#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=500005;
int n,m,tt,cc,tp,nn,cnt,qn,hd[N],dfn[N],low[N],bel[N],stk[N],q[N];vi g[N];
struct st{int a,b,c,t;}p[N];
struct E{int v,nxt;}e[N*4];
inline void add(int u,int v){e[++cc]=(E){v,hd[u]};hd[u]=cc;}
inline bool cmp(int x,int y){return p[x].c<p[y].c;}
inline int A(int x){return x*2-1;}
inline int B(int x){return x*2;}
inline void calc1()
{
	rep(i,1,qn)
	{
		add(A(q[i]),tt+A(i));add(tt+B(i),B(q[i]));
		if(i==1)continue;
		add(tt+A(i-1),tt+A(i));add(tt+B(i),tt+B(i-1));
		add(tt+A(i-1),B(q[i]));add(A(q[i]),tt+B(i-1));
	}
	tt+=qn*2;qn=0; 
}
inline void calc2()
{
	rep(i,1,qn)
	{
		add(B(q[i]),tt+B(i));add(tt+A(i),A(q[i]));
		if(i==1)continue;
		add(tt+B(i-1),tt+B(i));add(tt+A(i),tt+A(i-1));
		add(tt+B(i-1),A(q[i]));add(B(q[i]),tt+A(i-1));
	}
	tt+=qn*2;qn=0; 
}
void tarjan(int x)
{
	dfn[x]=low[x]=++nn;stk[++tp]=x;
	for(int i=hd[x];i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(!dfn[y])tarjan(y),low[x]=min(low[x],low[y]);
		else if(!bel[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		cnt++;int y;
		do{y=stk[tp--];bel[y]=cnt;}while(y!=x);
	}
}
inline bool chk(int mid)
{
	tt=m*2;cc=0;memset(hd,0,sizeof(hd));
	rep(i,1,m)if(p[i].t>mid)add(B(i),A(i));
	rep(i,1,n)
	{
		for(int t:g[i])
		{
			if(qn&&p[t].c!=p[q[qn]].c)calc1();
			q[++qn]=t;
		}
		calc1();for(int t:g[i])q[++qn]=t;calc2();
	}
	rep(i,1,tt)dfn[i]=0,bel[i]=0;
	nn=0;cnt=0;rep(i,1,tt)if(!dfn[i])tarjan(i);
	for(int i=1;i<=tt;i+=2)if(bel[i]==bel[i+1])return 0;
	return 1;
}
int main()
{
	n=rd(),m=rd();int l=0,r=0,mid,ff=0;
	rep(i,1,m)p[i]=(st){rd(),rd(),rd(),rd()},r=max(r,p[i].t+1);
	rep(i,1,m)g[p[i].a].pb(i),g[p[i].b].pb(i);
	rep(i,1,n)sort(g[i].begin(),g[i].end(),cmp);
	while(l<r)if(chk(mid=l+r>>1))r=mid,ff=1;else l=mid+1;
	if(!ff){puts("No");return 0;}
	chk(r);tt=0;
	rep(i,1,m)if(bel[2*i-1]>bel[2*i])q[++tt]=i;
	printf("Yes\n%d %d\n",r,tt);
	rep(i,1,tt)printf("%d ",q[i]);return 0;
}