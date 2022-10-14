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
    int n;
    cin >> n;
    vector <int> a(2, 0);
    int al = 0;
    for (int i = 0, w; i < n; ++i) cin >> w, a[--w]++, al += w + 1;
    if (al & 1) {
    	cout << "NO\n";
    	return;
	}
	al >>= 1;
	for (int i = 0; i <= a[1]; ++i) {
		if (0 <= al - i * 2 && al - i * 2 <= a[0]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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