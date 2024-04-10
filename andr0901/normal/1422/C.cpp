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


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    forn (i, 0, sz(s))
        s[i] -= '0';
    int ans = 0, r = 0, l = 0, pow = 1;
    for (int i = sz(s) - 1; i >= 0; --i) {
        l = add(l, mul(pow, s[i]));
        pow = mul(pow, 10);
    }
    int cnt = 1, p = 1, sum = 0;
    int ten_inv = inv(10);
    forn (i, 0, sz(s)) {
        pow = mul(pow, ten_inv);
        l = sub(l, mul(pow, s[i]));
        cerr << l << " " << r << "\n";
        ans = add(ans, add(mul(sum, pow), mul(l, cnt)));
        cerr << add(mul(sum, pow), mul(l, cnt)) << "\n\n";
        r = add(s[i], mul(10, r));
        p = mul(p, 10);
        sum = add(sum, r);
        ++cnt;
    }
    cout << ans;
    return 0;
}