#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
struct seg
{
	int mn,sm,d;
}tr[1111111];
void push(int p,int d)
{tr[p].mn+=d,tr[p].d+=d;}
void pushd(int p)
{push(p<<1,tr[p].d),push(p<<1|1,tr[p].d),tr[p].d=0;}
int min(int x,int y)
{return(x<y)?x:y;}
void pushu(int p)
{
	tr[p].mn=min(tr[p<<1].mn,tr[p<<1|1].mn),tr[p].sm=0;
	if(tr[p].mn==tr[p<<1].mn)tr[p].sm=tr[p<<1].sm;
	if(tr[p].mn==tr[p<<1|1].mn)tr[p].sm+=tr[p<<1|1].sm;
}
int n,p[1111111];
void modify(int l,int r,int d,int p=1,int pl=1,int pr=n)
{
	if(l>pr||pl>r)return;
	if(pl>=l&&pr<=r){return push(p,d);}
	int mid=(pl+pr)>>1;
	pushd(p),modify(l,r,d,p<<1,pl,mid),modify(l,r,d,p<<1|1,mid+1,pr),pushu(p);
}
void pre(int p=1,int pl=1,int pr=n)
{tr[p].sm=pr-pl+1;if(pl^pr){int mid=(pl+pr)>>1;pre(p<<1,pl,mid),pre(p<<1|1,mid+1,pr);}}
typedef long long ll;
int Ip[1111111],It[1111111],Is;
int Dp[1111111],Dt[1111111],Ds;
void ins(int x,int t)
{
	while(Is&&x>Ip[Is])modify(It[Is-1]+1,It[Is],x-Ip[Is]),Is--;
	Ip[++Is]=x,It[Is]=t;
	while(Ds&&x<Dp[Ds])modify(Dt[Ds-1]+1,Dt[Ds],Dp[Ds]-x),Ds--;
	Dp[++Ds]=x,Dt[Ds]=t;
	modify(1,t,-1);
}
int main()
{
	ll ans=0;
	register int i;
	scanf("%d",&n),pre();
	for(i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),p[x]=y;
	}for(i=1;i<=n;i++)
		ins(p[i],i),ans+=tr[1].sm;
	printf("%lld\n",ans);
}
/*
Just go for it.
*/