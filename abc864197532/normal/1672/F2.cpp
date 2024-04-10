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
const int mod = 998244353, N = 1000005, logN = 20, K = 111, M = 4e7, C = 350;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> p(n), qq(n), cnt(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i], p[i]--, cnt[p[i]]++;
        for (int i = 0; i < n; ++i)
            cin >> qq[i], qq[i]--;
        int mx = max_element(all(cnt)) - cnt.begin();
        vector <vector <int>> adj(n);
        vector <int> in(n);
        auto add_edge = [&](int u, int v) {
            if (u == mx || v == mx)
                return;
            adj[u].pb(v);
            in[v]++;
        };
        for (int i = 0; i < n; ++i)
            add_edge(p[i], qq[i]);
        queue <int> q;
        for (int i = 0; i < n; ++i) if (!in[i])
            q.push(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : adj[v]) {
                in[u]--;
                if (!in[u])
                    q.push(u);
            }
        }
        cout << (accumulate(all(in), 0) ? "WA\n" : "AC\n");
    }
}