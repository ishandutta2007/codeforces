#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
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
    cout << setprecision(9) << fixed;
    cerr << setprecision(9) << fixed;

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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> in(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int j;
            cin >> j;
            --j;
            ++in[i];
            g[j].push_back(i);
        }
    }
    set<int> setik;

    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            setik.insert(i);
        }
    }

    int res = 1, cnt = 0;

    int cur = 0;
    while (!setik.empty()) {
        auto it = setik.lower_bound(cur);
        if (it == setik.end()) {
            ++res;
            it = setik.begin();
        }
        ++cnt;
        cur = *it;
        setik.erase(it);
        for (int to : g[cur]) {
            --in[to];
            if (!in[to]) {
                setik.insert(to);
            }
        }
    }

    cout << (cnt == n ? res : -1) << endl;
}