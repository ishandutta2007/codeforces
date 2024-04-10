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
const int mod = 998244353, N = 300005;

int lcm(int i, int j) {
    return i * j / __gcd(i, j);
}

void solve () {
    // 3 4 6
    // 6 10 15
    // lcm(i, j, k) = k
    int l, r;
    cin >> l >> r;
    ll ans = 0;
    for (int x = 1; x * 6 <= r; ++x) {
        if (l <= x * 3 && x * 6 <= r)
            ans++;
    }
    for (int x = 1; x * 15 <= r; ++x) {
        if (l <= x * 6 && x * 15 <= r)
            ans++;
    }
    vector <ll> val(r + 1, 0);
    for (int i = l; i <= r; ++i)
        val[i]++;
    for (int i = r; i; --i) {
        for (int j = i + i; j <= r; j += i)
            val[j] += val[i];
    }
    for (int c = l + 2; c <= r; ++c) {
        ans += (val[c] - 2) * (val[c] - 1) / 2;
    }
    ll len = r - l + 1;
    cout << len * (len - 1) * (len - 2) / 6 - ans << '\n';
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}