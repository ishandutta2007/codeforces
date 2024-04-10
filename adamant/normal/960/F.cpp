#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42, logn = 20, maxs = maxn * logn * 4;

int mx[maxs], L[maxs], R[maxs];
int sz = maxn;

int make(int &v) {
    if(!v) {
        v = sz++;
    }
    return v;
}

int get(int v, int p, int l = 0, int r = maxn) {
    if(r - l == 1) {
        return mx[v];
    }
    int m = (l + r) / 2;
    if(p <= m) {
        return get(L[v], p, l, m);
    } else {
        return max(mx[L[v]], get(R[v], p, m, r));
    }
}

void upd(int v, int p, int c, int l = 0, int r = maxn) {
    if(r - l == 1) {
        mx[v] = max(mx[v], c);
    } else {
        int m = (l + r) / 2;
        if(p < m) {
            upd(make(L[v]), p, c, l, m);
        } else {
            upd(make(R[v]), p, c, m, r);
        }
        mx[v] = max(mx[L[v]], mx[R[v]]);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[m], b[m], w[m];
    int ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> w[i];
        int t = get(a[i], w[i]) + 1;
        upd(b[i], w[i], t);
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}