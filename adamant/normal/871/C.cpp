#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 3e5;

int par[maxn], sz[maxn];

int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}

int comp = 0;
int ff[maxn], cyc[maxn];

void uni(int a, int b) {
    a = get(a);
    b = get(b);
    ff[a] = true;
    if(a == b) {
        cyc[a] = 1;
        return;
    }
    comp--;
    cyc[a] |= cyc[b];
    sz[a] += sz[b];
    par[b] = a;
}

int gg(vector<int> &X, int x) {
    assert(binary_search(begin(X), end(X), x));
    return lower_bound(begin(X), end(X), x) - begin(X);
}

const int mod = 1e9 + 7;

int bpow(int x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n % 2 == 0) {
        return bpow(x * x % mod, n / 2);
    } else {
        return x * bpow(x, n - 1) % mod;
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + maxn, 0);
    fill(sz, sz + maxn, 1);
    int n;
    cin >> n;
    int x[n], y[n];
    map<int, vector<int>> xy, yx;
    set<int> xx, yy;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        xx.insert(x[i]);
        yy.insert(y[i]);
    }
    vector<int> X(begin(xx), end(xx));
    vector<int> Y(begin(yy), end(yy));
    for(int i = 0; i < n; i++) {
        uni(n + gg(X, x[i]), gg(Y, y[i]));
    }
    int ans = 1;
    for(int i = 0; i < maxn; i++) {
        if(i != par[i]) {
            continue;
        }
        if(ff[i]) {
            ans = ans * (bpow(2, sz[i]) - 1 + cyc[i] + mod) % mod;
        }
        
    }
    
    cout << ans << "\n";
    return 0;
}