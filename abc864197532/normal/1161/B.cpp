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
const int mod = 998244353, N = 401, logN = 20, K = 111, C = 7;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <pii> E;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        if (u > v)
            swap(u, v);
        E.eb(u, v);
    }
    auto chk = [&](int k) {
        if (k == n)
            return false;
        vector <pii> now;
        for (auto [u, v] : E) {
            u += k, v += k;
            if (u >= n)
                u -= n;
            if (v >= n)
                v -= n;
            if (u > v)
                swap(u, v);
            now.eb(u, v);
        }
        sort(all(now));
        return now == E;
    };
    sort(all(E));
    for (int k = 1; k * k <= n; ++k) if (n % k == 0) {
        if (chk(k) || chk(n / k))
            return cout << "YES\n", 0;
    }
    cout << "NO\n";
}