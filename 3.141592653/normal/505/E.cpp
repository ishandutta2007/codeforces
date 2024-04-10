#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
int N,M,K,P;
ll a[111111],h[111111];
#include<queue>
struct pii
{ll x;int d,p;};
bool operator<(cpnst pii x,cpnst pii y)
{return(x.x/x.d)>(y.x/y.d);}
std::priority_queue<pii>q;
pii stk[111111];
bool valid(ll mid)
{
	while(q.size())q.pop();
	register int i,ii;
	for(i=1;i<=N;i++)
		if(a[i]>mid)return 0;
	ll eva=0,top=0;
	for(i=1;i<=N;i++)
	{
		pii g=pii{mid,(int)a[i],i};
		(g.x/g.d<M)?q.push(g):(void)(stk[++top]=g);
	}for(i=M;i;i--)
	{
		for(ii=K;ii;ii--)
			if(q.size())
			{
				pii g=q.top();q.pop();
				if(g.x/g.d<M-i+1)return 0;
				if(g.x/g.d<M)
				{g.x+=P,(g.x/g.d<M)?q.push(g):(void)(stk[++top]=g);}
				else stk[++top]=g,eva++;
			}else eva++;
	}for(;q.size();)
	{
		pii g=q.top();q.pop();
		if(g.x/g.d<M)return 0;
		else stk[++top]=g;
	}for(i=1;i<=N;i++)
	{
		ll rem=h[stk[i].p]-(stk[i].x-M*1ll*stk[i].d);
		if(rem>0)eva-=(rem-1)/P+1;
	}return eva>=0;
}
int main()
{
	scanf("%d%d%d%d",&N,&M,&K,&P);
	register int i;
	for(i=1;i<=N;i++)
		scanf("%lld%lld",h+i,a+i);
	ll L=0,R=1e13;
	while(L+1<R)
	{ll m=(L+R)>>1;(valid(m)?R:L)=m;}
	printf("%lld\n",R);
}
/*
Just go for it.
*/