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
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300001, logN = 20, K = 111;

int dsu[N];

int Find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = Find(dsu[x]);
}

int main () {
    owo;
    int n, m, k;
    cin >> n >> m >> k;
    iota(dsu, dsu + k, 0);
    vector <vector <int>> adj1(k), adj2(k);
    vector <int> deg(k, 0);
    bool flag = false;
    for (int i = 0, sz; i < n; ++i) {
        cin >> sz;
        flag |= sz > 1;
        vector <int> in(sz);
        for (int j = 0; j < sz; ++j) {
            cin >> in[j], in[j]--;
            if (j) {
                adj1[in[j - 1]].pb(in[j]), adj2[in[j]].pb(in[j - 1]);
                dsu[Find(in[j - 1])] = Find(in[j]);
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        sort(all(adj1[i])), sort(all(adj2[i]));
        adj1[i].resize(unique(all(adj1[i])) - adj1[i].begin());
        adj2[i].resize(unique(all(adj2[i])) - adj2[i].begin());
        deg[i] = adj2[i].size();
    }
    vector <bool> dead(k, false);
    for (int i = 0; i < k; ++i) if (adj1[i].size() >= 2 || adj2[i].size() >= 2)
        dead[i] = true;
    queue <pii> q;
    vector <vector <int>> ord(k);
    for (int i = 0; i < k; ++i) if (!deg[i] && !dead[i])
        q.emplace(i, i);
    while (!q.empty()) {
        int v, rt;
        tie(v, rt) = q.front(); q.pop();
        ord[rt].pb(v);
        for (int u : adj1[v]) {
            deg[u]--;
            if (!deg[u] && !dead[u])
                q.emplace(u, rt);
        }
    }
    for (int i = 0; i < k; ++i) if (deg[i] || dead[i])
        dead[i] = true, dead[Find(i)] = true;
    for (int i = 0; i < k; ++i) if (dead[Find(i)])
        dead[i] = true;
    vector <int> cnt(k + 1, 0);
    for (int i = 0; i < k; ++i) if (!ord[i].empty()) {
        bool is = false;
        for (int j : ord[i])
            is |= dead[j];
        if (!is)
            cnt[ord[i].size()]++;
    }
    vector <pii> item;
    for (int i = 1; i <= k; ++i) if (cnt[i])
        item.eb(i, cnt[i]);
    vector <int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (pii A : item) if (i - A.X >= 0) {
            dp[i] += 1ll * dp[i - A.X] * A.Y % mod;
            if (dp[i] >= mod) dp[i] -= mod;
        }
    }
    cout << dp[m] << endl;
}