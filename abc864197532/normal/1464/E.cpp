#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 998244353, abc = 864197532, N = 100000, logN = 17, M = 512;

vector <int> adj[N];
int dp[N];

int mex(vector <int> &a) {
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    for (int i = 0; i < a.size(); ++i) {
        if (i ^ a[i]) return i;
    }
    return a.size();
}

int ask(int v) {
    if (~dp[v]) return dp[v];
    vector <int> cur;
    for (int u : adj[v]) cur.pb(ask(u));
    return dp[v] = mex(cur);
}

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < N; ++i) dp[i] = -1;
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
    }
    vector <int> cnt(M, 0);
    for (int i = 0; i < n; ++i) cnt[ask(i)]++;
    vector <vector <long long>> mat(M, vector <long long>(M + 1, 0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            mat[i][i ^ j] = (j == 0 ? n + 1 : 0) - cnt[j];
            if (mat[i][i ^ j] < 0) mat[i][i ^ j] += mod;
        }
    }
    mat[0][M] = 1;
    for (int i = 0; i < M; ++i) {
        long long times = modpow(mat[i][i], mod - 2);
        for (int k = 0; k < M + 1; ++k) {
            mat[i][k] = mat[i][k] * times % mod;
        }
        for (int j = 0; j < M; ++j) if (i ^ j) {
            times = mat[j][i];
            for (int k = 0; k < M + 1; ++k) {
                mat[j][k] -= mat[i][k] * times % mod;
                if (mat[j][k] < 0) mat[j][k] += mod;
            }
        }
    }
    cout << (1 + mod - mat[0][M]) % mod << '\n';
}