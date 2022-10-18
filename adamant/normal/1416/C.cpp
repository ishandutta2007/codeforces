#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 42;
const int logn = 32;
const int maxs = 2 * maxn * logn;
int to[maxs][2], szs[maxs];
int64_t inv[logn], uninv[logn], totinv;
int sz = 2;

void add_num(int x) {
    int v = 1;
    szs[v]++;
    for(int i = logn - 1; i >= 0; i--) {
        int c = (x >> i) & 1;
        if(c == 0) {
            inv[i] += szs[to[v][1]];
            totinv += szs[to[v][1]];
        } else {
            uninv[i] += szs[to[v][0]];
        }
        if(!to[v][c]) {
            to[v][c] = sz++;
        }
        v = to[v][c];
        szs[v]++;
    }
}

pair<int64_t, int> best_x() {
    int64_t ans = totinv, x = 0;
    for(int i = logn - 1; i >= 0; i--) {
        if(inv[i] > uninv[i]) {
            x ^= 1LL << i;
            ans -= inv[i] - uninv[i];
        }
    }
    return {ans, x};
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        add_num(a[i]);
    }
    int64_t ans;
    int x;
    tie(ans, x) = best_x();
    cout << ans << ' ' << x << "\n";
}

signed main() {
    //cout << ((sizeof(to) + sizeof(inv) + sizeof(szs)) >> 20) << endl;
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
}