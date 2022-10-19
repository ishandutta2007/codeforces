#include <bits/stdc++.h>
/// this time?
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
vector <pair <int,pii> > ans;
void solve(ll x,ll y){
    ans.pb({1,{x,y}});
    ans.pb({2,{x,y}});
    ans.pb({1,{x,y}});

    ans.pb({1,{x,y}});
    ans.pb({2,{x,y}});
    ans.pb({1,{x,y}});

}
int Main(){
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
    }
    ans.clear();
    for (int i=1;i<=n;i+=2){
        solve(i,i+1);
    }
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u.F << " " << u.S.F << " " << u.S.S << endl;
    }
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