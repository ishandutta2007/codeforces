#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ll t[2][N + 2];

void u(ll xe, ll pos, ll val){
    for(; pos <= N; pos += pos & -pos)t[xe][pos] += val;
}

ll f(ll xe, ll pos){
    ll res = 0;
    for(; pos > 0; pos -= pos & -pos)res += t[xe][pos];
    return res;
}

ll get(ll xe, ll l, ll r){
    return f(xe, r) - f(xe, l - 1);
}

ll sum(ll x){
    return x * (x + 1) >> 1;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ordered_set <ll> st;

    ll n;
    cin >> n;

    vector <ll> a(n + 1), pos(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }

    ll S = 0;

    for(int i = 1; i <= n; i++){
        S += get(0, pos[i], n);
        ll ans = S;
        st.insert(pos[i]);
        ll mid = *st.find_by_order(sz(st) / 2);
        u(0, pos[i], 1);
        u(1, pos[i], pos[i]);

        ans += get(0, 1, mid - 1) * mid - get(1, 1, mid - 1) - sum(get(0, 1, mid - 1));
        ans += get(1, mid + 1, n) - get(0, mid + 1, n) * mid - sum(get(0, mid + 1, n));
        cout << ans << " ";
    }

    return 0;
}