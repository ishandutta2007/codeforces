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

const int N = 100;
int isPrime[N];

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; i++) {
        int d = s[i] - '0';
        if (!isPrime[d]) {
            cout << "1\n" << d << '\n';
            return;
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int d = (s[i] - '0') * 10 + s[j] - '0';
            if (!isPrime[d]) {
                cout << "2\n" << d << '\n';
                return;
            }
        }
    }
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i < N; i++) {
        isPrime[i] = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime[i] = 0;
            }
        }
    }

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}