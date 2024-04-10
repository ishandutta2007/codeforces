#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    vector<int> b(2), open(2);
    string mask;
    cin >> mask;
    int kek = 0;
    int rem = count(mask.begin(), mask.end(), '1') / 2;
    for (int i = 0; i < n; i++) {
        if (mask[i] == '0') {
            kek++;
            if (kek % 2) {
                open[0]++;
                b[0]++;
                b[1]--;
                s += '(';
                t += ')';
            } else {
                open[1]++;
                b[0]--;
                b[1]++;
                s += ')';
                t += '(';
            }
        } else {
            if (rem > 0) {
                open[0]++;
                open[1]++;
                s += '(';
                t += '(';
                b[0]++;
                b[1]++;
            } else {
                s += ')';
                t += ')';
                b[0]--;
                b[1]--;
            }
            rem--;
        }
        if (b[0] < 0 || b[1] < 0) {
            cout << "NO\n";
            return;
        }
    }
    if (b[0] || b[1]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << s << '\n' << t << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}