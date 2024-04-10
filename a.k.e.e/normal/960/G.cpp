#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

typedef long long ll;
typedef vector<ll> Poly;
const int MAXN=300005,MOD=998244353,INV3=(MOD+1)/3;

int n,x,y;
int N,rev[MAXN];
ll fac[MAXN];
ll qmi(ll x,ll y)
{
	ll ans=1;
	for(;y;y>>=1,x=x*x%MOD)
		if(y&1)ans=ans*x%MOD;
	return ans;
}
void ntt(Poly &a,int g)
{
	int N=a.size();
	for(int i=0;i<N;i++)if(i>rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<N;i<<=1)
		for(int j=0,wn=qmi(g,(MOD-1)/(i<<1));j<N;j+=(i<<1))
			for(int k=j,w=1;k<i+j;k++)
			{
				ll t=a[i+k]*w%MOD;
				a[i+k]=a[k]-t;if(a[i+k]<0)a[i+k]+=MOD;
				a[k]+=t;if(a[k]>=MOD)a[k]-=MOD;
				w=(ll)w*wn%MOD;
			}
}
Poly operator *(Poly a,Poly b)
{
	int N;
	for(N=1;N<a.size()+b.size()-1;N<<=1);
    for(int i=1;i<N;i++)
    	if(i&1)rev[i]=(rev[i>>1]>>1)^(N>>1);
    	else rev[i]=(rev[i>>1]>>1);
	for(int i=a.size();i<N;i++)a.push_back(0);
	for(int i=b.size();i<N;i++)b.push_back(0);
	a.resize(N);b.resize(N);
	ntt(a,3);ntt(b,3);
	for(int i=0;i<N;i++)a[i]=(a[i]*b[i])%MOD;
	ntt(a,INV3);
	ll invN=qmi(N,MOD-2);
	for(int i=0;i<N;i++)a[i]=a[i]*invN%MOD;
	return a;
}
Poly solve(int l,int r)
{
	if(l==r)
	{
		Poly a;
		a.push_back(l);
		a.push_back(1);
		return a;
	}
	int mid=(l+r)>>1;
	return solve(l,mid)*solve(mid+1,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>x>>y;--x;--y;
    if(x+y>=n || x<0 || y<0)return 0*printf("0\n");
	--n;
    fac[0]=1;
    for(int i=1;i<=x+y;i++)fac[i]=fac[i-1]*i%MOD;
    if(n)printf("%lld\n",solve(0,n-1)[x+y]*fac[x+y]%MOD*qmi(fac[x]*fac[y]%MOD,MOD-2)%MOD);
    else printf("1\n");
    return 0;
}