#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Maxn=1e6+10;
struct node{LL x,t,c;node(){}node(LL _t,LL _x,LL _c){t=_t; x=_x; c=_c;}}Q1[Maxn],Q2[Maxn]; LL Q1len,Q2len;
bool Cmp1(const node &x,const node &y){return x.t<y.t;}
bool Cmp2(const node &x,const node &y){return x.t>y.t;}

LL cnt[Maxn],cost[Maxn]; LL F[Maxn],G[Maxn];

LL N,M,K;
int main()
{
  scanf("%lld%lld%lld",&N,&M,&K); Q1len=Q2len=0;
  for(LL i=1;i<=M;i++)
  {
	LL t,x,y,c; scanf("%lld%lld%lld%lld",&t,&x,&y,&c);
	if(y==0) Q1[++Q1len]=node(t,x,c);
	if(x==0) Q2[++Q2len]=node(t,y,c);
  }
  sort(Q1+1,Q1+Q1len+1,Cmp1);
  sort(Q2+1,Q2+Q2len+1,Cmp2);
  
  memset(cost,126,sizeof(cost));
  memset(F,126,sizeof(F));
  
  LL now=1; LL num=0; LL s=0;
  for(LL i=1;i<=(LL)(1e6);i++)
  {
	while(now<=Q1len && Q1[now].t==i)
	{
	  if(cost[Q1[now].x]>99999999)
	  {
		cost[Q1[now].x]=Q1[now].c;
		s+=Q1[now].c; num++;
	  }
	  else if(cost[Q1[now].x]>Q1[now].c)
	  {
		s-=cost[Q1[now].x]; s+=Q1[now].c;
		cost[Q1[now].x]=Q1[now].c;
	  }
	  now++;
	}
	if(num==N) F[i]=s;
  }
  
  memset(cost,126,sizeof(cost));
  memset(G,126,sizeof(G));
  
  now=1; num=0; s=0;
  for(LL i=(LL)(1e6);i>=1;i--)
  {
	while(now<=Q2len && Q2[now].t==i)
	{
	  if(cost[Q2[now].x]>99999999)
	  {
		cost[Q2[now].x]=Q2[now].c;
		s+=Q2[now].c; num++;
	  }
	  else if(cost[Q2[now].x]>Q2[now].c)
	  {
		s-=cost[Q2[now].x]; s+=Q2[now].c;
		cost[Q2[now].x]=Q2[now].c;
	  }
	  now++;
	}
	if(num==N) G[i]=s;
  }
  
  for(LL i=1;i<=(LL)(1e6);i++) F[i]=min(F[i],F[i-1]);
  for(LL i=(LL)(1e6);i>=1;i--) G[i]=min(G[i],G[i+1]);
  
  LL minx=LLONG_MAX; for(LL i=1;i<=(LL)(1e6)-K-1;i++) if(F[i]<(1LL<<40) && G[i+K+1]<(1LL<<40)) minx=min(minx,F[i]+G[i+K+1]);
  
  if(minx==LLONG_MAX) printf("-1\n");
  else printf("%lld\n",minx);
  return 0;
}