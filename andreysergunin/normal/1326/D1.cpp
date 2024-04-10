#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
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
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

    int tests = 1;
    cin >> tests;

    while (tests--) {
       solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

vector<int> manacher(const string &s) {
    int n = sz(s);
    vector<int> m(n);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        if (j + m[j] >= i) {
            m[i] = min(j + m[j] - i, m[2 * j - i]);
        }
        while (i - m[i] - 1 >= 0 && i + m[i] + 1 < n && s[i - m[i] - 1] == s[i + m[i] + 1]) {
            ++m[i];
        }
    }
    return m;
}


void solve() {      
    string s;
    cin >> s;
    int n = sz(s);
    string t = "*";
    for (int i = 0; i < n; ++i) {
        t += s[i];
        t += '*';
    }

    int len = 0;
    while (2 * len + 2 <= sz(s) && s[len] == s[n - len - 1]) {
        ++len;
    }

    vector<int> m = manacher(t);

    int res = 0;
    int opt = -1;

    for (int i = 1; i < 2 * n; ++i) {
        if (i & 1) {
            int cur = m[i] / 2;
            int pos = i / 2;
            int boarders = min(pos - cur, n - 1 - (pos + cur));

            if (boarders <= len && 2 * boarders + 1 + 2 * cur > res) {
                res = 2 * boarders + 1 + 2 * cur;
                opt = i;
            }
        } else {
            int cur = (m[i] + 1) / 2;
            int pos = i / 2;
            int boarders = min(pos - cur, n - (pos + cur));
            if (boarders <= len && 2 * boarders + 2 * cur > res) {
                res = 2 * boarders + 2 * cur;
                opt = i;
            }
        }
    }

    vector<int> active(n);

    int boarders = 0;
    if (opt & 1) {
        int cur = m[opt] / 2;
        int pos = opt / 2;
        boarders = min(pos - cur, n - 1 - (pos + cur));
        for (int i = pos - cur; i <= pos + cur; ++i) {
            active[i] = 1;
        }
    } else {
        int cur = (m[opt] + 1) / 2;
        int pos = opt / 2;
        boarders = min(pos - cur, n - (pos + cur));
        for (int i = pos - cur; i < pos + cur; ++i) {
            active[i] = 1;
        }
    }
    for (int i = 0; i < boarders; ++i) {
        active[i] = 1; 
    }
    for (int i = n - boarders; i < n; ++i) {
        active[i] = 1;
    }

    string r;
    for (int i = 0; i < n; ++i) {
        if (active[i]) {
            r += s[i];
        }
    }

    cout << r << "\n";
}