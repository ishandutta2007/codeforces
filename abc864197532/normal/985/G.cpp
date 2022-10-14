/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 450;

vector <int> adj[N];

int main () {
    owo;
    unsigned long long ans = 0;
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; ++i) sort(all(adj[i]));
    // 0
    for (int i = 0; i < n; ++i) {
        // a
        unsigned long long res = 1ll * (n - i - 1) * (n - i - 2) / 2 * i;
        res *= a;
        ans += res;
        // b
        res = 1ll * i * (n - i - 1) * i;
        res *= b;
        ans += res;
        // c
        res = 1ll * i * (i - 1) / 2 * i;
        res *= c;
        ans += res;
    }
    // 1
    for (int i = 0; i < n; ++i) for (int j : adj[i]) if (i < j) {
        // X i j
        ans -= 1ll * i * (i - 1) / 2 * a + 1ll * i * i * b + 1ll * i * j * c;
        // i X j
        ans -= 1ll * (j - i - 1) * i * a + 1ll * (i + j) * (j - i - 1) / 2 * b + 1ll * (j - i - 1) * j * c;
        // i j X
        ans -= 1ll * (n - j - 1) * i * a + 1ll * (n - j - 1) * j * b + 1ll * (j + n) * (n - j - 1) / 2 * c;
    }
    // 2
    for (int i = 0; i < n; ++i) {
        lli less_sum = 0, great_sum = 0;
        int cnt0 = 0, cnt1 = 0;
        for (int j : adj[i]) {
            if (j < i) {
                // X j i
                ans += 1ll * less_sum * a + 1ll * cnt0 * j * b + 1ll * cnt0 * i * c;
                less_sum += j;
                cnt0++;
            } else {
                // i X j
                ans += 1ll * cnt1 * i * a + 1ll * great_sum * b + 1ll * cnt1 * j * c;
                // X i j
                ans += 1ll * less_sum * a + 1ll * cnt0 * i * b + 1ll * cnt0 * j * c;
                great_sum += j;
                cnt1++;
            }
        }
    }
    // 3
    vector <pii> Q[n];
    vector <bool> is(n, false);
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() <= K) {
            for (int j = 0; j < adj[i].size(); ++j) if (i < adj[i][j]) {
                Q[adj[i][j]].eb(i, j + 1);
            }
        } else {
            for (int j : adj[i]) is[j] = true;
            for (int j = 0; j < n; ++j) if (i < j) {
                for (int k : adj[j]) if (j < k) {
                    if (is[j] && is[k]) {
                        ans -= 1ll * i * a + 1ll * j * b + 1ll * k * c;
                    }
                }
            }
            for (int j : adj[i]) is[j] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) is[j] = true;
        for (auto [j, k] : Q[i]) {
            for (; k < adj[j].size(); ++k) if (i < adj[j][k]) {
                if (is[adj[j][k]]) {
                    ans -= 1ll * j * a + 1ll * i * b + 1ll * adj[j][k] * c;
                }
            }
        }
        for (int j : adj[i]) is[j] = false;
    }
    cout << ans << endl;
}