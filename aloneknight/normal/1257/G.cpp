#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define db double
#define mp make_pair
#define X first
#define Y second
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<(a).size();++i)
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
#define gc getchar
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=600000,P=998244353,iv2=(P+1)/2;
int fac[N],ifac[N],iv[N];
inline int pls(int a,int b){a+=b;return a>=P?a-P:a;}
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
namespace poly
{
	int r[N];//,w[N];
	int *w[21];
	void init()
	{
		for(int i=2,t=0;i<N;i<<=1,t++)
		{
			w[t]=new int[i>>1];int wn=pw(3,(P-1)/i);
			w[t][0]=1;rep0(j,1,(i>>1))w[t][j]=1ll*w[t][j-1]*wn%P;
		}
	}
	inline void ntt(int n,int*a,int f)
	{
		int l=1;while((1<<l)<n)l++;
		rep0(i,1,n)r[i]=r[i>>1]>>1|(i&1)<<(l-1);
		rep0(i,0,n)if(i<r[i])swap(a[i],a[r[i]]);
			for(int i=2,t=0;i<=n;i<<=1,t++)
		{
			for(int j=0;j<n;j+=i)
			{
				int*x=a+j,*y=a+j+(i>>1);
				rep0(k,0,(i>>1)){int v=1ll*y[k]*w[t][k]%P;y[k]=pls(x[k],P-v);x[k]=pls(x[k],v);}
			}
		}
		if(f==-1)
		{
			reverse(a+1,a+n);int ivn=iv[n];
			rep0(i,0,n)a[i]=1ll*a[i]*ivn%P;
		}
	}
	inline void mul(int n,int*a,int*b)
	{
		if(n<=64)
		{
			static ull tmp[130];int m=n>>1;
			rep0(i,0,m)rep0(j,0,m)tmp[i+j]+=1ll*a[i]*b[j];
			rep0(i,0,n)a[i]=tmp[i]%P,tmp[i]=0;return;
		}
		ntt(n,a,1);ntt(n,b,1);
		rep0(i,0,n)a[i]=1ll*a[i]*b[i]%P;ntt(n,a,-1);
	}
}
using namespace poly;
int tA[N],tB[N];
inline void mul(int nn,int mm,int*A,int*B,int*C,int o=0)
{
	rep0(i,0,nn)tA[i]=A[i],tB[i]=B[i];
	memset(tA+nn,0,nn*4);memset(tB+nn,0,nn*4);ntt(mm,tA,1);ntt(mm,tB,1);
	rep0(i,0,mm)C[i]=1ll*tA[i]*tB[i]%P;ntt(mm,C,-1);if(!o)memset(C+nn,0,nn*4);
}
inline vi operator*(vi a,vi b)
{
	int na=a.size(),nb=b.size(),nc=na+nb-1;
	int nn=1;while(nn<nc)nn<<=1;a.resize(nn);b.resize(nn);
	ntt(nn,&a[0],1);ntt(nn,&b[0],1);
	rep0(i,0,nn)a[i]=1ll*a[i]*b[i]%P;
	ntt(nn,&a[0],-1);a.resize(nc);return a;
}
int n,tt,c[3000005];vi g[N];
vi sol(int l,int r){if(l==r)return g[l];int m=l+r>>1;return sol(l,m)*sol(m+1,r);}
inline int C(int a,int b){return 1ll*fac[a]*ifac[b]%P*ifac[a-b]%P;}
int main()
{
	fac[0]=1;rep0(i,1,N)fac[i]=1ll*fac[i-1]*i%P;
	iv[1]=1;rep0(i,2,N)iv[i]=1ll*(P-P/i)*iv[P%i]%P;
	ifac[0]=1;rep0(i,1,N)ifac[i]=1ll*ifac[i-1]*iv[i]%P;
	init();n=rd();rep(i,1,n)c[rd()]++;
	rep(i,1,3000000)if(c[i])
	{
		g[++tt].resize(c[i]+1);
		rep(j,0,c[i])g[tt][j]=1;//C(c[i],j);
	}
	vi G=sol(1,tt);
//	fore(i,G)cout<<G[i]<<" ";
	n/=2;printf("%d\n",G[n]);return 0;
}