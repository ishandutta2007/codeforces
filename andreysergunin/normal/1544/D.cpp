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
    // freopen("input.txt", "r", stdin);
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }   
    vector<int> used(n);
    vector<int> left, right;

    for (int i = 0; i < n; ++i) {
        if (used[a[i]]) {
            left.push_back(i);
        }
        ++used[a[i]];
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            right.push_back(i);
        }
    }

    int res = sz(left);

    if (sz(left) == 1) {
        for (int i = 0; i < n; ++i) {
            if (used[a[i]] == 2 && i != right[0]) {
                a[i] = right[0];
                break;
            }
        }
    } else if (sz(left) > 1) {
        int k = sz(left);
        for (; k > 2; --k) {
            if (left[k - 1] == right[k - 1]) {
                swap(right[k - 2], right[k - 1]);
            }
            a[left[k - 1]] = right[k - 1];
            left.pop_back();
            right.pop_back();
        }
        if (left[0] == right[0] || left[1] == right[1]) {
            swap(right[0], right[1]);
        }
        a[left[0]] = right[0];
        a[left[1]] = right[1];
    }

    cout << n - res << endl;
    for (int x : a) {
        cout << x + 1 << " ";
    }
    cout << '\n';
}