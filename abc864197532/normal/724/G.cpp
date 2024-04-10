#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 333;

lli basis[60];
int basis_num = 0;
bool has[60];

void add(lli t) {
    for (int i = 59; ~i; --i) if (t >> i & 1) has[i] = true;
    for (int i = 59; ~i; --i) if (t >> i & 1) {
        if (!basis[i]) {
            basis[i] = t;
            basis_num++;
            return;
        }
        t ^= basis[i];
    }
}

vector <pair <int, long long>> adj[N];
lli dis[N];
int cnt[60], vis_city;
bool vis[N];

void dfs(int v, int pa) {
    for (int i = 59; ~i; --i) if (dis[v] >> i & 1) cnt[i]++;
    vis[v] = true;
    vis_city++;
    for (auto [u, w] : adj[v]) if (u != pa) {
        if (vis[u]) {
            add(dis[u] ^ dis[v] ^ w);
        } else {
            dis[u] = dis[v] ^ w;
            dfs(u, v);
        }
    }
}

lli modpow(lli a, lli b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <lli> pw(121, 1);
    for (int i = 1; i <= 120; ++i) pw[i] = pw[i - 1] * 2 % mod;
    lli w;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        dfs(i, -1);
        for (int j = 0; j < 60; ++j) {
            if (has[j]) {
                ans += pw[j + basis_num - 1] * ((1ll * vis_city * (vis_city - 1) / 2) % mod) % mod;
            } else {
                ans += pw[j + basis_num] * (1ll * cnt[j] * (vis_city - cnt[j]) % mod) % mod;
            }
            if (ans >= mod) ans -= mod;
        }
        for (int j = 0; j < 60; ++j) basis[j] = 0, has[j] = false, cnt[j] = 0;
        basis_num = vis_city = 0;
    }
    cout << ans << '\n';
}