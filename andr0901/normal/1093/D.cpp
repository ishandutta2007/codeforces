#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> gr;
vector <int> col;

int change_color(int cur) {
    if (cur == 1)
        return 2;
    else 
        return 1;
}

int ok;
vector <int> cnt;

void dfs(int v, int cur) {
    cur = change_color(cur);
    col[v] = cur;
    cnt[cur]++;
    for (auto u : gr[v]) {
        if (col[u] == cur)
            ok = 0;
        if (!col[u]) 
            dfs(u, cur);
    }
}

const int MOD = 998244353;

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    return (1LL * bin_pow(a, p / 2) * bin_pow(a, p / 2)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        int n, m;
        cin >> n >> m;
        gr.clear(), gr.resize(n);
        forn (i, 0, m) {
            int v, u;
            cin >> v >> u;
            v--, u--;
            gr[v].pb(u), gr[u].pb(v);
        }
        col.clear(), col.resize(n);
        ok = 1;
        int ans = 1;
        forn (i, 0, n) {
            if (!col[i]) {
                cnt.clear(), cnt.resize(3);
                dfs(i, 1);
                ans = (1LL * ans * (bin_pow(2, cnt[1]) + bin_pow(2, cnt[2]))) % MOD;
            }
        }
        if (ok)
            cout << ans;
        else 
            cout << 0;
        cout << "\n";
    }
    return 0;
}