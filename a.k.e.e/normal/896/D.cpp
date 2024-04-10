#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,l,r,pn;
ll mod,p[25],phi,alp[25];
ll qmi(ll x,ll y)
{
	ll ans=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)ans=ans*x%mod;
	return ans;
}
struct Int
{
	ll c[25],a;
	Int(){}
	Int(ll x)
	{
		memset(c,0,sizeof(c));
		for(int i=1;i<=pn;i++)
			while(!(x%p[i]))++c[i],x/=p[i];
		a=x%mod;
	}
	Int operator *(Int b)
	{
		Int res;
		for(int i=1;i<=pn;i++)
			res.c[i]=c[i]+b.c[i];
		res.a=a*b.a%mod;
		return res;
	}
	Int operator /(Int b)const
	{
		Int res;
		for(int i=1;i<=pn;i++)
			res.c[i]=c[i]-b.c[i];
		res.a=a*qmi(b.a,phi-1)%mod;
		return res;
	}
	ll value()const
	{
		ll res=a;
		for(int i=1;i<=pn;i++)
			res=res*qmi(p[i],c[i])%mod;
		return res;
	}
};

Int fac[MAXN];
ll calc(int l)
{
	ll res=0;
	for(int i=l;i*2<=n+l;i++)
		res=(res+(fac[n]/(fac[i]*fac[i-l]*fac[n+l-2*i])).value())%mod;
	return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>mod>>l>>r;
    ll t=mod;phi=1;
    for(ll i=2;i*i<=t;i++)
    	if(!(t%i))
    	{
    		p[++pn]=i;
    		while(!(t%i))++alp[pn],t/=i;
    		phi*=(i-1);
    		for(int j=2;j<=alp[pn];j++)phi*=i;
    	}
    if(t>1){p[++pn]=t;alp[pn]=1;phi*=t-1;}
/*for(int i=1;i<=pn;i++)
	cerr<<p[i]<<"^"<<alp[i]<<endl;
cerr<<phi<<endl;*/
    fac[0]=Int(1);
    for(int i=1;i<=n+2;i++)
    	fac[i]=fac[i-1]*Int(i);
    if(r>l)cout<<(calc(l)+calc(l+1)-calc(r+1)-calc(r+2)+2*mod)%mod<<endl;
    else cout<<(calc(l)-calc(l+2)+mod)%mod<<endl;
    return 0;
}