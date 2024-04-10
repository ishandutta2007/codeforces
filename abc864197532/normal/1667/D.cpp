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
const int mod = 998244353, N = 200001, logN = 20, K = 111, M = 4e7;

vector <int> adj[N];
bool dp[N][2];

void dfs1(int v, int pa) {
    vector <int> cnt(4, 0);
    int ch = 0;
    for (int u : adj[v]) if (u != pa) {
        dfs1(u, v);
        cnt[dp[u][0] | dp[u][1] << 1]++;
        ch++;
    }
    int d = int(adj[v].size()) & 1;
    // d = 1 -> start 0
    // d = 0 -> start 1
    {
        int need0 = ch >> 1, need1 = ch - need0;
        if (d)
            swap(need0, need1);
        if (cnt[1] <= need0 && cnt[2] <= need1 && !cnt[0])
            dp[v][0] = true;
    }
    if (ch) {
        int need0 = ch - 1 >> 1, need1 = ch - 1 - need0;
        if (d)
            swap(need0, need1);
        if (cnt[1] && cnt[1] - 1 <= need0 && cnt[2] <= need1 && !cnt[0])
            dp[v][1] = true;
        if (cnt[3] && cnt[1] <= need0 && cnt[2] <= need1 && !cnt[0])
            dp[v][1] = true;
    }
}

vector <pii> ans;
int pt[N];

void dfs2(int v, int pa, int f) {
    vector <vector <int>> pos(4);
    int ch = 0;
    for (int u : adj[v]) if (u != pa) {
        pos[dp[u][0] | dp[u][1] << 1].pb(u);
        ch++;
    }
    int d = int(adj[v].size()) & 1 ^ 1;
    // d = 1 -> start 0
    // d = 0 -> start 1
    if (!f) {
        int need0 = ch >> 1, need1 = ch - need0;
        if (!d)
            swap(need0, need1);
        while (!pos[1].empty() || !pos[2].empty() || !pos[3].empty()) {
            int x = d ? 2 : 1;
            int u;
            if (!pos[x].empty()) {
                u = pos[x].back(), pos[x].pop_back();
            } else {
                u = pos[3].back(), pos[3].pop_back();
            }
            dfs2(u, v, d);
            if (d)
                ans.eb(u, v), ans.eb(u, pt[u]);
            else
                ans.eb(u, v);
            d ^= 1;
        }
    } else {
        int need0 = ch - 1 >> 1, need1 = ch - 1 - need0;
        if (!d)
            swap(need0, need1);
        if (!pos[1].empty())
            pt[v] = pos[1].back(), pos[1].pop_back();
        else
            pt[v] = pos[3].back(), pos[3].pop_back();
        dfs2(pt[v], v, 0);
        while (!pos[1].empty() || !pos[2].empty() || !pos[3].empty()) {
            int x = d ? 2 : 1;
            int u;
            if (!pos[x].empty()) {
                u = pos[x].back(), pos[x].pop_back();
            } else {
                u = pos[3].back(), pos[3].pop_back();
            }
            dfs2(u, v, d);
            if (d)
                ans.eb(u, v), ans.eb(u, pt[u]);
            else
                ans.eb(u, v);
            d ^= 1;
        }
    }
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0, u, v; i < n - 1; ++i) {
            cin >> u >> v, --u, --v;
            adj[u].pb(v), adj[v].pb(u);
        }
        dfs1(0, -1);
        if (dp[0][0]) {
            cout << "YES\n";
            dfs2(0, -1, 0);
            for (auto [u, v] : ans)
                cout << ++u << ' ' << ++v << '\n';
        } else {
            cout << "NO\n";
        }
        for (int i = 0; i < n; ++i)
            adj[i].clear(), dp[i][0] = dp[i][1] = false;
        ans.clear();
    }
}