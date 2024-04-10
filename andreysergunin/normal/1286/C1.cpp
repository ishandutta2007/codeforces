#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

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

vector<string> ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int m = (r - l + 1);
    int n = m * (m + 1) / 2;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sort(all(s[i]));
    }
    sort(all(s));
    return s;
}

void solve() {
    int n;
    cin >> n;

    vector<string> s = ask(1, n);

    if (n == 1) {
        cout << "! " << s[0] << endl;
        return;
    }

    vector<string> t = ask(2, n);

    vector<string> rem(n);

    for (int i = 0, j = 0; i < sz(s); ++i) {
        if (j < sz(t) && s[i] == t[j]) {
            ++j;
        } else {
            rem[sz(s[i]) - 1] = s[i];
        }
    }

    string res(n, ' ');
    res[0] = rem[0][0];

    for (int i = 1; i < n; ++i) {
        vector<int> cnt(26);
        for (char c : rem[i]) {
            ++cnt[c - 'a'];
        }
        for (char c : rem[i - 1]) {
            --cnt[c - 'a'];
        }

        for (int j = 0; j < 26; ++j) {
            if (cnt[j]) {
                res[i] = char(j + 'a');
            }
        }
    }

    cout << "! " << res << endl; 


}