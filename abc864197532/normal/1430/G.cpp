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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000001, logN = 20, K = 111;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <int> ord, adj(n), deg(n), radj(n);
    vector <int> weight(n);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u] |= 1 << v;
        radj[v] |= 1 << u;
        weight[u] -= w;
        weight[v] += w;
        deg[v]++;
    }
    queue <int> q;
    int t = 0;
    for (int i = 0; i < n; ++i) if (!deg[i]) {
        q.push(i);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        ord.pb(v);
        for (int i = 0; i < n; ++i) if (adj[v] >> i & 1) {
            deg[i]--;
            if (!deg[i])
                q.push(i);
        }
    }
    reverse(all(ord));
    vv <int> dp(n * n + 1, 1 << n, 1 << 30);
    dp[0][0] = 0;
    for (int num = 0; num < n; ++num) {
        for (int i = 0; i < n; ++i) {
            int v = ord[i];
            for (int s = 0; s < 1 << n; ++s) {
                dp[num * n + i + 1][s] = min(dp[num * n + i + 1][s], dp[num * n + i][s]);
                if (s >> v & 1)
                    continue;
                if ((radj[v] & s) == radj[v]) {
                    dp[num * n + i + 1][s ^ (1 << v)] = min(dp[num * n + i + 1][s ^ (1 << v)], dp[num * n + i][s] + weight[v] * num);
                }
            }
        }
    }
    vector <int> ans(n, -1);
    int s = (1 << n) - 1;
    for (int num = n - 1; ~num; --num) {
        for (int i = n - 1; ~i; --i) {
            int v = ord[i];
            if (~s >> v & 1)
                continue;
            if (dp[num * n + i + 1][s] == dp[num * n + i][s ^ (1 << v)] + weight[v] * num) {
                ans[v] = n - num;
                s ^= (1 << v);
            }
        }
    }
    printv(all(ans));
}