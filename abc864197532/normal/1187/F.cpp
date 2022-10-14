#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 300087, K = 111;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int inter(vector <int> l, vector <int> r) {
    int ll = *max_element(all(l)), rr = *min_element(all(r));
    if (ll <= rr) return rr - ll + 1;
    return 0;
}

void add(lli &a, lli b) {
    a += b;
    if (a >= mod) a -= mod;
}

void del(lli &a, lli b) {
    a -= b;
    if (a < 0) a += mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> l(n), r(n), sz(n), inv(n);
    for (int i = 0; i < n; ++i) cin >> l[i];
    lli al = 1;
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        sz[i] = r[i] - l[i] + 1;
        al = al * sz[i] % mod;
        inv[i] = modpow(sz[i], mod - 2);
    }
    lli square = 0, sum = 0;
    for (int i = 0; i + 1 < n; ++i) {
        add(sum, inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) * al % mod * inv[i] % mod * inv[i + 1] % mod);
    }
    square = sum;
    for (int i = 0; i + 2 < n; ++i) {
        add(square, inter({l[i], l[i + 1], l[i + 2]}, {r[i], r[i + 1], r[i + 2]}) * al % mod * inv[i] % mod * inv[i + 1] % mod * inv[i + 2] % mod * 2 % mod);
    }
    lli now = 0;
    for (int i = 0; i + 1 < n; ++i) add(now, 1ll * inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) * inv[i] % mod * inv[i + 1] % mod);
    for (int i = 0; i + 1 < n; ++i) {
        if (i - 1 >= 0) del(now, 1ll * inter({l[i - 1], l[i]}, {r[i - 1], r[i]}) * inv[i - 1] % mod * inv[i] % mod);
        del(now, 1ll * inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) * inv[i] % mod * inv[i + 1] % mod);
        if (i + 2 < n) del(now, 1ll * inter({l[i + 1], l[i + 2]}, {r[i + 1], r[i + 2]}) * inv[i + 1] % mod * inv[i + 2] % mod);
        add(square, now * inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) % mod * inv[i] % mod * inv[i + 1] % mod * al % mod);
        if (i - 1 >= 0) add(now, 1ll * inter({l[i - 1], l[i]}, {r[i - 1], r[i]}) * inv[i - 1] % mod * inv[i] % mod);
        add(now, 1ll * inter({l[i], l[i + 1]}, {r[i], r[i + 1]}) * inv[i] % mod * inv[i + 1] % mod);
        if (i + 2 < n) add(now, 1ll * inter({l[i + 1], l[i + 2]}, {r[i + 1], r[i + 2]}) * inv[i + 1] % mod * inv[i + 2] % mod);
    }
    cout << ((square + mod - sum * n * 2 % mod) * modpow(al, mod - 2) + 1ll * n * n) % mod;
}