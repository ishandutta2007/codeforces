#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll fac[N];
ll fm[N];
ll mod=998244353;
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll ent(ll k,ll n){
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
int Main(){
    string s;
    ll n;
    cin >> n;
    cin >> s;
    ll t0=0,t1=0,t11=0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='0') t0++;
        if (s[i]=='1' && i+1<s.size() && s[i+1]=='1'){
            t11++;
            i++;
            continue;
        }
        if (s[i]=='1'){
            t1++;
        }
    }
    kill(ent(t11,t0+t11));
    return 0;
}
int32_t main(){
    sync;
    fac[0]=1;
    fm[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
    ll t=1;
    cin >> t;
    while(t--) Main();
}