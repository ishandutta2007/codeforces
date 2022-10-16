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

const int P = 1e9 + 7;


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
int inv(ll x) { return mpow(x, P - 2); }
int add(int x, int y) { x += y; if (x >= P) x -= P; return x; }
int madd(int& x, int y) { return x = add(x, y); }
int mult(int x, int y) { return 1LL * x * y % P; }
int mmult(int& x, int y) { return x = mult(x, y); }

const int N = 1e5 + 5;

int fact[N], ifact[N];

int C(int x, int y) {
    if (x < y) return 0;
    return mult(fact[x], mult(ifact[y], ifact[x - y]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    f1r(i, 1, N) fact[i] = mult(fact[i - 1], i);
    ifact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) ifact[i] = mult(ifact[i + 1], i + 1);
    int n; cin >> n;
    vl a(n);
    ll sum = 0;
    f0r(i, n) cin >> a[i], sum += a[i];
    if (sum % n != 0) {
        cout << 0 << '\n';
        return 0;
    }
    ll avg = sum / n;
    int mul = 1;
    map<int, int> cnt;
    each(x, a) cnt[x]++;
    each(x, cnt) mmult(mul, ifact[x.s]);
    int ans = 1;
    int eq = 0;
    int le = 0;
    int ge = 0;
    f0r(i, n) {
        if (a[i] > avg) ge++;
        else if (a[i] < avg) le++;
        else eq++;
    }

    mmult(ans, C(n, eq));
    mmult(ans, mul);
    mmult(ans, fact[eq]);
    mmult(ans, fact[ge]);
    mmult(ans, fact[le]);
    int x = le;
    int y = ge;
    if (x > y) swap(x, y);
    if (x && y) {
        if (x == 1) {
            mmult(ans, x + y);
        } else {
            mmult(ans, 2);
        }
    }
    cout << ans << '\n';

    return 0;
}