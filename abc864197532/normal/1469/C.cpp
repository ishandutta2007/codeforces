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
        int n, k;
        cin >> n >> k;
        int l, r;
        bool is = true;
        for (int i = 0, h; i < n; ++i) {
            cin >> h;
            if (i == 0) l = r = h;
            else if (i == n - 1) {
                if (h + k <= l || r + k <= h) is = false;
            } else {
                l = max(l - k + 1, h);
                r = min(r + k - 1, h + k - 1);
                if (l > r) {
                    is = false;
                }
            }
        }
        cout << (is ? "YES\n" : "NO\n");
    }
}