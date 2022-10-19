#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100;
map <int,bool> mp;
int Main(){
   ll n;
   cin >> n;
   if (mp[n]) kill("YES");
   kill("NO");
}
int32_t main(){
    sync;
    for (int i=1;i<(ll)1e5;i++){
        mp[2*i*i]=1;
        mp[4*i*i]=1;
    }
    ll t=1;
    cin >> t;
    while(t--) {
        Main();
    }
}