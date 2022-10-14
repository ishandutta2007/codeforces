#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 100008, logN = 18, K = 500, C = 100;

int mod;
vector <pii> adj[N];
int sz[N], cd_pa[N], dep[N];
lli pw[N], pwinv[N], dis1[N], dis2[N];
vector <vector <int>> cur;
lli ans = 0;

int phi(int x) {
    int ans = x;
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
        ans -= ans / i;
        while (x % i == 0) x /= i;
    }
    if (x > 1) ans -= ans / x;
    return ans;
}

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

void dfs1(int v, int pa) {
    sz[v] = 1;
    for (pii A : adj[v]) if (A.X != pa && cd_pa[A.X] == -1) {
        dfs1(A.X, v);
        sz[v] += sz[A.X];
    }
}

int dfs2(int v, int pa, int n) {
    for (pii A : adj[v]) if (A.X != pa && cd_pa[A.X] == -1 && sz[A.X] > n / 2) {
        return dfs2(A.X, v, n);
    }
    return v;
}

void dfs3(int v, int pa, int w) {
    if (~pa) cur.back().pb(v);
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    dis1[v] = ~pa ? (dis1[pa] * 10 + w) % mod : 0;
    dis2[v] = ~pa ? (pw[dep[pa]] * w + dis2[pa]) % mod : 0;
    if (~pa && !dis1[v]) ans++;
    if (~pa && !dis2[v]) ans++;
    for (pii A : adj[v]) if (A.X != pa && cd_pa[A.X] == -1) {
        if (!~pa) cur.pb({});
        dfs3(A.X, v, A.Y);
    }
    if (!~pa) {
        for (int t : {0, 1}) {
            map <int, int> m1;
            fop (i,0,cur.size()) {
                for (int k : cur[i]) {
                    lli re = 1ll * (mod - dis1[k]) % mod * pwinv[dep[k]] % mod;
                    ans += m1[re];
                }
                for (int k : cur[i]) {
                    m1[dis2[k]]++;
                }
            }
            m1.clear();
            reverse(all(cur));
        }
        cur.clear();
    }
}

void cd(int v, int pa) {
    dfs1(v, pa);
    int c = dfs2(v, pa, sz[v]);
    cd_pa[c] = ~pa ? pa : -2;
    dfs3(c, -1, 0);
    for (pii A : adj[c]) if (cd_pa[A.X] == -1) {
        cd(A.X, c);
    }
    if (pa == -1) cd_pa[c] = -1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v, w;
    cin >> n >> mod;
    if (mod == 1) {
        cout << 1ll * n * (n - 1) << endl;
        return 0;
    }
    fop (i,0,n - 1) {
        cin >> u >> v >> w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    pw[0] = pwinv[0] = 1;
    int inv = modpow(10, phi(mod) - 1);
    for (int i = 1; i < N; ++i) pw[i] = pw[i - 1] * 10 % mod, pwinv[i] = pwinv[i - 1] * inv % mod;
    for (int i = 0; i < n; ++i) cd_pa[i] = -1;
    cd(0, -1);
    cout << ans << endl;
}