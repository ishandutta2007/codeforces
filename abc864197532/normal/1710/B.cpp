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
const int mod = 998244353, N = 200005;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> x(n), p(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> p[i];
    vector <int> v = x;
    sort(all(v)), v.resize(unique(all(v)) - v.begin());
    int sz = v.size();
    vector <lli> lz1(sz + 1, 0), lz2(sz + 1, 0);
    for (int i = 0; i < n; ++i) {
        {
            int l = lower_bound(all(v), x[i]) - v.begin();
            int r = lower_bound(all(v), x[i] + p[i]) - v.begin();
            lz1[l] += p[i] + x[i], lz1[r] -= p[i] + x[i];
            lz2[l]--, lz2[r]++;
        }
        {
            int l = upper_bound(all(v), x[i] - p[i]) - v.begin();
            int r = lower_bound(all(v), x[i]) - v.begin();
            lz1[l] += p[i] - x[i], lz1[r] -= p[i] - x[i];
            lz2[l]++, lz2[r]--;
        }
    }
    for (int i = 0; i < sz; ++i)
        lz1[i + 1] += lz1[i], lz2[i + 1] += lz2[i];
    vector <lli> val(sz);
    for (int i = 0; i < sz; ++i)
        val[i] = max(lz1[i] + lz2[i] * v[i] - m, 0ll);
    set <pair <lli, int>> Sl, Sr;
    for (int i = 0; i < sz; ++i) if (val[i]) {
        Sr.insert({val[i] + v[i], i});
    }
    vector <vector <int>> id(sz);
    for (int i = 0; i < n; ++i) {
        id[lower_bound(all(v), x[i]) - v.begin()].pb(i);
    }
    string ans(n, '0');
    for (int now = 0; now < sz; ++now) {
        if (val[now])
            Sr.erase({val[now] + v[now], now});
        for (int i : id[now]) {
            bool ok = true;
            if (!Sl.empty() && prev(Sl.end())->X > p[i] - x[i])
                ok = false;
            if (!Sr.empty() && prev(Sr.end())->X > p[i] + x[i])
                ok = false;
            if (val[now] - p[i] > 0)
                ok = false;
            if (ok)
                ans[i] = '1';
        }
        if (val[now])
            Sl.insert({val[now] - v[now], now});
    }
    cout << ans << '\n';
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}