#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int MOD = 1000003;

int power(int x, int y, int mod) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % mod;
        y >>= 1;
        x = 1LL * x * x % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k;
    cin >> n >> k;
    { // edge cases
        long long cur = 1, foo = 0;
        while (cur < k) {
            cur = cur * 2;
            foo++;
        }
        if (foo > n) {
            return cout << "1 1\n", 0;
        }
    }

    long long v2 = 0;
    long long cur = 2;
    int limit = min<long long>(60, n);
    for (int i = 1; i <= min<long long>(60, n); i++) {
        v2 += k / cur;
        if (k % cur) v2++;
        cur *= 2;
    }
    v2 += (n - limit) % (MOD - 1);
    int red = power((MOD + 1) / 2, v2 % (MOD - 1), MOD);
    int pp = (n % (MOD - 1)) * (k % (MOD - 1)) % (MOD - 1); 
    int mau = 1LL * power(2, pp, MOD) * red % MOD;
    int tu;
    if (k >= MOD) tu = 0;
    else {
        int start = power(2, n % (MOD - 1), MOD);
        tu = 1;
        for (int i = start; i > start - k; i--) {
            tu = (1LL * tu * i) % MOD;
        }
        if (tu < 0) tu += MOD;
    } 

    cout << ((mau - 1LL * tu * red % MOD) + MOD) % MOD << ' ' << mau << '\n';

    return 0;
}