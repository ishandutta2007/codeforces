#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
//#define _USE_MATH_DEFINE
using namespace std;

const int R = 1 << 17, inf = 1e16;

int t[R * 2], t2[R * 2];

void build() {
    for (int i = R - 1; i >= 0; --i) {
        t[i] = min(t[i * 2], t[i * 2 + 1]);
        t2[i] = min(t2[i * 2], t2[i * 2 + 1]);
    }
}

int get(int ql, int qr, int node = 1, int nl = 0, int nr = R) {
    if (ql <= nl && nr <= qr) {
        return t[node];
    }
    if (qr <= nl || nr <= ql) {
        return inf;
    }
    int nm = (nl + nr) / 2;
    return min(get(ql, qr, node * 2, nl, nm), get(ql, qr, node * 2 + 1, nm, nr));
}

int get2(int ql, int qr, int x, int node = 1, int nl = 0, int nr = R) {
    if (ql <= nl && nr <= qr) {
        if (t2[node] < x) {
            return x - t2[node];
        }
        return 0;
    }
    if (qr <= nl || nr <= ql) {
        return 0;
    }
    int nm = (nl + nr) / 2;
    return max(get2(ql, qr, x, node * 2, nl, nm), get2(ql, qr, x, node * 2 + 1, nm, nr));
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> pr(n + 1), pr2(n + 1);
    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i] + b[i] - a[i];
        pr2[i + 1] = pr2[i] + a[i] - b[i];
    }
    for (int i = 0; i < n; ++i) {
        t[i + R] = pr[i + 1];
        t2[i + R] = pr2[i + 1];
    }
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (get(l, r) - pr[l] < 0 || pr[r] - pr[l] != 0) {
            cout << -1 << '\n';
        } else {
//            cout << pr[l] << ' ';
            cout << get2(l, r, pr2[l]) << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}