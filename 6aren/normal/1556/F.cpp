#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    os << '[';
    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";
    if (!vt.empty()) os << vt.back();
    return os << ']';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define bit(x, y) ((x >> y) & 1)

template <int MOD_>
struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

   private:
    using ll = long long;

    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

   public:
    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) {
        if (v < 0) v += MOD;
    }
    explicit operator int() const { return v; }
    friend std::ostream& operator<<(std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator>>(std::istream& in, modnum& n) {
        ll v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }

    friend bool operator==(const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator!=(const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator-() const {
        return neg();
    }
    modnum operator+() const {
        return modnum(*this);
    }

    modnum& operator++() {
        v++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator--() {
        if (v == 0) v = MOD;
        v--;
        return *this;
    }
    modnum& operator+=(const modnum& o) {
        v -= MOD - o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator-=(const modnum& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator*=(const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator/=(const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator++(modnum& a, int) {
        modnum r = a;
        ++a;
        return r;
    }
    friend modnum operator--(modnum& a, int) {
        modnum r = a;
        --a;
        return r;
    }
    friend modnum operator+(const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator-(const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using mint = modnum<1000000007>;

void run_case() {
    int n;
    cin >> n;
    vector<mint> a(n);
    for (mint &e : a) cin >> e;
    vector<mint> dp(1 << n, 0);
    vector<vector<mint>> pre_calc(n, vector<mint>(1 << n, 1));
    vector<vector<mint>> win(n, vector<mint>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            win[i][j] = a[i] / (a[i] + a[j]);
            win[j][i] = 1 - win[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (bit(mask, i)) continue;
            for (int j = 0; j < n; j++) {
                if (bit(mask, j)) pre_calc[i][mask] = pre_calc[i][mask] * win[i][j];
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        dp[mask] = 1;
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            if (submask == mask) continue;
            assert((mask & submask) == submask);
            int rem = mask - submask;
            mint tmp = 1;
            for (int i = 0; i < n; i++) {
                if (bit(submask, i)) tmp = tmp * pre_calc[i][rem];
            }
            dp[mask] -= tmp * dp[rem];
        }
    }
    // cout << dp[7] << endl;
    mint res = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int rem = (1 << n) - 1 - mask;
        mint tmp = 1;
        for (int i = 0; i < n; i++) {
            if (bit(mask, i)) tmp = tmp * pre_calc[i][rem];
        }
        res = (res + dp[mask] * tmp *  __builtin_popcount(mask));
    }
    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    while (tests--) run_case();
    return 0;
}