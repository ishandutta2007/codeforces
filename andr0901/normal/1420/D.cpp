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

const int MOD = 998244353;

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

vector <int> f, inv_f;

int c(int n, int k) {
    if (n < k)
        return 0;
    return mul(f[n], mul(inv_f[k], inv_f[n - k]));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    f.resize(n + 1), inv_f.resize(n + 1);
    f[0] = inv_f[0] = 1;
    forn (i, 1, sz(f)) {
        f[i] = mul(f[i - 1], i);
        inv_f[i] = inv(f[i]);
    }
    map <int, int> beginnigs;
    map <int, int> endings;
    set <int> events;
    forn (i, 0, n) {
        int l, r;
        cin >> l >> r;
        beginnigs[l]++, endings[r]++;   
        events.insert(l), events.insert(r);
    }
    int ans = 0;
    int open = 0;
    for (int x : events) {
        open += beginnigs[x];
        ans = add(ans, sub(c(open, k), c(open - beginnigs[x], k)));
        open -= endings[x];
    }
    cout << ans;
    return 0;
}