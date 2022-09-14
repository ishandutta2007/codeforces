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

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    string t;
    for (int i = 0; i < k - 1; ++i) {
        t += "()";
    }
    for (int i = 0; i < (n - 2 * (k - 1)) / 2; ++i) {
        t += "(";
    }
    for (int i = 0; i < (n - 2 * (k - 1)) / 2; ++i) {
        t += ")";
    }

    vector<pii> res;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (t[i] != s[j]) {
            ++j;
        }

        if (i == j) {
            continue;
        }

        reverse(s.begin() + i, s.begin() + j + 1);
        res.push_back({i + 1, j + 1});
    }

    cout << sz(res) << endl;
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
}

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

    int tests;
    cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}