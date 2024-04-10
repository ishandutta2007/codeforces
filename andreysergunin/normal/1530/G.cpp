#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() {    
    int n, k;
    cin >> n >> k;
    array<string, 2> s;
    cin >> s[0] >> s[1];
    array<string, 2> init = s;

    array<int, 2> ones = {0, 0};
    array<int, 2> sum = {0, 0};

    for (int i = 0; i < n; ++i) {
        for (int t = 0; t < 2; ++t) {
            if (s[t][i] == '1') {
                ++ones[t];
                sum[t] += i;
            }
        }
    }

    if (ones[0] != ones[1] || (k % 2 == 0 && sum[0] % 2 != sum[1] % 2)) {
        cout << -1 << endl;
        return;
    }

    if (k == 0) {
        cout << (s[0] == s[1] ? 0 : -1) << endl;
        return;
    }

    array<vector<pii>, 2> res;

    for (int i = n - 1; i >= 0; --i) {
        if (s[0][i] == s[1][i]) {
            continue;
        }

        int t = s[0][i] == '1' ? 1 : 0;

        int j = i;
        int cnt = 0;
        for (; j >= 0 && cnt < k; --j) {
            cnt += s[t][j] == '1';
        }
        if (cnt < k) {
            break;
        }
        ++j;
        res[t].push_back({j, i});
        reverse(s[t].begin() + j, s[t].begin() + i + 1);
    }

    auto printAns = [&]() {
        while (!res[1].empty()) {
            res[0].push_back(res[1].back());
            res[1].pop_back();
        }

        cout << sz(res[0]) << endl;
        for (auto [l, r] : res[0]) {
            cout << l + 1 << " " << r + 1 << endl;
        }
    };

    if (k > ones[0]) {
        if (s[0] == s[1]) {
            printAns();
        } else {
            cout << -1 << endl;
        }
        return;
    }

    if (k == ones[0]) {
        if (s[0] == s[1]) {
            printAns();
            return;
        }

        int lf = -1, rg = -1;
        for (int i = 0; i < n; ++i) {
            if (s[0][i] == '1') {
                rg = i;
                lf = (lf == -1 ? i : lf);
            }
        }

        res[0].push_back({lf, rg});
        reverse(s[0].begin() + lf, s[0].begin() + rg + 1);
        
        if (s[0] == s[1]) {
            printAns();
            return;
        }

        cout << -1 << endl;
        return;
    }


    ones = {0, 0};

    n = 0;
    for (; ones[0] != k + 1 && ones[1] != k + 1; ++n) {
        ones[0] += s[0][n] == '1';
        ones[1] += s[1][n] == '1';
    }

    for (int t = 0; t < 2; ++t) {
        for (int it = 1; it <= k; ++it) {
            int lf = -1, rg = -1;
            for (int i = 0; i < n; ++i) {
                if (s[t][i] == '1') {
                    rg = i;
                    lf = (lf == -1 ? i : lf);
                }
            }

            if (it & 1) {
                res[t].push_back({lf, rg - 1});
                reverse(s[t].begin() + lf, s[t].begin() + rg);
            } else {
                res[t].push_back({lf + 1, rg});
                reverse(s[t].begin() + lf + 1, s[t].begin() + rg + 1);
            }

        }
    }

    // cerr << s[0] << " " << s[1] << endl;

    array<int, 2> lf = {-1, -1};
    array<int, 2> rg = {-1, -1};
    for (int i = 0; i < n; ++i) {
        for (int t = 0; t < 2; ++t) {
            if (s[t][i] == '1') {
                rg[t] = i;
                lf[t] = (lf[t] == -1 ? i : lf[t]);
            }
        }
    }

    int l = min(lf[0], lf[1]);
    int r = max(rg[0], rg[1]);
    int t = lf[0] < lf[1] ? 0 : 1;

    if (k & 1) {
        for (int it = 0; s[0] != s[1]; ++it) {
            if (it & 1) {
                res[t].push_back({l, r - 1});
                reverse(s[t].begin() + l, s[t].begin() + r);
            } else {
                res[t].push_back({l + 1, r});
                reverse(s[t].begin() + l + 1, s[t].begin() + r + 1);
            }
        }
    } else if (s[0] != s[1]) {
        cout << -1 << endl;
        return;
    }
        

    printAns();

    assert(sz(res[0]) + sz(res[1]) <= 3 * sz(s[0]));

    for (auto [lf, rg] : res[0]) {
        int cnt = 0;
        for (int i = lf; i <= rg; ++i) {
            cnt += init[0][i] == '1';
        }
        // cerr << init[0] << " " << init[1] << endl;
        // cerr << lf << " " << rg << endl;
        assert(cnt == k);
        reverse(init[0].begin() + lf, init[0].begin() + rg + 1);
    }
    assert(init[0] == init[1]);
}