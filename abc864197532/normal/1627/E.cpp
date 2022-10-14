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
const int mod = 1e9 + 7, N = 1000087, logN = 20, K = 48763;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector <int> x(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        map <pii, int> pt;
        vector <vector <pair <int, int>>> adj(k * 2 + 2);
        int _id = 0;
        auto get = [&](int a, int b) {
            if (!pt.count({a, b}))
                return pt[{a, b}] = _id++;
            return pt[{a, b}];
        };
        get(0, 0), get(n - 1, m - 1);
        for (int i = 0, a, b, c, d, h; i < k; ++i) {
            cin >> a >> b >> c >> d >> h, --a, --b, --c, --d;
            adj[get(a, b)].eb(get(c, d), h);
        }
        vector <lli> dp(_id, 1ll << 60);
        dp[get(0, 0)] = 0;
        for (int i = 0; i < n; ++i) {
            test(i);
            vector <pii> cur;
            for (auto it = pt.lower_bound({i, -1}); it != pt.end() && it->X.X == i; ++it)
                cur.pb(mp(it->X.Y, it->Y));
            for (int t : {0, 1}) {
                lli pre = 1ll << 60, prew = 0;
                for (auto [u, w] : cur) {
                    dp[w] = min(dp[w], pre + abs(u - prew) * x[i]);
                    tie(pre, prew) = mp(dp[w], u);
                }
                reverse(all(cur));
            }
            for (auto [u, w] : cur) {
                for (auto [v, w1] : adj[w]) if (dp[w] < 1ll << 60) {
                    dp[v] = min(dp[v], dp[w] - w1);
                }
            }
        }
        lli xx = dp[get(n - 1, m - 1)];
        if (xx == 1ll << 60)
            cout << "NO ESCAPE\n";
        else
            cout << xx << endl;
    }
}