#include <bits/stdc++.h>

#define int int64_t

using namespace std;

const int maxn = 5e5 + 42;
const int inf = 1e18;

vector<int> to_clean;

int mx[4 * maxn];

void upd(int p, int c, int v = 1, int l = 0, int r = maxn) {
    to_clean.push_back(v);
    mx[v] = max(mx[v], c);
    if(r - l > 1) {
        int m = (l + r) / 2;
        if(p < m) {
            upd(p, c, 2 * v, l, m);
        } else {
            upd(p, c, 2 * v + 1, m, r);
        }
    }
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        return mx[v];
    } else if(r <= a || b <= l) {
        return -inf;
    } else {
        int m = (l + r) / 2;
        return max(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
    }
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n + 1), d(n + 1, -n * n);
    d[0] = 0;
    partial_sum(a, a + n, begin(b) + 1);
    auto B = b;
    ranges::sort(B);
    for(auto &it: b) {
        it = lower_bound(begin(B), end(B), it) - begin(B);
    }
    map<int, int> Mx;
    upd(b[0], 0);
    for(int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + (b[i] > b[i - 1] ? 1 : b[i] < b[i - 1] ? -1 : 0);
        
        if(Mx.count(b[i])) {
            d[i] = max(d[i], Mx[b[i]]);
        }
        
        d[i] = max(d[i], i + get(0, b[i]));
        upd(b[i], d[i] - i);
        
        if(Mx.count(b[i])) {
            Mx[b[i]] = max(Mx[b[i]], d[i]);
        } else {
            Mx[b[i]] = d[i];
        }
    }
    cout << d[n] << "\n";
    for(auto it: to_clean) {
        mx[it] = -inf;
    }
    to_clean.clear();
}

signed main() {
    fill(mx, mx + 4 * maxn, -inf);
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) {
        solve();
    }
}