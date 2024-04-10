#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
//#include <stdint.h>

using namespace std;

typedef long long ll;
const int MAXN=100005;
const ll INF=1ll<<60;

ll a;
ll calc(ll x)
{
	ll ans=0;
	for(ll i=0,ten=1,y=0;x;y=y+x%10*ten,x/=10,++i,ten*=10)
	{
		ans+=(x%10)*(ten/10)*i*45;if(ans>=INF)return INF;
		ans+=(x%10)*(y+1);if(ans>=INF)return INF;
		ans+=(x%10)*(x%10-1)/2*ten;if(ans>=INF)return INF;
	}
	return ans;
}
ll wawa(ll x)
{
	ll ans=0;
	while(x)ans+=x%10,x/=10;
	return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>a;
    ll L=1,R=13999999999999999ll,mid,ans=0;
    while(L<=R)
    {
    	mid=(L+R)>>1;
    	if(calc(mid)>=a)ans=mid,R=mid-1;
    	else L=mid+1;
    }
    R=ans;L=1;ans=calc(ans);
    while(1)
    {
    	if(ans==a)return 0*printf("%lld %lld\n",L,R);
    	else if(ans<a)ans+=wawa(++R);
    	else ans-=wawa(L++);
    }
    return 0;
}