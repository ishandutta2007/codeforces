#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
cpnst int blk=320;
cpnst ll mod=119<<23|1;
ll f[444][444],ads[444];
ll dp[111111];
int t[111111];
int ls[111111],lss[111111],n,k;
#define bel(x) (((x)-1)/blk+1)
#define Lf(x) (((x)-1)*blk+1)
#define Rf(x) ((x)*blk)
ll nw=0;
void lift(int x,int det)
{ads[x]+=det;for(register int i=Lf(x);i<=Rf(x);i++)t[i]-=det;}
void block(int x)
{
	int Mn=1e9;
	register int i;
	for(i=Lf(x);i<=Rf(x);i++)if(t[i]<Mn)Mn=t[i];
	if(Mn)lift(x,Mn);
	for(i=0;i<=blk;i++)f[x][i]=0;
	for(i=Lf(x);i<=Rf(x);i++)f[x][t[i]]+=dp[i-1];
	for(i=1;i<=blk;i++)(f[x][i]+=f[x][i-1])%=mod;
}
void brute(int l,int r,int d)
{for(register int i=l;i<=r;i++)t[i]+=d;}
ll qr(ll x)
{return(k<ads[x])?0:(k-ads[x]>blk)?f[x][blk]:f[x][k-ads[x]];}
void modify(int l,int r,int d)
{
	int X=bel(l),Y=bel(r);
	if(X==Y)nw-=qr(X),brute(l,r,d),block(X),nw+=qr(X);
	else
	{
		register int i;
		for(i=X+1;i<Y;i++)nw-=qr(i),ads[i]+=d,nw+=qr(i);
		nw-=qr(X),nw-=qr(Y),brute(l,Rf(X),d),brute(Lf(Y),r,d),
		block(X),block(Y),nw+=qr(X),nw+=qr(Y);
	}nw=(nw%mod+mod)%mod;
}
int main()
{
	scanf("%d%d",&n,&k);
	register int i;
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x),modify(ls[x]+1,i,1);
		if(ls[x])modify(lss[x]+1,ls[x],-1);
		lss[x]=ls[x],ls[x]=i,dp[i]=nw,
		nw-=qr(bel(i)),block(bel(i)),nw+=qr(bel(i));
	}printf("%lld\n",dp[n]);
}
/*
Just go for it.
*/