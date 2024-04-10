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
const int mod = 998244353, N = 100002, M = 150000, logN = 20, K = 1000;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int lp[N], mu[N];

void build() {
    vector <int> p;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            p.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; 1ll * p[j] * i < N; ++j) {
            lp[p[j] * i] = p[j];
            if (i % p[j] == 0) break;
        }
    }
    mu[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (lp[i] == lp[i / lp[i]]) mu[i] = 0;
        else mu[i] = mu[i / lp[i]] * -1;
    }
}

void solve() {
    int n;
    cin >> n;
    vector <vector <int>> adj(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    auto chk = [&](int k) {
        vector <int> in(n, 0);
        vector <bool> out(n, false);
        queue <int> q;
        for (int i = 0; i < n; ++i) {
            in[i] = adj[i].size();
            if (in[i] == 1) q.push(i);
        }
        vector <int> cur(n, 0);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            out[v] = true;
            int u = -1;
            for (int ii : adj[v]) if (!out[ii]) {
                u = ii;
                in[u]--;
                if (in[u] == 1) q.push(u);
            }
            if (u == -1) break;
            if (cur[v] % k == 0) cur[u]++;
            else if ((cur[v] + 1) % k == 0) cur[v]++;
            else return false;
        }
        return true;
    };
    vector <lli> ans(n + 1, 0);
    ans[1] = modpow(2, n - 1);
    for (int i = 2; i <= n; ++i) if ((n - 1) % i == 0) {
        if (chk(i)) ans[i]++;
    }
    for (int i = 1; i <= n; ++i) {
        lli cur_ans = 0;
        for (int j = 1; j * i <+ n; ++j) {
            (cur_ans += ans[i * j] * mu[j]) % mod;
        }
        if (cur_ans < 0) cur_ans += mod;
        cout << cur_ans << ' ';
    }
    cout << endl;
}

int main () {
    owo;
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}