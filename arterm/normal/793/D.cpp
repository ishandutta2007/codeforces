#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 1e9 + 7;

int add(int x) {
    return x;
}

template<typename... T>
int add(int x, T... y) {
    x += add(y...);
    if (x >= mod)
        x -= mod;
    return x;
}

template<typename... T>
int udd(int &x, T... y) {
    return x = add(x, y...);
}

template<typename... T>
int sub(int x, T... y) {
    return add(x, mod - add(y...));
}

int mul(int x) {
    return x;
}

template<typename... T>
int mul(int x, T... y) {
    return 1ll * x * mul(y...) % mod;
}

int bin(int x, int to) {
    int y = 1;
    while (to) {
        if (to & 1)
            y = mul(x, y);
        x = mul(x, x);
        to >>= 1;
    }
    return y;
}

int inv(int x) {
    assert(x != 0);
    return bin(x, mod - 2);
}

const int M = 83;
const int inf = 1e9;

int n, k;
vector<int> g[M], w[M];
int d[M][M][M];

void read() {
    cin >> n >> k;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        g[v].push_back(u);
        w[v].push_back(c);
    }
}

void uin(int &x, int y) {
    x = min(x, y);
}

void kill() {
    for (int t = 0; t < M; ++t)
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                d[t][x][y] = inf;

    for (int x = 0; x < n; ++x)
        d[0][x][x] = 0;

    for (int t = 0; t < k; ++t)
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y) {
                if (d[t][x][y] != inf) {
                    //cerr << t << " " << x << " " << y << endl;
                    for (int i = 0; i < (int) g[x].size(); ++i) {
                        int to = g[x][i];
                        int c = w[x][i];
                        if (min(x, y) <= to && to <= max(x, y))
                            continue;
                        int tmx = max({x, y, to});
                        int tmn = min({x, y, to});
                        int ty = tmx ^ tmn ^ to;
                        uin(d[t + 1][to][ty], d[t][x][y] + c);
                    }
                }
            }

    int ans = inf;
    for (int x = 0; x < n; ++x)
        for (int y = 0; y < n; ++y)
            uin(ans, d[k - 1][x][y]);

    if (ans == inf) {
        cout << "-1\n";
        return;
    }

    cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}