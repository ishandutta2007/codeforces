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
const int mod = 998244353, N = 200005, logN = 20, K = 111;

int main () {
    owo;
    int n, q, mod;
    cin >> n >> q >> mod;
    vector <int> a(n + 2), fib(n + 3);
    fib[1] = fib[2] = 1;
    for (int i = 3; i < n + 3; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] >= mod)
            fib[i] -= mod;
    }
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[i] -= x;
        if (a[i] < 0)
            a[i] += mod;
    }
    for (int i = n + 1; i >= 2; --i) {
        a[i] -= a[i - 2];
        if (a[i] < 0)
            a[i] += mod;
        a[i] -= a[i - 1];
        if (a[i] < 0)
            a[i] += mod;
    }
    a[1] -= a[0];
    if (a[1] < 0)
        a[1] += mod;
    int cnt = 0;
    for (int i = 0; i < n + 2; ++i) 
        cnt += a[i] == 0;
    auto add = [&](int i, int v) {
        if (v < 0)
            v += mod;
        cnt -= a[i] == 0;
        a[i] += v;
        if (a[i] >= mod)
            a[i] -= mod;
        cnt += a[i] == 0;
    };
    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r, --l;
        // fib1 fib2 fib3 ... fiblen
        // fib1 0 0 0 0 0 0 0 0 -fib{len + 1} -fib{len}
        int len = r - l;
        add(l, 1 * (c == 'A' ? 1 : -1));
        add(r, -fib[len + 1] * (c == 'A' ? 1 : -1));
        add(r + 1, -fib[len] * (c == 'A' ? 1 : -1));
        cout << (cnt == n + 2 ? "YES\n" : "NO\n");
    }
}