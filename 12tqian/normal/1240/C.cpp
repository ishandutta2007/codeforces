#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }

const int N = 5e5 + 5;

ll dp[N][2]; 
int n, k;
vector<vpl> adj;
// 0 - you're free to take thing above
// 1 - don't take thing above

void reset() {
    adj.clear();
    f0r(i, n) f0r(j, 2) dp[i][j] = 0;
}

void dfs(int u, int p) {
    vpl use; 
    each(go, adj[u]) {
        int v = go.f;
        ll w = go.s;
        if (v == p) continue;
        dfs(v, u);
        use.eb(dp[v][0]+w, dp[v][1]);
    }
    ll base = 0;
    vl del;
    each(t, use) {
        base += t.s; // take the nothing
        del.pb(t.f-t.s);
    }
    sort(all(del));
    reverse(all(del));
    auto sum = [&](int num) -> ll {
        ll res = 0;
        f0r(i, min(num, sz(del))) res += max(del[i], 0LL);
        return res;
    };
    dp[u][0] = sum(k-1) + base;
    dp[u][1] = sum(k) + base;
}


void solve_case() {
    cin >> n >> k;
    adj.resize(n);
    f0r(i, n-1) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    dfs(0, -1);

    ll ans = dp[0][1];

    cout << ans << '\n';

    reset();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) solve_case();
    return 0;
}