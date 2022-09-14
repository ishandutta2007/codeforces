#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

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
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }


#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

const int MAXN = 200200;
const int LIM = 300;


int used[MAXN * (LIM + 1)];

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    // int n = 200000;

    // for (int i = 0; i < n; ++i) {
    //     s += (rnd() & 1 ? '0' : '1');
    // }

    vector<int> arr;

    ll ans = 0;

    for (int m = 1; m <= min(LIM, n); ++m) {
        int pref = n;
            
        arr.push_back(pref);
        used[pref] = 1;

        for (int i = 0; i < n; ++i) {   
            pref += (s[i] == '1' ? m : 0) - 1;
            ++used[pref];
            arr.push_back(pref);
        }

        for (int pos : arr) {
            ans += ll(used[pos]) * (used[pos] - 1) / 2;
            used[pos] = 0;
        }

        arr.clear();
    }



    for (int sum = 1; sum <= n / LIM; ++sum) {
        int lf = 0, rg = 0;

        int sm = 0;
        while (sm != sum && lf < n) {
            if (s[lf] == '1') {
                ++sm;
            }
            ++lf;
        }

        if (sm != sum) {
            continue;
        }

        rg = lf;    
        while (rg < n && s[rg] == '0') {
            ++rg;
        }

        for (int i = 0; i < n; ++i) {
            // cerr << sum << " " << i << " " << lf << " " << rg << endl;
            int val = (rg - i) / sum - max((lf - i - 1) / sum, LIM);
            val = max(val, 0);
            ans += val;

            if (s[i] == '0') {
                continue;
            }
            
            lf = rg + 1;
            if (lf == n + 1) {
                break;
            }
            ++rg;

            while (s[rg] != '1' && rg < n) {
                ++rg;
            }
        }

        // cerr << ans << endl;
    }

    cout << ans << endl;

}