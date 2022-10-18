#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 833280 + 7;
const int mod = 998244353;

int mx[4 * maxn];

void upd(int p, int c, int n) {
    int v = n + p;
    mx[v] = c;
    do {
        mx[v >> 1] = max(mx[v], mx[v ^ 1]);
    } while(v >>= 1);
}

void build(int n) {
    for(int i = n - 1; i; i--) {
        mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    }
}

int get() {
    return mx[1];
}

int mul(int a, int b) {
    return (a * b) % mod;
}
int add(int a, int b) {
    return (a + b) % mod;
}

void solve() {
    int n, q;
    n = 166320;
    q = 200000;
    cin >> n >> q;
    vector<int> divs;
    vector<vector<int>> sums, idxs;
    int IDX = 0;
    fill(mx, mx + 2 * IDX + 2, 0);
    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            divs.push_back(i);
            sums.emplace_back(vector<int>(i));
            idxs.emplace_back(vector<int>(i));
            for(auto &it: idxs.back()) {
                it = IDX++;
            }
        }
    }
    int a[n];
    int m = divs.size();
    int pmod[n][m];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            int t = i % divs[j];
            pmod[i][j] = t;
            sums[j][t] += a[i] * divs[j];
            mx[IDX + idxs[j][t]] = sums[j][t];
        }
    }
    build(IDX);
    cout << get() << "\n";
    for(int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        for(int j = 0; j < m; j++) {
            int t = pmod[p][j];
            sums[j][t] += (x - a[p]) * divs[j];
            upd(idxs[j][t], sums[j][t], IDX);
        }
        a[p] = x;
        cout << get() << "\n";
    }
    
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}