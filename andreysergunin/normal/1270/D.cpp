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

int ask(const vector<int> &arr) {
    cout << "? ";
    for (int x : arr) {
        cout << x + 1 << " ";
    }
    cout << endl;
    int res, tmp;
    cin >> tmp >> res;
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ans;
    for (int i = 0; i <= k; ++i) {
        vector<int> arr;
        for (int j = 0; j <= k; ++j) {
            if (i != j) {
                arr.push_back(j);
            }
        }
        ans.push_back(ask(arr));
    }


    sort(all(ans));

    int cnt = 1;
    assert(ans[0] != ans.back());
    while (ans[cnt] == ans[cnt - 1]) {
        ++cnt;
    }

    cout << "! " << k + 1 - cnt << endl;
}