#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
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
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int MAXN = 200200;
const int ALPH = 26;
int nxt[MAXN][ALPH];

void solve() {  
    string s;
    cin >> s;

    memset(nxt, -1, sizeof(nxt));
    for (int i = sz(s) - 1; i >= 0; --i) {
        memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
        nxt[i][s[i] - 'a'] = i;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        int cnt = 0;
        for (int c = 0; c < 26; ++c) {
            if (nxt[l][c] != -1 && nxt[l][c] < r) {
                ++cnt;
            }
        }
        if (l + 1 == r || cnt > 2 || s[l] != s[r - 1]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}