#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42, logn = 20;
const int inf = 1e9;

int bpow(int x, int n, int m) {
    return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1;
}


vector<int> g[maxn];
int used[maxn];


void dfs(int v = 0) {
    if(used[v]) {
        return;
    }
    used[v] = 1;
    for(auto u: g[v]) {
        dfs(u);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < j && a[i] && a[j]) {
                g[i].push_back(j);
            }
            if(j < i && b[i] && b[j]) {
                g[i].push_back(j);
            }
        }
    }
    dfs();
    cout << (used[s - 1] ? "YES" : "NO") << endl;
    return 0;
}