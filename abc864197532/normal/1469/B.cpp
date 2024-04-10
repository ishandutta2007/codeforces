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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, logN = 17, K = 3e6;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        int ans1 = 0, ans2 = 0, pre = 0;
        for (int i = 0, tmp; i < n; ++i) cin >> tmp, pre += tmp, ans1 = max(ans1, pre);
        cin >> m;
        pre = 0;
        for (int j = 0, tmp; j < m; ++j) cin >> tmp, pre += tmp, ans2 = max(ans2, pre);
        cout << ans1 + ans2 << endl;
    }
}