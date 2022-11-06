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
const int N=200005,P=1e9+7;
int n,m,mx,ans,a[N],f[N],fac[N],ifac[N],iv[N];
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
int main()
{
	fac[0]=1;rep0(i,1,N)fac[i]=1ll*fac[i-1]*i%P;
	iv[1]=1;rep0(i,2,N)iv[i]=1ll*(P-P/i)*iv[P%i]%P;
	ifac[0]=1;rep0(i,1,N)ifac[i]=1ll*ifac[i-1]*iv[i]%P;
	n=rd();rep(i,1,n)a[i]=rd(),m+=a[i],mx=max(mx,a[i]);
	rep(i,1,mx)f[i]=(f[i-1]+pw(m+1-i,P-2))%P;
	rep(i,1,mx)f[i]=1ll*(m-1)*(m-i)%P*f[i]%P;
	rep(i,1,n)ans=(ans+f[a[i]])%P;
	printf("%d\n",ans);return 0;
}