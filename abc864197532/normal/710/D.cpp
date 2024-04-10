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

ll phi(ll a) {
    ll ans = a;
    for (int i = 2; i * i <= a; ++i) if (a % i == 0) {
        ans -= ans / i;
        while (a % i == 0)
            a /= i;
    }
    if (a > 1)
        ans -= ans / a;
    return ans;
}

ll modpow(ll a, ll b, ll m) {
    if (!a)
        return 0;
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % m)
        if (b & 1)
            ans = ans * a % m;
    return ans;
}

void solve() {
    // a1X + b1 = a2Y + b2
    // a1X - a2Y = b2 - b1
    ll a1, b1, a2, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R, --L;
    ll x = b2 - b1, g = __gcd(a1, a2);
    if (x % g) {
        cout << 0 << '\n';
        return;
    }
    x /= g;
    ll a = a1 / g, b = a2 / g;
    // aX - bY = x
    // X >= 0, Y >= 0
    // X = (x + bY) / a
    ll r = (-(x % a) + a) % a;
    ll resy = r * modpow(b % a, phi(a) - 1, a) % a;
    assert((x + b * resy) % a == 0);
    ll resx = (x + b * resy) / a;
    // y += a, x += b
    if (resx < 0) {
        // res + bk >= 0
        ll round = (-resx + b - 1) / b;
        resx += round * b, resy += round * a;
    }
    // resx, resx + b, ...
    // a1 * resx + b1 <= n
    auto f = [&](ll n) {
        // resx <= (n - b1) / a1;
        ll bound = (n - b1 >= 0 ? (n - b1) / a1 : (n - b1 - a1 + 1) / a1);
        // res <= x <= bound
        ll len = bound - resx;
        if (len < 0)
            return 0ll;
        return len / b + 1;
    };
    cout << f(R) - f(L) << '\n';
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}