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

    while (tests--) {
        solve();
    }


#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

void solve() {
    int n;
    cin >> n;

    vector<int> to(n);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        x += n - i;
        to[n - i] = x;
    }

    vector<int> cycle;
    int cur = 0;
    vector<int> used(n);

    for (int j = 1; ; ++j) {
        if (used[cur]) {
            break;
        }
        cycle.push_back(cur);
        used[cur] = j;
        cur = to[cur];
    }

    cout << sz(cycle) - (used[cur] - 1) << "\n";
    for (int i = used[cur] - 1; i < sz(cycle); ++i) {
        cout << n - cycle[i] << " ";
    }
    cout << "\n";

}