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
const int mod = 998244353, N = 3005, logN = 20, K = 111, C = 1e9;

vector <int> adj[N];
bool vis[N];
vector <int> ord;

void dfs(int v) {
    vis[v] = true;
    ord.pb(v);
    for (int u : adj[v]) if (!vis[u])
        dfs(u);
}

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 0, u, v; i < n * 2; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        dfs(i);
        int m = ord.size();
        for (int i = 1; i < m; i += 2)
            ord[i] -= n;
        // all
        {
            int mn[2] = {ord[0], ord[1]}, mx[2] = {ord[0], ord[1]};
            for (int i = 2; i < m; ++i) {
                mn[i & 1] = min(mn[i & 1], ord[i]);
                mx[i & 1] = max(mx[i & 1], ord[i]);
            }
            lli first_way = 1ll * (mn[0] + 1) * (n - mx[0]);
            lli second_way = 1ll * (mn[1] + 1) * (n - mx[1]);
            ans += 1ll * first_way * second_way * (m / 2);
        }
        for (int i = 0; i < m; ++i) {
            int mn[2] = {ord[i], ord[(i + 1) % m]}, mx[2] = {ord[i], ord[(i + 1) % m]};
            if (i & 1)
                swap(mn[0], mn[1]), swap(mx[0], mx[1]);
            auto valid = [&](int dead) {
                return ord[dead] < mn[dead & 1] || mx[dead & 1] < ord[dead];
            };
            for (int len = 2; len < m; ++len) {
                // calc answer
                int first1 = -1, first2 = n;
                int second1 = -1, second2 = n;
                auto upd = [&](int dead) {
                    if (dead & 1) {
                        if (ord[dead] < mn[1])
                            second1 = max(second1, ord[dead]);
                        else
                            second2 = min(second2, ord[dead]);
                    } else {
                        if (ord[dead] < mn[0])
                            first1 = max(first1, ord[dead]);
                        else
                            first2 = min(first2, ord[dead]);
                    }
                };
                int dead1 = (i + m - 1) % m, dead2 = (i + len) % m;
                if (valid(dead1) && valid(dead2)) {
                    upd(dead1), upd(dead2);
                    lli first_way = 1ll * (mn[0] - first1) * (first2 - mx[0]);
                    lli second_way = 1ll * (mn[1] - second1) * (second2 - mx[1]);
                    ans += 1ll * first_way * second_way * (len / 2);
                }
                // update
                int now = (i + len) % m;
                mn[now & 1] = min(mn[now & 1], ord[now]);
                mx[now & 1] = max(mx[now & 1], ord[now]);
            }
        }
        ord.clear();
    }
    cout << ans << '\n';
}