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
const int mod = 998244353, N = 300001, logN = 20, K = 111;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vv <lli> a(n, n, 1ll << 60);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        a[u][v] = w;
    }
    for (int i = 0; i < n; ++i) {
        vector <lli> dis(n, 1ll << 60);
        for (int j = 0; j < n; ++j) dis[j] = a[i][j];
        vector <bool> vis(n, false);
        while (true) {
            int v = -1;
            for (int i = 0; i < n; ++i) if (!vis[i] && (v == -1 || dis[v] > dis[i])) v = i;
            if (v == -1) break;
            vis[v] = true;
            int nxt = v + 1;
            if (nxt >= n) nxt -= n;
            dis[nxt] = min(dis[nxt], dis[v] + 1);
            for (int i = 0; i < n; ++i) {
                int j = (i + dis[v]) % n;
                dis[j] = min(dis[j], dis[v] + a[v][i]);
            }
        }
        dis[i] = 0;
        printv(all(dis));
    }
}