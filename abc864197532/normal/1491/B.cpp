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
        int n;
        lli u, v;
        cin >> n >> u >> v;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (*max_element(all(a)) == *min_element(all(a))) {
            cout << min(u + v, v * 2) << endl;
        } else {
            bool is = false;
            for (int i = 0; i + 1 < n; ++i) {
                if (abs(a[i] - a[i + 1]) > 1) is = true;
            }
            if (is) cout << 0 << endl;
            else {
                cout << min(u, v) << endl;
            }
        }
    }
}