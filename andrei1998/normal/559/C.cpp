#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 2005;

int h, w, n;
struct point {
    int x, y;

    point(int _x = 0, int _y = 0): x(_x), y(_y) {}
} v[NMAX];

bool operator<(const point &a, const point &b) {
    return (a.x <= b.x && a.y <= b.y);
}

vector <int> graph[NMAX];

const int mod = 1000000007;

int inv[200005];

int fact[200005];
int inv_fact[200005];

inline void precalc() {
    inv[1] = 1;
    for (int i = 2; i <= h + w; ++ i)
        inv[i] = (mod - 1ll * (mod / i) * inv[mod % i] % mod) % mod;

    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= h + w; ++ i) {
        fact[i] = (1ll * i * fact[i - 1]) % mod;
        inv_fact[i] = (1ll * inv[i] * inv_fact[i - 1]) % mod;
    }
}

int comb(int n, int k) {
    return ((1ll * fact[n] * inv_fact[n - k]) % mod * inv_fact[k]) % mod;
}

int dp[NMAX];
bool vis[NMAX];

void dfs(int node) {
    if (vis[node])
        return ;
    vis[node] = true;

    dp[node] = comb(v[node].x + v[node].y - 2, v[node].x - 1);
    for (auto it: graph[node]) {
        dfs(it);

        dp[node] = (dp[node] - 1ll * comb(v[node].x - v[it].x + v[node].y - v[it].y, v[node].x - v[it].x) * dp[it]) % mod;
        if (dp[node] < 0)
            dp[node] += mod;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> h >> w >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i].x >> v[i].y;
    v[++ n] = point(h, w);

    int j;
    for (int i = 1; i <= n; ++ i)
        for (j = 1; j <= n; ++ j)
            if (i != j && v[i] < v[j])
                graph[j].push_back(i);

    precalc();

    dfs(n);

    cout << dp[n] << '\n';
    return 0;
}