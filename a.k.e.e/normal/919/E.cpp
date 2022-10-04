#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300013,INF=1<<30;

ll a,b,p,x;

ll qmi(ll a,ll k,ll mod)
{
	if(!k)return 1;
	if(k==1)return a;
	ll t=qmi(a,k>>1,mod);
	if(k&1)return t*t%mod*a%mod;
	return t*t%mod;
}

void extend_gcd(ll a,ll b,ll &x,ll &y)
{
    if(!b){x=1;y=0;return;}
    extend_gcd(b,a%b,x,y);
    ll t=x;x=y;y=t-a/b*y;
}

int main()
{
	#ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>a>>b>>p>>x;
    ll t,cx,cy,m,ans=0;
    for(int i=0;i<p-1;i++)
    {
    	t=qmi(a,i,p);
    	extend_gcd(t,p,cx,cy);
    	cx=((cx+p)%p)*b%p;
    	m=i*p-cx*p+cx;
    	while(m<=0)m+=p*(p-1);
    	if(m<=x)ans+=(x-m)/(p*(p-1))+1;
    }
    cout<<ans<<endl;
    return 0;
}