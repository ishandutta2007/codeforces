#include <bits/stdc++.h>

using namespace std;

using int128 = __int128_t;

#define rep(i, n)         for (int i = 0; i < n; ++i)
#define reps(i, n, s)     for (int i = 0; i < n; i += s)
#define repl(i, l, r)     for (int i = l; i < r; ++i)
#define repsl(i, l, r, s) for (int i = l; i < r; i += s)

#define all(iterable) (iterable).begin(), (iterable).end()

constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template <typename T>
void print_vector(const vector<T>& vec, const string sep = " ", const string end = "\n") {
    int n = vec.size();
    rep(i, n) {
        cout << vec[i];
        if (i < n - 1) cout << sep;
        else cout << end;
    }
}

template <typename T>
void read_vector(vector<T>& a, int begin_index, int length) {
    if (a.size() < begin_index + length) a.resize(begin_index + length);
    while (length --> 0) cin >> a[begin_index++];
}
template <typename T>
void read_vector(vector<T>& a) { read_vector(a, 0, a.size()); }

constexpr int inf = 1 << 30;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<tuple<int, int, int>>>> edges(n, vector<vector<tuple<int, int, int>>>(m));
    rep(i, n) rep(j, m - 1) {
        int c;
        cin >> c;
        edges[i][j].push_back({i, j + 1, c});
        edges[i][j + 1].push_back({i, j, c});
    }
    rep(i, n - 1) rep(j, m) {
        int c;
        cin >> c;
        edges[i][j].push_back({i + 1, j, c});
        edges[i + 1][j].push_back({i, j, c});
    }
    if (k & 1) {
        rep(i, n) rep(j, m) cout << -1 << " \n"[j == m - 1];
        return 0;
    }
    k /= 2;
    auto in = [&](int i, int j) { return 0 <= i and i < n and 0 <= j and j < m; };
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n, vector<int>(m, inf)));
    rep(i, n) rep(j, m) dp[0][i][j] = 0;
    rep(t, k) {
        rep(i, n) rep(j, m) {
            for (auto &[ni, nj, c] : edges[i][j]) {
                dp[t + 1][i][j] = min(dp[t + 1][i][j], dp[t][ni][nj] + c);
            }
        }
    }
    rep(i, n) rep(j, m) {
        cout << 2 * dp[k][i][j] << " \n"[j == m - 1];
    }
    return 0;
}