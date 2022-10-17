#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
typedef std::decay <decltype(MOD)>::type mod_t;
struct mi {
    mod_t val;
    explicit operator mod_t() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend std::istream& operator >> (std::istream& in, mi& a) { 
        long long x; std::cin >> x; a = mi(x); return in; }
    friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }    
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
    friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
    friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};

namespace Hashing {

const int MOD = 1e9 + 7;
std::mt19937 rng((uint32_t) std::chrono::steady_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const std::array<int, 2> base = {BDIST(rng), BDIST(rng)};
std::vector<std::array<int, 2>> pows = {{1, 1}};

std::array<int, 2> operator + (std::array<int, 2> l, std::array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        if ((l[i] += r[i]) >= MOD)
            l[i] -= MOD;
    return l;
}
std::array<int, 2> operator - (std::array<int, 2> l, std::array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        if ((l[i] -= r[i]) < 0)
            l[i] += MOD;
    return l;
}
std::array<int, 2> operator * (std::array<int, 2> l, std::array<int, 2> r) {
    for (int i = 0; i < 2; i++)
        l[i] = (long long) l[i] * r[i] % MOD;
    return l;
}
std::array<int, 2> make_hash(char c) {
    return {c, c};
}
struct HashRange {
    std::vector<std::array<int, 2>> pre = {{0, 0}};
    std::string s;
    void add(char c) {
        s += c;
        pre.push_back(base * pre.back() + make_hash(c));
    }
    void add(std::string t) {
        for (auto& c : t)
            add(c);
    }
    void extend(int len) {
        while ((int) pows.size() <= len)
            pows.push_back(base * pows.back());
    }
    std::array<int, 2> hash(int l, int r) {
        int len = r + 1 - l;
        extend(len);
        return pre[r + 1] - pows[len] * pre[l];
    }
};

} // Hashing

const int L = 21;
const int N = (1 << (L - 1));

mi po[N];
mi ipo[N];
mi i2 = 1 / mi(2);

int main() {
    using namespace std;
    using namespace Hashing;
    cin.tie(0)->sync_with_stdio(0); 

    po[0] = ipo[0] = 1;
    for (int i = 1; i < N; i++) {
        po[i] = po[i - 1] * 2;
        ipo[i] = ipo[i - 1] * i2;
    }

    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;

    int m = int(s.size());

    vector<vector<int>> use(26);
    vector<vector<mi>> pre(26, vector<mi>(n));
    for (int i = 0; i < n; i++) {
        use[t[i] - 'a'].push_back(i + 1);
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < int(use[i].size()); j++) {
            pre[i][j] = (j ? pre[i][j - 1] : 0) + ipo[use[i][j]];
        }
    }

    HashRange scmp;
    scmp.add(s);
    int sbase = m;

    HashRange tcmp;
    string tmp = "";
    int cnt = 0;
    while (int(tmp.size()) < 2 * N) {
        char add = '?';
        if (cnt < n) add = t[cnt];
        tmp = tmp + add + tmp;
        cnt++;
    }
    tcmp.add(tmp);
    int tbase = int(tmp.size());

    for (int qq = 0; qq < q; qq++) {
        mi ans = 0;
        int k; string w; cin >> k >> w;
        int sz = int(w.size());
        scmp.add(w);

        auto S = [&](int a, int b, int c, int d) -> bool {
            return (scmp.hash(a, b) == scmp.hash(sbase + c, sbase + d));
        };
        // Case 1: w is completely within s
        if (sz <= m) { 
            for (int i = 0; i <= m - sz; i++) {
                if (S(i, i + sz - 1, 0, sz - 1)) {
                    ans += po[k];
                }
            }
        }

        // Case 2: it straddles a border
        vector<int> c; // stores where the t characters occur
        for (int i = 0; i <= min(sz - 1, m); i++) {
            // first occurence of the t character is at location i
            c.clear();
            bool ok = true;
            c.push_back(w[i] - 'a');
            if (i) { 
                // check if the first part agrees 
                ok &= S(m - 1 - (i - 1), m - 1, 0, i - 1);
            }
            int up = i + m + 1;
            while (up < sz) {
                c.push_back(w[up] - 'a');
                ok &= S(0, m - 1, up - m, up - 1);
                up += m + 1;
            }
            up -= (m + 1);
            if (up != sz - 1) {
                // check if the last part agrees
                ok &= S(0, sz - 1 - up - 1, up + 1, sz - 1);
            }
            if (!ok) continue; // it is incorrect
            

            int num = int(c.size());
            for (int i = 0; i < num; i++) {
                tcmp.add((char) ('a' + c[i]));
            }
            auto T = [&](int c, int d) -> bool {
                return tcmp.hash(0, d - c) == tcmp.hash(c + tbase, d + tbase);
            };
            auto rT = [&](int c, int d) -> bool {
                return tcmp.hash(N - 2 - (d - c), N - 2) == tcmp.hash(c + tbase, d + tbase);
            };
            for (int i = 0; i < num; i++) {
                if (i != num - 1 && !T(i + 1, num - 1)) continue;
                if (i && !rT(0, i - 1)) continue;
                // c[i] is on a peak
                if (use[c[i]].empty()) continue;

                int mx = max(i, num - 1 - i);
                mi run = 0;

                // binary search for first place at greater than or equal to k
                int lo = 0;
                int hi = int(use[c[i]].size()) - 1;
                int loc = -1;
                if (use[c[i]].back() <= k) {
                    loc = hi;
                } else {
                    while (hi - lo > 1) {
                        int mid = (lo + hi) / 2;
                        if (use[c[i]][mid] <= k) lo = mid;
                        else hi = mid - 1;
                    }

                    if (use[c[i]][hi] <= k) loc = hi;
                    else if (use[c[i]][lo] <= k) loc = lo;
                }

                for (int j = 0; j < int(use[c[i]].size()); j++) {
                    if (j > loc) break;
                    int id = use[c[i]][j];
                    assert(id <= k);
                    if (id >= L || (1 << (id - 1)) > mx) {
                        if (id < L) {
                            ans += po[k] * ipo[id];
                        } else {
                            ans += po[k] * (pre[c[i]][loc] - run);
                            break;
                        }
                    }
                    run += ipo[id];
                }
            }
            tbase += num;
        }
        cout << ans << '\n';
        sbase += sz;
    }   
    return 0;
}