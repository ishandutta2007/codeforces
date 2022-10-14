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
const int mod = 1e9 + 7, abc = 864197532, N = 100001, K = 111;

void solve() {
    int n, a[4];
    cin >> n;
    for (int i = 0; i < 4; ++i) cin >> a[i];
    set <int> s[4];
    for (int i = 0; i < 4; ++i) {
        for (int j : {0, 1, 2}) {
            if (0 <= a[i] - j && a[i] - j <= n - 2) s[i].insert(j);
        }
    }
    bool is = false;
    for (int i = 0; i < 16; ++i) {
        int cnt[4] = {0, 0, 0, 0};
        for (int j = 0; j < 4; ++j) if (i >> j & 1) {
            cnt[j]++;
            cnt[(j + 1) % 4]++;
        }
        bool ok = true;
        for (int j = 0; j < 4; ++j) {
            if (!s[j].count(cnt[j])) ok = false;
        }
        if (ok) is = true;
    }
    cout << (is ? "YES\n" : "NO\n");
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}