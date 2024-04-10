#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; ++i)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define mp make_pair
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int P = 998244353;

int mpow(ll b, ll e) { 
    ll r = 1;
    while (e) {
        if (e & 1) {
            r *= b;
            r %= P;
        }
        b *= b;
        b %= P;
        e >>= 1;
    }
    return r;
}
int minv(int x) { return mpow(x, P - 2); }
int add(int x, int y) { x += y; if (x >= P) x -= P; return x; }
int mult(int x, int y) { return 1LL * x * y % P; }
int madd(int& x, int y) { return x = add(x, y); }
int mmult(int& x, int y) { return x = mult(x, y); }
int mdiv(int &x, int y) { return x = mult(x, minv(y)); }

const int N = 2e5 + 5;

int fact[N], ifact[N];

int C(int x, int y) { 
    if (x < y) return 0;
    if (y < 0) return 0;
    return mult(fact[x], mult(ifact[y], ifact[x - y]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    f1r(i, 1, N) fact[i] = mult(fact[i - 1], i);
    ifact[N - 1] = minv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) ifact[i] = mult(ifact[i + 1], (i + 1));
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi b(2);
    vi q(2);
    f0r(i, n) {
        if (s[i] == 'b') {
            b[i % 2]++;
        } else if (s[i] == '?') {
            q[i % 2]++;
        }
    }
    int i2 = minv(2);
    int ans = i2;
    ans = 1;
    f0r(i, q[0] + q[1]) mmult(ans, i2); 
    // cout << b[0] << " b " << b[1] << endl;
    // cout << q[0] << " q " << q[1] << endl;
    // cout << ans << endl;
    int res = 0;
    for (int i = -q[0]; i <= q[1]; i++) {
        if ((i + b[0] + b[1]) % 2 != 0) continue;
        madd(res, mult(C(q[0] + q[1], q[0] + i), abs(i + b[1] - b[0])));
        // cout << i << "  " <<  C(q[0] + q[1], q[0] + i) << " " << abs(i + b[1] - b[0]) << endl;
    }
    mmult(ans, res);
    cout << ans << '\n';




    return 0;
}
/**
 * abs(black on even - black on odd)
 */