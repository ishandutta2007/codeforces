#include <bits/stdc++.h>

#define int int64_t
#define all(x) begin(x), end(x)

using namespace std;

const int mod = 998244353;
const int maxn = 2e5 + 42;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}
int inv(int x) {
    return bpow(x, mod - 2);
}

vector<tuple<int, int, int>> g[maxn];
int r[maxn];

vector<int> pdivs[maxn];

int mx[maxn], cur[maxn];
set<int> toc;

void dfs(int v = 0, int p = 0) {
    for(auto [u, x, y]: g[v]) {
        // r[v] / r[u] = x / y
        if(u != p) {
            int tx = x, ty = y;
            for(auto p: pdivs[y]) {
                while(ty % p == 0) {
                    ty /= p;
                    cur[p]++;
                }
                toc.insert(p);
            }
            for(auto p: pdivs[x]) {
                while(tx % p == 0) {
                    tx /= p;
                    cur[p]--;
                    mx[p] = min(mx[p], cur[p]);
                }
                toc.insert(p);
            }
            r[u] = y * r[v] % mod * inv(x) % mod;
            dfs(u, v);            
            tx = x, ty = y;
            for(auto p: pdivs[y]) {
                while(ty % p == 0) {
                    ty /= p;
                    cur[p]--;
                }
            }
            for(auto p: pdivs[x]) {
                while(tx % p == 0) {
                    tx /= p;
                    cur[p]++;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for(int z = 0; z < n - 1; z++) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        i--, j--;
        g[i].emplace_back(j, x, y);
        g[j].emplace_back(i, y, x);
    }
    r[0] = 1;
    dfs();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += r[i];
        ans %= mod;
    }
    for(auto it: toc) {
        ans = ans * bpow(it, -mx[it]) % mod;
        cur[it] = mx[it] = 0;
    }
    cout << ans << "\n";
    for(int i = 0; i < n; i++) {
        g[i].clear();
        r[i] = 0;
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i < maxn; i++) {
        if(pdivs[i].empty()) {
            for(int j = i; j < maxn; j += i) {
                pdivs[j].push_back(i);
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}