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
const int mod = 1e9 + 7, N = 200010, logN = 17, M = N * 40;

struct edge {
    int u, v, w;
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector <int> dsu(n * 2);
        iota(all(dsu), 0);
        function <int(int)> Find = [&](int x) {
            if (dsu[x] == x)
                return x;
            return dsu[x] = Find(dsu[x]);
        };
        vector <edge> E;
        for (int i = 0, u, v, w; i < n - 1; ++i) {
            cin >> u >> v >> w, --u, --v;
            E.pb({u, v, w});
            if (w != -1) {
                w = __builtin_popcount(w) & 1;
                if (w) {
                    dsu[Find(u + n)] = Find(v);
                    dsu[Find(u)] = Find(v + n);
                } else {
                    dsu[Find(u)] = Find(v);
                    dsu[Find(u + n)] = Find(v + n);
                }
            }
        }
        while (q--) {
            int u, v, w;
            cin >> u >> v >> w, --u, --v;
            if (w) {
                dsu[Find(u + n)] = Find(v);
                dsu[Find(u)] = Find(v + n);
            } else {
                dsu[Find(u)] = Find(v);
                dsu[Find(u + n)] = Find(v + n);
            }
        }
        bool fail = false;
        for (int i = 0; i < n; ++i) {
            if (Find(i) == Find(i + n))
                fail = true;
        }
        if (fail) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector <int> dep(n);
            dep[0] = 0;
            for (int i = 1; i < n; ++i) {
                if (Find(i) != Find(0) && Find(i + n) != Find(0)) {
                    dsu[Find(i)] = Find(0);
                    dsu[Find(i + n)] = Find(n);
                }
            }
            for (int i = 1; i < n; ++i) {
                if (Find(i) == Find(0))
                    dep[i] = 0;
                else if (Find(i + n) == Find(0))
                    dep[i] = 1;
                else
                    assert(false);
            }
            for (auto e : E) {
                if (e.w == -1) {
                    e.w = dep[e.u] ^ dep[e.v];
                }
                cout << e.u + 1 << ' ' << e.v + 1 << ' ' << e.w << endl;
            }
        }
    }
}