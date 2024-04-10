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
typedef pair<pll, pll> Mat;

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

ll n, q, A[MAXN];
Mat M = {{1, 1},
         {1, 0}}, seg[MAXN << 2], lazy[MAXN << 2];

Mat operator+(Mat &A, Mat &B) {
    return {{(A.X.X + B.X.X) % MOD , (A.X.Y + B.X.Y) % MOD},
            {(A.Y.X + B.Y.X) % MOD , (A.Y.Y + B.Y.Y) % MOD}};
}

Mat operator*(Mat &A, Mat &B) {
    return {{(A.X.X * B.X.X + A.X.Y * B.Y.X) % MOD, (A.X.X * B.X.Y + A.X.Y * B.Y.Y) % MOD},
            {(A.Y.X * B.X.X + A.Y.Y * B.Y.X) % MOD, (A.Y.X * B.X.Y + A.Y.Y * B.Y.Y) % MOD}};
}

Mat operator^(Mat A, ll x) {
    Mat ans = {{1, 0},
               {0, 1}};
    for (ll i = 0; i < 30; i++, A = A * A) {
        if (x & (1ll << i)) ans = ans * A;
    }
    return ans;
}

void build(int id = 1, int l = 0, int r = MAXN) {
    if (r - l == 1) {
        seg[id] = M ^ (A[l] - 1);
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

void shift(int id) {
    lazy[id << 1] = lazy[id << 1] * lazy[id];
    lazy[id << 1 | 1] = lazy[id << 1 | 1] * lazy[id];
    seg[id << 1] = seg[id << 1] * lazy[id];
    seg[id << 1 | 1] = seg[id << 1 | 1] * lazy[id];
    lazy[id] = {{1, 0},
                {0, 1}};
}

void update(int ql, int qr, Mat x, int id = 1, int l = 0, int r = MAXN) {
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
        lazy[id] = lazy[id] * x;
        seg[id] = seg[id] * x;
        return;
    }
    shift(id);
    int mid = l + r >> 1;
    update(ql, qr, x, id << 1, l, mid);
    update(ql, qr, x, id << 1 | 1, mid, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

ll get(int ql, int qr, int id = 1, int l = 0, int r = MAXN) {
    if (qr <= l || r <= ql) return 0;
    if (ql <= l && r <= qr) return seg[id].X.X;
    shift(id);
    int mid = l + r >> 1;
    return get(ql, qr, id << 1, l, mid) + get(ql, qr, id << 1 | 1, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(lazy, lazy + MAXN * 4, Mat(pll(1, 0), pll(0, 1)));
    fill(A, A + MAXN, 1);

    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> A[i];
    build();
    while (q--) {
        ll t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            ll x;
            cin >> x;
            Mat A = M ^ x;
            update(l, r + 1, A);
        } else {
            cout << get(l, r + 1) % MOD << endl;
        }
    }

    return 0;
}
/*
 
*/