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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

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

const int MAXM = 5005000;

vector<pii> arr[MAXM];

void solve() {  
    int n;
    cin >> n;
    vector<pii> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(all(a));

    int l = -1, r = -1;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i].first == a[i + 1].first) {
            if (l == -1) {
                l = i;
            }
            r = i;
        }
    }

    if (l != -1 && r - l >= 2) {
        cout << "YES\n";
        cout << a[l].second << " " << a[r + 1].second << " " << a[l + 1].second << " " << a[r].second << "\n";
        return;
    }

    // int m = 1;
    // for (int i = 1; i < n; ++i) {
    //     if (a[i].first != a[i - 1].first) {
    //         a[m++] = a[i];
    //     }
    // }
    // a.resize(m);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int s = a[i].first + a[j].first;
            pii p = {a[i].second, a[j].second};
            auto [u, v] = p;

            for (auto [x, y] : arr[s]) {
                if (x != u && x != v && y != u && y != v) {
                    cout << "YES\n";
                    cout << x << " " << y << " " << u << " " << v << "\n";
                    return;
                }
            }

            arr[s].push_back(p);
        }
    }

    cout << "NO\n";

}