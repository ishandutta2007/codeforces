#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef complex<double> point;
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
const int N=2e5+100;
int Main(){
    ll n;
    cin >> n;
    ll x=2050;
    ll ans=0;
    while(n){
        ll z=x;
        if (z>n) kill(-1);
        while(z*(ll)10<=n){
            z*=(ll)10;
        }
        while(n>=z){
            n-=z;
            ans++;
        }
    }
    kill(ans);

    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--){
        Main();
    }
}