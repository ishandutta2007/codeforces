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
int Main(){
    ll n;
    cin >> n;
    ll mx=0;
    while(n>0){
        mx=max(mx,n%10);
        n/=10;
    }
    kill(mx);
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}