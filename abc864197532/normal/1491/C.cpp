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
        cin >> n;
        vector <int> a(n);
        lli ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector <int> dsu(n + 1);
        function<int(int)> Find = [&](int x) {
            if (dsu[x] == x) return x;
            return dsu[x] = Find(dsu[x]);
        };
        iota(all(dsu), 0);
        for (int i = 0; i < n; ++i) if (a[i] == 1) dsu[Find(i)] = Find(i + 1);
        for (int i = 0; i < n; ++i) {
            if (a[i] >= 5000) ans += a[i] - 5000, a[i] = 5000;
            while (a[i] > 1) {
                int now = i;
                ans++;
                while (now < n) {
                    int nxt = now + a[now];
                    a[now]--;
                    if (a[now] == 1) dsu[Find(now)] = Find(now + 1);
                    now = (nxt <= n ? Find(nxt) : nxt);
                }
            }
        }
        cout << ans << endl;
    }
}