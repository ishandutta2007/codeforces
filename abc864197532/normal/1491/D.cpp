#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 300087, K = 111;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int u, v;
        cin >> u >> v;
        int U = __builtin_popcount(u), V = __builtin_popcount(v);
        if (U < V) {
            cout << "NO\n";
            continue;
        }
        int diff = U - V;
        bool is = true;
        for (int i = 29; ~i; --i) {
            if (v >> i & 1) {
                diff++;
                for (int j = i; ~j && diff; --j) {
                    if (u >> j & 1) {
                        u ^= (1 << j), diff--;
                        if (j == i) break;
                    }
                }
            }
        }
        if (diff) cout << "NO\n";
        else cout << "YES\n";
        /*
         * 1 > 1 + 1
         * 2 > 2 + 2
         * 3 > 3 + 1
         * 3 > 3 + 2
         * 3 > 3 + 3
         * 4 > 4 + 4
         * 5 > 5 + 1
         * 5 > 5 + 4
         * 5 > 5 + 5
         */
    }
}