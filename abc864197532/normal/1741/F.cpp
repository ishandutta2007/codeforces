#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 20, K = 250;

void solve() {
    int n;
    cin >> n;
    vector <int> l(n), r(n), c(n);
    vector <vector <int>> bucket(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> l[i] >> r[i] >> c[i], --c[i];
        bucket[c[i]].pb(i);
    }
    vector <int> col_mx(n);
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return mp(l[i], r[i]) < mp(l[j], r[j]);
    });
    vector <int> ans(n, 1 << 30);
    set <pii, greater <pii>> SS;
    for (int i : p) {
        for (auto it = SS.begin(); it != SS.end(); ++it) {
            if (it->Y == c[i])
                continue;
            if (r[i] <= it->X)
                ans[i] = 0;
            break;
        }
        if (col_mx[c[i]] < r[i]) {
            SS.erase({col_mx[c[i]], c[i]});
            col_mx[c[i]] = r[i];
            SS.insert({col_mx[c[i]], c[i]});
        }
    }
    multiset <pii> S, Sinv;
    for (int i = 0; i < n; ++i)
        S.insert({l[i], r[i]}), Sinv.insert({r[i], l[i]});
    for (int i = 0; i < n; ++i) {
        for (int id : bucket[i]) {
            S.erase(S.lower_bound({l[id], r[id]}));
            Sinv.erase(Sinv.lower_bound({r[id], l[id]}));
        }
        for (int id : bucket[i]) {
            int tans = ans[id];
            {
                auto it = S.lower_bound({l[id], -1});
                if (it != S.end()) {
                    if (it->X <= r[id]) {
                        tans = 0;
                    } else {
                        tans = min(tans, it->X - r[id]);
                    }
                }
            }
            {
                auto it = Sinv.lower_bound({r[id], 1 << 30});
                if (it != Sinv.begin()) {
                    --it;
                    if (l[id] <= it->X) {
                        tans = 0;
                    } else {
                        tans = min(tans, l[id] - it->X);
                    }
                }
            }
            ans[id] = tans;
        }
        for (int id : bucket[i]) {
            S.insert({l[id], r[id]});
            Sinv.insert({r[id], l[id]});
        }
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}