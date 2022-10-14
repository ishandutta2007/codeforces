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
const int mod = 1e9 + 7, N = 1002, logN = 20, K = 600, M = 1e9 + 1;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
         int n, k;
         cin >> n >> k;
         vector <vector <int>> adj(n);
         queue <int> q;
         vector <int> dis1(n, -1), dis2(n, -1);
         for (int i = 0, x; i < k; ++i) {
            cin >> x, --x;
            q.push(x), dis1[x] = 0;
         }
         for (int i = 0, u, v; i < n - 1; ++i) {
            cin >> u >> v, --u, --v;
            adj[u].pb(v), adj[v].pb(u);
         }
         while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : adj[v]) if (dis1[u] == -1) {
                dis1[u] = dis1[v] + 1;
                q.push(u);
            }
         }
         dis2[0] = 0;
         q.push(0);
         while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : adj[v]) if (dis2[u] == -1) {
                dis2[u] = dis2[v] + 1;
                q.push(u);
            }
         }
         bool ans = false;
         for (int i = 1; i < n; ++i) if (adj[i].size() == 1) {
            ans |= dis1[i] > dis2[i];
         }
         cout << (ans ? "YES\n" : "NO\n");
    }
}