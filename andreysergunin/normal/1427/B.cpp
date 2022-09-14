#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(6) << fixed;
    cerr << setprecision(6) << fixed;

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
    string s;
    cin >> s;
    vector<int> gaps;

    int prv = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            if (prv == -1) {
                cnt += i;
            }
            if (prv != -1 && prv + 1 != i) {
                gaps.push_back(i - prv - 1);
            }
            prv = i;
        } 
    }

    if (prv == -1) {
        cout << max(2 * min(k, n) - 1, 0) << "\n";
        return;
    }

    cnt += n - prv - 1;

    sort(all(gaps));
    reverse(all(gaps));

    int res = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            ++res;
            res += (i > 0 && s[i - 1] == 'W');
        }
    }

    while (k > 0 && !gaps.empty()) {
        --k;
        --gaps.back();
        res += 2;
        if (gaps.back() == 0) {
            gaps.pop_back();
            ++res;
        }
    }

    while (k > 0 && cnt > 0) {
        --k;
        --cnt;
        res += 2;
    }

    cout << res << "\n";


}