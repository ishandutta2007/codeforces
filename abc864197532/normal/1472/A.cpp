#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 3e6;

void solve() {
	int h, w, n;
	cin >> h >> w >> n;
	int al = 1;
	while (h & 1 ^ 1) h >>= 1, al <<= 1;
	while (w & 1 ^ 1) w >>= 1, al <<= 1;
	cout << (al >= n ? "YES\n" : "NO\n");
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