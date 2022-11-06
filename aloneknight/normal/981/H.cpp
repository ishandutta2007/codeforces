#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define db long double
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
const int N=262150,P=998244353,iv2=(P+1)/2;
int n,K,r1,r2,ans,sz[N],f[N],fs[N],fac[N],ifac[N],r[N],w[N];vi G[N];vector<pii>V[N];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline void ntt(int n,int*a,int f)
{
	int l=0;while((1<<l)<n)l++;
	rep0(i,1,n)r[i]=r[i>>1]>>1|(i&1)<<(l-1);
	rep0(i,0,n)if(i<r[i])swap(a[i],a[r[i]]);
	for(int i=2;i<=n;i<<=1)
	{
		int wn=pw(3,f==1?(P-1)/i:P-1-(P-1)/i);
		w[0]=1;rep0(j,1,(i>>1))w[j]=1ll*w[j-1]*wn%P;
		for(int j=0;j<n;j+=i)
		{
			int*x=a+j,*y=a+j+(i>>1);
			rep0(k,0,(i>>1)){int v=1ll*y[k]*w[k]%P;y[k]=(x[k]+P-v)%P;x[k]=(x[k]+v)%P;}
		}
	}
	if(f==-1){int ivn=pw(n,P-2);rep0(i,0,n)a[i]=1ll*a[i]*ivn%P;}
}
int f1[N],f2[N],g1[N],g2[N],A[N],B[N];vi v1[N],v2[N];
void sol(int l,int r,int x)
{
	if(l==r)
	{
		int y=V[x][l].X;
		v1[l].resize(2);v1[l][0]=1;v1[l][1]=V[x][l].Y;
		v2[l].resize(2);v2[l][0]=(f[y]+fs[y])%P;
		v2[l][1]=1ll*(n-sz[x])*(f[y]+fs[y])%P;return;
	}
	int m=l+r>>1;sol(l,m,x);sol(m+1,r,x);m++;
	int n=r-l+2,nn=1;while(nn<n)nn<<=1;
	rep0(i,0,nn)f1[i]=f2[i]=g1[i]=g2[i]=0;
	fore(i,v1[l])f1[i]=v1[l][i],g1[i]=v2[l][i];
	fore(i,v1[m])f2[i]=v1[m][i],g2[i]=v2[m][i];
	ntt(nn,f1,1);ntt(nn,f2,1);ntt(nn,g1,1);ntt(nn,g2,1);
	rep0(i,0,nn)A[i]=1ll*f1[i]*f2[i]%P,B[i]=(1ll*f1[i]*g2[i]+1ll*g1[i]*f2[i])%P;
	ntt(nn,A,-1);ntt(nn,B,-1);v1[l].resize(n);v2[l].resize(n);
	rep0(i,0,n)v1[l][i]=A[i],v2[l][i]=B[i];
}
void dfs(int x,int p)
{
	sz[x]=1;
	for(int y:G[x])if(y!=p)
	{
		dfs(y,x);sz[x]+=sz[y];V[x].pb(mp(y,sz[y]));
		fs[x]=(1ll*fs[x]+fs[y]+f[y])%P;
	}
	if(!V[x].size())V[x].pb(mp(0,0));sol(0,V[x].size()-1,x);
	int k=min(K,(int)v1[0].size()-1);
	rep(i,0,k)f[x]=(f[x]+1ll*v1[0][i]*fac[K]%P*ifac[K-i])%P;
	r1=(r1+f[x])%P;r2=(r2+1ll*f[x]*f[x])%P;
	ans=(ans+P-1ll*f[x]*fs[x]%P)%P;
	rep(i,0,k)ans=(ans+1ll*v2[0][i]*fac[K]%P*ifac[K-i])%P;
} 
int main()
{
	n=rd();K=rd();fac[0]=1;rep(i,1,K)fac[i]=1ll*fac[i-1]*i%P;
	ifac[K]=pw(fac[K],P-2);per(i,K,1)ifac[i-1]=1ll*ifac[i]*i%P;
	if(K==1){printf("%d\n",1ll*n*(n-1)/2%P);return 0;}
	rep(i,1,n-1){int u=rd(),v=rd();G[u].pb(v);G[v].pb(u);} 
	dfs(1,1);printf("%d\n",(ans+1ll*(1ll*r1*r1%P+P-r2)*iv2%P)%P);return 0;
}