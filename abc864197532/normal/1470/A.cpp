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
    int n, m;
    cin >> n >> m;
    int a[m]{}, b[m];
    lli al = 0;
    for (int i = 0, tmp; i < n; ++i) cin >> tmp, a[--tmp]++;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        al += 1ll * b[i] * a[i];
    }
    for (int i = m - 1, j = 0; i >= 0 && j < m; --i) {
        while (j < m && a[i] && b[i] > b[j]) {
            al -= b[i] - b[j++];
            a[i]--;
        }
    }
    cout << al << endl;
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