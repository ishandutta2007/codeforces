#pragma GCC optimize("Ofast")
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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <long long> primes;

void get_primes(long long x) {
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            primes.pb(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        primes.pb(x);
}

int m;

void get(long long x, vector <int>& ans) {
    ans.resize(m);
    forn (i, 0, m) {
        while (x % primes[i] == 0) {
            ans[i]++;
            x /= primes[i];
        }
    }
}

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

int solve(vector <int>& a, vector <int>& b) {
    vector <int> diff(m);
    int s = 0;
    forn (i, 0, m) {
        diff[i] = a[i] - b[i];
        s += diff[i];
    }
    int ans = f[s];
    forn (i, 0, m)
        ans = mul(ans, inv_f[diff[i]]);
    return ans;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    f.resize(1000);
    f[0] = 1;
    forn (i, 1, sz(f))
        f[i] = mul(i, f[i - 1]);
    inv_f.resize(1000);
    forn (i, 0, sz(f))
        inv_f[i] = inv(f[i]);

    long long n;
    cin >> n;
    if (n == 1) {
        int q;
        cin >> q;
        while (q --> 0) {
            long long v, u;
            cin >> v >> u;
            cout << "1\n";
        }
        return 0;
    }
    get_primes(n);
    m = sz(primes);
    int q;
    cin >> q;
    while (q --> 0) {
        long long v, u;
        cin >> v >> u;
        vector <int> a, b;
        get(v, a), get(u, b);
        vector <int> c(m);
        forn (i, 0, m)  
            c[i] = min(a[i], b[i]);
        cout << mul(solve(a, c), solve(b, c)) << "\n"; 
    }
    return 0;
}