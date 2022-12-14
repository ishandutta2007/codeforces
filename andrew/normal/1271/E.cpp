#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll n, k;

ll f(ll x){
    if(x > n)return 0;
    if(x & 1)return 1 + f(x << 1);
    ll ans = 0, p = 3;
    for(ll st = 0, step = 1;; st++, step *= 2){
        if(st == 0){
            ll l = x * step, r = x * step + (step * 2) - 1;
            if(l > n)break;
            ans += min(r, n) - l + 1;
            if(r >= n)break;
        }else if(st == 1){
            ll l = x * step, r = x * step + (step * 2) - 1;
            if(l > n)break;
            ans += min(r, n) - l + 1;
            if(r >= n)break;
        }else{
            p *= 2;
            ll l = x * step, r = x * step + (step * 2) - 1;
            if(l > n)break;
            ans += min(r, n) - l + 1;
            if(r >= n)break;
        }
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    cin >> n >> k;

    ll l = 0, r = n / 2;

    ll ans = 0;

    while(l < r){
        ll c = (l + r + 1) >> 1;
        ll val = c * 2;
        if(f(val) < k)r = c - 1; else l = c;
    }

    ans = l * 2;
    l = 0, r = (n + 1) / 2;

    while(l < r){
        ll c = (l + r + 1) >> 1;
        ll val = c * 2 - 1;
        if(f(val) < k)r = c - 1;
        else l = c;
    }

    ans = max(ans, (2 * l) - 1);

    cout << ans << "\n";

    return 0;
}