#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 401, logN = 20, K = 111, C = 7;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <pii> E;
    vv <int> dis(n, n, 1e9);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        dis[u][v] = dis[v][u] = 1, E.eb(u, v);
    }
    for (int i = 0; i < n; ++i)
        dis[i][i] = 0;
    for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        vector <int> cnt(n);
        int c = 0;
        for (int k = 0; k < n; ++k) if (dis[i][j] == dis[i][k] + dis[k][j])
            c++, cnt[k] = 1;
        if (c != dis[i][j] + 1) {
            cout << 0 << " \n"[j == n - 1];
            continue;
        }
        for (auto [u, v] : E) {
            if (dis[i][j] != dis[i][v] + dis[v][j])
                if (dis[i][u] < dis[i][v] && dis[j][u] < dis[j][v])
                    cnt[v]++;
            if (dis[i][j] != dis[i][u] + dis[u][j])
                if (dis[i][u] > dis[i][v] && dis[j][u] > dis[j][v])
                    cnt[u]++;
        }
        cout << accumulate(all(cnt), 1ll, [&](int i, int j) {
            return 1ll * i * j % mod;
        }) << " \n"[j == n - 1];
    }
}