#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
cpnst int blk=320;
#define Ls(x) (1+((x)-1)*blk)
#define Rs(x) ((x)*blk)
#define bel(x) (((x)-1)/blk+1)
typedef unsigned long long ull;
bool val[111111];
int n,t[1111111];
namespace blt
{
	cpnst ull bas=123415421;
	ull k[1111111];
	void init()
	{
		register int i;
		for(i=k[0]=1;i<=1e6;i++)k[i]=k[i-1]*bas;
	}
	ull preh[1111][1111],sufh[1111][1111];
	int lf[1111][1111],lt[1111],rf[1111][1111],rt[1111];
	void calc(ull*f,int*k,int sz)
	{for(register int i=1;i<=sz;i++)f[i]=f[i-1]*bas+k[i];}
	void block(int x)
	{
		register int i;
		lt[x]=rt[x]=0;
		for(i=Ls(x);i<=Rs(x);i++)
		{
			if(t[i]>0)rf[x][++rt[x]]=t[i];
			else
			{
				if(rt[x])
				{
					if(rf[x][rt[x]]!=-t[i]){val[x]=0;return;}
					rt[x]--;
				}else lf[x][++lt[x]]=-t[i];
			}
		}for(i=1;i<lt[x]+1-i;i++)
		{int tp=lf[x][i];lf[x][i]=lf[x][lt[x]+1-i],lf[x][lt[x]+1-i]=tp;}
		calc(preh[x],lf[x],lt[x]),calc(sufh[x],rf[x],rt[x]);
		val[x]=1;
	}
	struct rng
	{
		int f,l,r,e;
	}rlk[111111];
	int rtp;
	ull gethash(ull*h,int l,int r)
	{return h[r]-h[l-1]*k[r-l+1];}
	int gtop()
	{
		if(rlk[rtp].e)return rlk[rtp].e;
		else return rf[rlk[rtp].f][rlk[rtp].r];
	}
	int tpsize()
	{return(rlk[rtp].e)?1:(rlk[rtp].r-rlk[rtp].l+1);}
	void ptop()
	{
		if(rlk[rtp].e)rtp--;
		else
		{
			rlk[rtp].r--;
			if(rlk[rtp].r<rlk[rtp].l)rtp--;
		}
	}
	bool push(int op)
	{
		if(op<0)
		{
			if(!rtp)return 0;
			int v=gtop();
			if(v!=-op)return 0;
			ptop();
		}else rlk[++rtp]=(rng){0,0,0,op};
		return 1;
	}
	bool pushb(int x)
	{
		if(lt[x])
			for(register int i=lt[x];i;)
			{
				if(!rtp)return 0;
				if(tpsize()>i)
				{
					if(gethash(sufh[rlk[rtp].f],rlk[rtp].r-i+1,rlk[rtp].r)!=
					gethash(preh[x],1,i))return 0;
					rlk[rtp].r-=i;
					break;
				}else if(!rlk[rtp].e)
				{
					if(gethash(sufh[rlk[rtp].f],rlk[rtp].l,rlk[rtp].r)!=
					gethash(preh[x],i-tpsize()+1,i))return 0;
				}else if(gethash(preh[x],i-tpsize()+1,i)!=rlk[rtp].e)
					return 0;
				i-=tpsize(),rtp--;
			}
		if(rt[x])rlk[++rtp]=(rng){x,1,rt[x],0};
		return 1;
	}
	bool solve(int l,int r)
	{
		register int i;
		rtp=0;
		for(i=l;i<=Rs(bel(l));i++)if(!push(t[i]))return 0;
		for(i=bel(l)+1;i<bel(r);i++)
		{
			if(!val[i])return 0;
			if(!pushb(i))return 0;
		}for(i=Ls(bel(r));i<=r;i++)if(!push(t[i]))return 0;
		return!rtp;
	}
}
namespace brute
{
	int stk[111111],top;
	bool run(int l,int r)
	{
		register int i;
		top=0;
		for(i=l;i<=r;i++)
		{
			if(t[i]<0){if(stk[top]!=(-t[i]))return 0;top--;}
			else stk[++top]=t[i];
		}return!top;
	}
}
using blt::solve;
using blt::block;
using brute::run;
int main()
{
	blt::init();
	int n,m,k;
	scanf("%d%d",&n,&k);
	register int i;
	for(i=1;i<=n;i++)scanf("%d",t+i);
	for(i=1;i<=bel(n);i++)block(i);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(o&1)t[x]=y,block(bel(x));
		else puts(((bel(x)^bel(y))?solve(x,y):run(x,y))?"Yes":"No");
	}
}
/*
Just go for it.
*/