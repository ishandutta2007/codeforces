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
const ll max_3_step = 450283905890997363;
const ll max_3_pow = 37;
void solve(ll n){
    vector<ll> n_in_3;
    ll cur_3_step = max_3_step;
    ll f2 = -1;
    for(ll i = max_3_pow;i>=0;i--){
        ll c = 0;
        while(n >= cur_3_step){
            n-= cur_3_step;
            c++;
        }
        if(c == 2 && f2 == -1) f2 = i;
        cur_3_step/=3;
        n_in_3.pb(c);
    }
    reverse(itr(n_in_3));
    if(f2 != -1){
        n_in_3[f2] = 0;
        ll cp = f2+1;
        if(cp == n_in_3.size()) n_in_3.pb(0);
        while(cp < n_in_3.size() && ++n_in_3[cp]>1){
            n_in_3[cp] = 0;
            cp++;
            if(cp == n_in_3.size()) n_in_3.pb(0);
        }
        for(ll i =0;i<f2;i++) n_in_3[i] = 0;
    }
    ull x = 1, r = 0;
    for(ll i = 0;i<n_in_3.size();i++) r+=((ull)n_in_3[i])*x, x*=(ull)3;
    cout << r << endl;
}
main(){
    FAST;
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        solve(n);
    }
}