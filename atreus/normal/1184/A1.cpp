// High above the clouds there is a rainbow...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

void solve(ll n,ll x){
    n/=x;
    n--;
    n-=x;
    if(n>0 && (n&1)==0)
	cout<<x<<" "<<(n/2)<<endl, exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    ll n; cin>>n; --n;

    if(n==0) return cout<<"NO\n",0;
    
    vector<ll> v;
    for(ll i=1;i*i<=n;i++){
	if(n%i==0) solve(n,i), v.PB(i);
    }
    for(int i=sz(v)-1;i>=0;i--){
	solve(n, n/v[i]);
    }
    return cout<<"NO\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")