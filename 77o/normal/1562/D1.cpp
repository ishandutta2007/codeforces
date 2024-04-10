// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

using ll = long long;

template <typename T, typename S = istream>
void read(vector<T>& vec, S& in = cin) {
    for (auto& elem : vec) {
        in >> elem;
    }
}

template <typename T, typename S = ostream>
void write(const vector<T>& vec, char delim = ' ', char last = '\n', S& out = cout) {
    bool first = true;
    for (auto& elem : vec) {
        if (!first) {
            out << delim;
        }
        out << elem;
        first = false;
    }
    out << last;
}

const int MOD = 1e9 + 7;
const int NUMB = 998'244'853;
const int DUMB = 998'244'353;

ll binpow(ll a, ll p, ll mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * a % mod;
        }
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<array<int, 2>> pref(n + 1);
    pref[0][0] = pref[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        int cur = s[i - 1] == '+' ? 1 : -1;
        for (int j = 0; j < 2; j++) {
            int x = cur;
            if (i % 2 != j % 2) {
                x = -cur;
            }
            pref[i][j] = pref[i - 1][j] + x;
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if ((r - l + 1) % 2) {
            cout << "1\n";
            continue;
        }
        int sum = pref[r][l % 2] - pref[l - 1][l % 2];
        if (sum == 0) {
            cout << "0\n";
        } else {
            cout << "2\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}