#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
vector<ll> res;
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++){
        char c;
        cin >> c;
        ll x = c-'0';
        if(x <= 1) continue;
        else if (x == 4){
            res.pb(3);
            res.pb(2);
            res.pb(2);
        }else if (x == 6){
            res.pb(5);
            res.pb(3);
        }else if (x == 8){
            res.pb(7);
            res.pb(2);
            res.pb(2);
            res.pb(2);
        }else if (x == 9){
            res.pb(7);
            res.pb(3);
            res.pb(3);
            res.pb(2);
        }else res.pb(x);
    }
    sort(itr(res), greater<ll>());
    for(auto i : res) cout << i;
}