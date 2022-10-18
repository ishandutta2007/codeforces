#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 5e5 + 42;

int mx[4 * maxn], ad[4 * maxn], sz[4 * maxn];

void add(int p, int c, int v = 1, int l = 0, int r = maxn) {
    if(r - l == 1) {
        sz[v] += c > 0 ? 1 : -1;
        if(sz[v] == 0 && c < 0 || sz[v] == 1 && c > 0) {
            mx[v] += c;
        }
    } else {
        int m = (l + r) / 2;
        if(p < m) {
            add(p, c, 2 * v, l, m);
        } else {
            add(p, c, 2 * v + 1, m, r);
        }
        sz[v] = sz[2 * v] + sz[2 * v + 1];
        mx[v] = ad[v] + max(mx[2 * v], mx[2 * v + 1]);
    }
}

void upd(int a, int b, int c, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        ad[v] += c;
        mx[v] += c;
    } else if(r <= a || b <= l) {
        return;
    } else {
        int m = (l + r) / 2;
        upd(a, b, c, 2 * v, l, m);
        upd(a, b, c, 2 * v + 1, m, r);
        mx[v] = ad[v] + max(mx[2 * v], mx[2 * v + 1]);
    }
}

int get(int v = 1, int l = 0, int r = maxn, int up = 0) {
    if(r - l == 1) {
        return 1;
    } else {
        int m = (l + r) / 2;
        int mxl = up + ad[v] + mx[2 * v];
        int mxr = up + ad[v] + mx[2 * v + 1];
        int res = 0;
        if(mxl > 0 && sz[2 * v] > 0) {
            res += get(2 * v, l, m, up + ad[v]);
        }
        if(mxr > 0 && sz[2 * v + 1] > 0) {
            res += get(2 * v + 1, m, r, up + ad[v]);
        }
        return res;
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    vector<char> t(q);
    vector<int> x(q);
    for(int i = 0; i < q; i++) {
        cin >> t[i] >> x[i];
    }
    auto y = x;
    sort(all(y));
    y.erase(unique(all(y)), end(y));
    int sz = 0;
    for(int i = 0; i < q; i++) {
        if(t[i] == '+') {
            sz++;
            add(lower_bound(all(y), x[i]) - begin(y), x[i]);
            upd(upper_bound(all(y), x[i]) - begin(y), maxn, -2 * x[i]);
        } else {
            sz--;
            add(lower_bound(all(y), x[i]) - begin(y), -x[i]);
            upd(upper_bound(all(y), x[i]) - begin(y), maxn, 2 * x[i]);
        }
        cout << sz - get() << endl;
    }
    return 0;
}