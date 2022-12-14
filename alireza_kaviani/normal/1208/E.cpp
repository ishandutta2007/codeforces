/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct MaxQ {
    set<pll, greater<pll>> st;
    ll ind = 0;

    ll size() { return SZ(st) != 0; }

    void push(ll val, ll i, ll &ans) {
        if (size()) ans -= (*st.begin()).X;
        st.insert({val, i});
        if (size()) ans += (*st.begin()).X;
    }

    void pull(ll i, ll &ans) {
        if (size()) ans -= (*st.begin()).X;
        while (size() && (*st.begin()).Y <= i) {
            st.erase(st.begin());
        }
        if (size()) ans += (*st.begin()).X;
    }
};

ll n, w, ans;
pll A[MAXN];
MaxQ Q[MAXN];
vector<ll> vec[MAXN];

int main() {
    fast_io;

    cin >> n >> w;
    for (ll i = 0; i < n; i++) {
        cin >> A[i].X;
        A[i].Y = i;
        vec[i].push_back(0);
        for (ll j = 0; j < A[i].X; j++) {
            ll x;
            cin >> x;
            vec[i].push_back(x);
        }
        A[i].X += 2;
        vec[i].push_back(0);
    }

    sort(A, A + n);

    for (ll i = 0; i < w + 2; i++) {
        ll ind = upper_bound(A, A + n, pll(i, INF)) - A;
        for (ll j = ind; j < n; j++) {
            Q[j].push(vec[A[j].Y][i], i, ans);
        }
        if (i != 0 && i != w + 1) cout << ans << sep;
        ind = upper_bound(A, A + n, pll(w + 2 - i, -INF)) - A;
        for (ll j = ind; j < n; j++) {
            Q[j].pull(i - w - 2 + A[j].X, ans);
        }
    }

    return 0;
}
/*

*/