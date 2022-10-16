#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
ll c[1111];
int V;
int ref[1111],stk[1111];
struct matrix
{
	ll Mt[72][72];
	void reset(){memset(Mt,0x3f,sizeof Mt);}
};
matrix operator*(matrix x,matrix y)
{
	matrix ret;
	register int i,ii,iii;
	for(i=1;i<=V;i++)
		for(ii=1;ii<=V;ii++)
			ret.Mt[i][ii]=1e18;
	for(i=1;i<=V;i++)
		for(iii=1;iii<=V;iii++)
			for(ii=1;ii<=V;ii++)
			{
				ll T=x.Mt[i][iii]+y.Mt[iii][ii];
				if(ret.Mt[i][ii]>T)ret.Mt[i][ii]=T;
			}
	return ret;
}
int popcnt[11111];
int trans(int x,int d)
{
	if(x&(1<<d))return -1;
	return(x|(1<<d))>>1;
}
int x,k,n,q;
matrix gen(ll*cs)
{
	register int i,ii;
	matrix ret;
	ret.reset();
	for(i=1;i<=V;i++)
	{
		int G=stk[i];
		if((G&1)==0){ret.Mt[i][ref[G>>1]]=0;continue;}
		for(ii=1;ii<=k;ii++)
		{
			int t=trans(G,ii);
			if(~t)ret.Mt[i][ref[t]]=cs[ii];
		}
	}return ret;
}
#include<map>
std::map<int,int>Ext;
std::map<int,matrix>Exp;
ll tmp[1111];
void ins(int p,int w)
{
	Ext[p]=w;
	register int i,ii;
	for(i=p-1;i&&i>=p-k;i--)
	{
		if(i>n-x)continue;
		for(ii=1;ii<=k;ii++)tmp[ii]=Ext[ii+i]+c[ii];
		Exp[i]=gen(tmp);
	}
}
matrix qpow(matrix g,int p)
{matrix r=g;for(p--;p;p>>=1,g=g*g)if(p&1)r=r*g;return r;}
void solve()
{
	matrix A,R=gen(c);
	A.reset(),A.Mt[1][1]=0;
	int P=1;
	for(auto i:Exp)
	{
		if(P^i.first)A=A*qpow(R,i.first-P);
		A=A*i.second,P=i.first+1;
	}if(P^(n-x+1))A=A*qpow(R,n-x+1-P);
	printf("%lld\n",A.Mt[1][1]);
}
int main()
{
	scanf("%d%d%d%d",&x,&k,&n,&q);
	register int i;
	for(i=1;i<=k;i++)scanf("%lld",c+i);
	for(i=1;i<(1<<k);i++)popcnt[i]=popcnt[i>>1]+(i&1);
	for(i=1;i<(1<<k);i++)if(popcnt[i]==x)stk[++V]=i,ref[i]=V;
	int p,w;
	for(i=1;i<=q;i++)scanf("%d%d",&p,&w),ins(p,w);
	solve();
}
/*
Just go for it.
*/