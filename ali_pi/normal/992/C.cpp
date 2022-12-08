#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=2e5+1000;
const ll mod=1e9+7;
const ll inf=1e9+500;
int di;
ll poww(ll a,ll b){
    ll ans=1;
    di++;
    while(b){
        if(b&1){
            di++;
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        di++;
        b=(b/2);
    }
    return ans;
}
int main(){
    ll x,k;
    di++;
    cin>>x>>k;
    if(x==0){
        di++;
        cout<<0;
        return 0;
    }
    x%=mod;
    di++;
    ll v=(x*poww(2,k+1))%mod;
    di++;
    ll u=(poww(2,k)+mod-1)%mod;
    cout<<(v-u+mod)%mod;
    return 0;

}