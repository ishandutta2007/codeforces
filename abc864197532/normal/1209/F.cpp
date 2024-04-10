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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    if (a.empty())
        return o << "{}";
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
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 1100005, logN = 18;

vector <int> adj[N][10];

int main () {
    owo;
    int n, m, _id;
    cin >> n >> m;
    _id = n;
    string s;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v, --u, --v;
        s = to_string(i);
        {
            int pre = u;
            for (int j = 0; j + 1 < s.length(); ++j) {
                adj[pre][s[j] - '0'].pb(_id);
                pre = _id++;
            }
            adj[pre][s.back() - '0'].pb(v);
        }
        {
            int pre = v;
            for (int j = 0; j + 1 < s.length(); ++j) {
                adj[pre][s[j] - '0'].pb(_id);
                pre = _id++;
            }
            adj[pre][s.back() - '0'].pb(u);
        }
    }
    vector <int> ans(_id, -1);
    ans[0] = 0;
    queue <vector <int>> q;
    q.push({0});
    while (!q.empty()) {
        vector <int> vec = q.front(); q.pop();
        for (int w = 0; w < 10; ++w) {
            vector <int> tmp;
            for (int v : vec) {
                for (int u : adj[v][w]) if (ans[u] == -1) {
                    ans[u] = (1ll * ans[v] * 10 + w) % mod;
                    tmp.pb(u);
                }
            }
            if (!tmp.empty())
                q.push(tmp);
        }
    }
    for (int i = 1; i < n; ++i)
        cout << ans[i] << '\n';
}