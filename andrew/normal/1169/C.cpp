#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define pll pair<ll, ll>
#define m_p make_pair
#define p_b push_back
#define all(v) v.begin(), v.end()
#define sqr(x)  (x) * (x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 3e5 + 5;
const ll M = 20;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n), b(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    ll l = 0, r = m;

    while(l < r){
        ll c = (l + r) >> 1;
        bool f = 1;
        ll mx = 0;
        for(int i = 0; i < n; i++){
            ll k = 1e18;
            if(a[i] >= mx) k = a[i];
            if(a[i] + c >= m){
                ll val = (a[i] + c) % m;
                if(val >= mx){
                    k = min(k, mx);
                }
                if(a[i] < mx)k = min(k, mx);
            }else{
                if(a[i] + c >= mx)k = min(max(mx, a[i]), k);
            }
            if(k == 1e18)f = 0;
            mx = max(mx, k);
        }

        if(!f)l = c + 1; else r = c;
    }

    cout << l << "\n";

    return 0;
}