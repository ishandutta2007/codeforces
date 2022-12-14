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
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, q, sum[MAXN << 2], mx[MAXN << 2], mn[MAXN << 2], lz1[MAXN << 2], lz2[MAXN << 2];

void build(int id = 1, int l = 0, int r = MAXN) {
    if (r - l == 1) {
        mx[id] = mn[id] = l;
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid), build(id << 1 | 1, mid, r);
    mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
    mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
}

void shift(int id, int l, int r) {
    if (lz1[id] != 0) {
        mx[id << 1] = mx[id << 1 | 1] = mn[id << 1] = mn[id << 1 | 1] = lz1[id << 1] = lz1[id << 1 | 1] = lz1[id];
    }
    int mid = l + r >> 1;
    lz2[id << 1] += lz2[id];
    lz2[id << 1 | 1] += lz2[id];
    sum[id << 1] += lz2[id] * (mid - l);
    sum[id << 1 | 1] += lz2[id] * (r - mid);
    lz1[id] = lz2[id] = 0;
}

void update(int ql, int qr, ll x, int id = 1, int l = 0, int r = MAXN) {
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr && mx[id] == mn[id]) {
        lz1[id] = x;
        lz2[id] += abs(x - mx[id]);
        sum[id] += abs(x - mx[id]) * (r - l);
        mx[id] = mn[id] = x;
        return;
    }
    shift(id, l, r);
    int mid = l + r >> 1;
    update(ql, qr, x, id << 1, l, mid);
    update(ql, qr, x, id << 1 | 1, mid, r);
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
    mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
    mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
}

ll get(int ql, int qr, int id = 1, int l = 0, int r = MAXN) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return sum[id];
    shift(id, l, r);
    int mid = l + r >> 1;
    return get(ql, qr, id << 1, l, mid) + get(ql, qr, id << 1 | 1, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    build();
    while (q--) {
        ll t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            ll x;
            cin >> x;
            update(l, r + 1, x);
        }
        if (t == 2) cout << get(l, r + 1) << endl;
    }

    return 0;
}
/*

*/