#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }

const int N = 1e5 + 5;

int dp[N][2]; 
int down[N], up[N];
// best if you end at node i, j whether 'set'
// we don't add things that are above

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vi> adj(n);
    f0r(i, n-1) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    f1r(i, 1, n) up[i] = 1;
    f0r(i, n) {
        down[i] = sz(adj[i]);
        if (i) down[i]--;
    }
    int ans = 0;
    auto b2 = [&](vi v) -> int {
        assert(sz(v) >= 2);
        sort(all(v));
        int res = v.back();
        v.pop_back();
        res += v.back();
        return res;
    };
    function<void(int, int)> dfs = [&](int src, int par) {
        dp[src][0] = 1;
        dp[src][1] = down[src];
        for (int nxt : adj[src]) {
            if (nxt == par) continue;
            dfs(nxt, src);
            ckmax(dp[src][0], dp[nxt][1]+1);
            ckmax(dp[src][1], dp[nxt][0]+down[src]-1);
            ckmax(dp[src][1], dp[nxt][1]+down[src]-1);
        }

        ckmax(ans, dp[src][1]+up[src]);
        vi sub;
        ckmax(ans, dp[src][0]);
        if (down[src] < 2) return;
        // joiner is a set node
        for (int nxt : adj[src]) {
            if (nxt == par) continue;
            sub.eb(max(dp[nxt][0], dp[nxt][1]));
        }
        ckmax(ans, down[src]-2+up[src]+b2(sub));
        // joiner is unset node
        sub.clear();
        for (int nxt : adj[src]) {
            if (nxt == par) continue;
            sub.eb(dp[nxt][1]);
        }
        ckmax(ans, b2(sub)+1);
    };
    dfs(0, -1);
    cout << ans << '\n';
    return 0;
}