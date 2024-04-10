#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  
 
    int tests = 1;
    // cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

const int mod = 1e9 + 7;

struct Mint;
Mint binPow(Mint a, int b);
Mint inv(Mint a);

struct Mint {
    Mint() {}
    Mint(int x) : val(x < 0 ? x + mod : x) {}
    Mint(ll x) : val(x % mod) {}

    Mint operator+(const Mint &other) const { 
        Mint c(val);
        return c += other;
    }

    Mint operator-(const Mint &other) const { 
        Mint c(val);
        return c -= other;
    }

    Mint operator*(const Mint &other) const { 
        return ll(val) * other.val % mod;
    }    

    Mint operator/(const Mint &other) const { 
        return (*this) * inv(other);
    }    

    Mint operator+=(const Mint &other) {
        val += other.val;
        if (val >= mod) {
            val -= mod;
        }
        return *this;
    }

    Mint operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) {
            val += mod;
        }
        return *this;
    }

    Mint operator*=(const Mint &other) {
        val = ll(val) * other.val % mod;
        return *this;
    }

    Mint operator/=(const Mint &other) {
        *this *= inv(other);
        return *this;
    }

    int val = 0;
};

Mint binPow(Mint a, int b) {
    Mint res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
    }
    return res;
}

Mint inv(Mint a) {
    return binPow(a, mod - 2);
}

istream &operator>>(istream &stream, Mint &a) {
    stream >> a.val;
    return stream;
}

ostream &operator<<(ostream &stream, const Mint &a) {
    stream << a.val;
    return stream;
}

void solve() {
    int n;
    cin >> n;
    ++n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (a[0] == 0) {
        cout << 0 << endl;
        return;
    }

    int m = 2.5e5;
    vector<Mint> fact(2 * m + 1), rfact(2 * m + 1), r(2 * m + 1);
    fact[0] = rfact[0] = 1;
    fact[1] = rfact[1] = r[1] = 1;
    for (int i = 2; i <= 2 * m; ++i) {
        fact[i] = fact[i - 1] * i;
        r[i] = r[mod % i] * (mod - mod / i);
        rfact[i] = rfact[i - 1] * r[i];
    }


    auto choose = [&](int n, int k) {
        if (k < 0 || k > n) {
            return Mint(0);
        }
        return fact[n] * rfact[k] * rfact[n - k];
    };

    Mint res = 0;

    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            ++b[a[i] - 1];
        }
    }
    for (int i = m - 2; i >= 0; --i) {
        b[i] += b[i + 1];
    }

    for (int i = 0; i < n; ++i) {
        res += choose(i + a[i] - 1, i);
    }
    for (int i = 0; i < m; ++i) {
        res += choose(i + b[i] - 1, i);
    }
    res -= 1;

    cout << res << endl;
}