
using namespace std;

//#define fileio

#ifndef fileio
#include <iostream>
#endif
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>

typedef long long ll;

#ifdef fileio
ifstream cin;
ofstream cout;
#endif


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

using mint = ModInt< 1000000007 >;



mint power(mint a, int b) {
    if (b == 0) return 1;
    mint y = power(a, b / 2);
    if (b % 2 == 0) return y * y;
    return y * y * a;
}

ll power(ll a, int b) {
    if (a == 1) return 1;
    if (b > 15) return 1000001;
    if (b == 0) return 1;
    ll y = power(a, b / 2);
    if (y > 1000001) return 1000001;
    if (y * y > 1000001) return 1000001;
    if (b % 2 == 0) return y * y;
    return y * y * a;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef fileio
    cin.open("Text.txt");
    cout.open("Output.txt");
#endif
   

    int tests;
    cin >> tests;
    for (int casenum = 1; casenum <= tests; casenum++) {
        int n, p;
        cin >> n >> p;

        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }


        sort(v.rbegin(), v.rend());
        ll difference = 0;
        mint realdifference = 0;
        int cur = v[0];


        for (int i : v) {
            if (cur > i) {
                realdifference *= power((mint)p, cur-i);
                if (difference < 1000001) difference *= power(p, cur-i);
                cur = i;
            }
            if (difference == 0) {
                difference++;
                realdifference+=1;
            }
            else {
                if (difference < 1000001) difference--;
                realdifference -= 1;
            }
        }
        if (cur > 0) {
            realdifference *= power((mint)p, cur );
            if (difference < 1000001) difference *= power(p, cur);
            cur--;
        }
        cout << realdifference << endl;


    }


}