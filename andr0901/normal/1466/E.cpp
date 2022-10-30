//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

constexpr int BITS = 61;

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    int t = bin_pow(a, p / 2);
    return (1LL * t * t) % MOD;
}

int inv(int x) {
    return bin_pow(x, MOD - 2);
}

vector<int> p;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    cin >> a;
    vector<int> cnt(BITS);
    forn (i, 0, n)
        forn (j, 0, BITS)
            if ((a[i] >> j) & 1)
                cnt[j]++;
    int ans = 0;
    forn (j, 0, n) {
        int s = 0;
        forn (bit, 0, BITS) {
            if ((a[j] >> bit) & 1)
                s = add(s, mul(n, p[bit]));
            else
                s = add(s, mul(cnt[bit], p[bit]));
        }
        int t = 0;
        forn (bit, 0, BITS) {
            if ((a[j] >> bit) & 1)
                t = add(t, mul(cnt[bit], p[bit]));
        }
        ans = add(ans, mul(s, t));
        // int s = 0;
        // forn (k, 0, n)
        //     s += (a[j] | a[k]);
        // forn (i, 0, n)
        //     ans += s * (a[i] & a[j]);
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    p.resize(BITS);
    p[0] = 1;
    forn (i, 1, BITS)
        p[i] = mul(p[i - 1], 2);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}