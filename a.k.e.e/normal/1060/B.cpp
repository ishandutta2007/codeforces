#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

using namespace std;

typedef long long ll;
const int MAXN=100005;

ll n;

ll s(ll x)
{
	ll ans=0;
	while(x)ans+=x%10,x/=10;
	return ans;
}

int main()
{
    cin>>n;
    ll a=9,ans=s(n);
    while(a<=n)
    	ans=max(ans,s(n-a)+s(a)),a=a*10+9;
    cout<<ans<<endl;
    return 0;
}