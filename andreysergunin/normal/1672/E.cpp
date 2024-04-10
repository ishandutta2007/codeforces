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

vector<int> arr;

int ask(int w) {
    cout << "? " << w << endl;
    int h;
    cin >> h;
    // int h = 1;
    // int len = -1;
    // for (int i = 0; i < sz(arr); ++i) {
    //     if (arr[i] > w) {
    //         return 0;
    //     }
    //     if (len + arr[i] + 1 > w) {
    //         ++h;
    //         len = arr[i];
    //     } else {
    //         len += arr[i] + 1;
    //     }
    // }
    // cerr << h << endl;

    return h;
}

void solve() {
    int n;
    cin >> n;
    // arr = {5, 2, 7, 3, 5, 6};
    int l = n - 1, r = 2001 * n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ask(m) == 1) {
            r = m;
        } else {
            l = m;
        }
    }

    int s = r - (n - 1);
    int ans = n - 1;

    for (int h = n; h >= 2; --h) {
        int rg = (s + ans - 1) / h;
        int lf = (s + h - 1) / h;
        while (rg >= lf) {
            int hh = ask(rg);
            if (hh == 0 || hh > h) {
                break;
            }
            ans = min(ans, hh * rg - s);
            --rg;
        }
    }

    cout << "! " << s + ans << endl;
}