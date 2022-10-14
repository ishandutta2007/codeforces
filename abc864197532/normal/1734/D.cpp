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
const int mod = 1e9 + 7, N = 1 << 19, C = 1e7 + 5;

void solve() {
    int n, k;
    cin >> n >> k, --k;
    vector <ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int _ : {0, 1}) {
        ll now = 0, mn = 0;
        map <ll, ll> m1;
        m1[mn] = now;
        for (int i = k + 1; i < n; ++i) {
            now += a[i]; mn = min(mn, now);
            if (!m1.count(mn))
                m1[mn] = now;
            else
                m1[mn] = max(m1[mn], now);
        }
        for (auto it = prev(m1.end()); ; --it) {
            if (next(it) != m1.end()) {
                it->Y = max(next(it)->Y, it->Y);
            }
            if (it == m1.begin())
                break;
        }
        for (auto [x, y] : m1)
            test(x, y);
        now = a[k];
        bool is = true;
        ll cur = now;
        for (int i = k - 1; ~i; --i) {
            cur = max(cur, now);
            auto it = m1.lower_bound(-cur);
            ll cur = now + it->Y;
            if (cur + a[i] < 0) {
                is = false;
            }
            now += a[i];
        }
        if (is) {
            cout << "YES\n";
            return;
        }
        reverse(all(a)), k = n - 1 - k;
    }
    cout << "NO\n";
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}