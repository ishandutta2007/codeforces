#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;


vector<vector<pair<int, int>>  > g;
vector<int> assignment;
vector<int> searched;
vector<int> parent;
vector<int> depth;



template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt& operator+=(const ModInt& p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator-=(const ModInt& p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt& operator*=(const ModInt& p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt& operator/=(const ModInt& p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt& p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt& p) const { return x == p.x; }

    bool operator!=(const ModInt& p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const ModInt& p) {
        return os << p.x;
    }

    friend istream& operator>>(istream& is, ModInt& a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using mint = ModInt< 998244353 >;
mint fct[500005];
mint ifct[5000005];
mint choose(int a, int b) {
    return fct[a] * ifct[b] * ifct[a - b];
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<mint> v;
    v.push_back(1);
    v.push_back(1);
   
    fct[0] = 1;
    for (int i = 1; i < 500005; i++) {
        fct[i] = fct[i - 1] * i;
    }
    ifct[500005 - 1] = (mint)1 / fct[500005 - 1];
    for (int i = 500005 - 2; i >= 0; i--) {
        ifct[i] = ifct[i + 1] * (i + 1);
    }
    for (int i = 2; i < 300005; i++) {
        v.push_back(v[i - 1] + v[i - 2] * (i-1));
    }
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        mint matches = 1;
        mint twos = 1;
        mint tot = 0;
        for (int pairs = 0; pairs * 2 <= n; pairs += 2) {
            mint num = choose(n - pairs, pairs);
            if (pairs != 0) {
                matches *= pairs - 1;
                twos *= 2;
            }
            tot += v[n - (pairs * 2)] * num * matches * twos;
        }
        cout << tot << endl;
    }
}