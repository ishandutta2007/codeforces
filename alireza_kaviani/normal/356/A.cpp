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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, L[MAXN], R[MAXN], val[MAXN];
int seg[MAXN << 2], lazy[MAXN << 2];

void Shift(int id, int l, int r) {
    lazy[id << 1] = min(lazy[id << 1], lazy[id]);
    seg[id << 1] = min(seg[id << 1], lazy[id]);
    lazy[id << 1 | 1] = min(lazy[id << 1 | 1], lazy[id]);
    seg[id << 1 | 1] = min(seg[id << 1 | 1], lazy[id]);
    lazy[id] = INF;
}

void Update(int ql, int qr, int x, int id = 1, int l = 0, int r = MAXN) {
    //cout << id << sep << l << sep << r << sep << seg[id] << endl;
    if (r <= ql || qr <= l || l >= r || ql >= qr) return;
    if (ql <= l && r <= qr) {
        lazy[id] = min(lazy[id], x);
        seg[id] = min(seg[id], x);
        return;
    }
    Shift(id, l, r);
    int mid = l + r >> 1;
    Update(ql, qr, x, id << 1, l, mid);
    Update(ql, qr, x, id << 1 | 1, mid, r);
    seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}

void Print(int ql, int qr, int id = 1, int l = 0, int r = MAXN) {
    if (r <= ql || qr <= l || l >= r || ql >= qr) return;
    if (r - l == 1) {
        cout << (seg[id] == INF ? 0 : val[seg[id]]) << sep;
        return;
    }
    Shift(id, l, r);
    int mid = l + r >> 1;
    Print(ql, qr, id << 1, l, mid);
    Print(ql, qr, id << 1 | 1, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(seg, seg + MAXN * 4, INF);
    fill(lazy, lazy + MAXN * 4, INF);

    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        cin >> L[i] >> R[i] >> val[i];
        Update(L[i], val[i], i);
        Update(val[i] + 1, R[i] + 1, i);
    }
    Print(1, n + 1);

    return 0;
}
/*

*/