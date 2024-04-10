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
        int n;
        cin >> n;
        vector <pii> ans;
        int cur = n;
        for (int i = n - 1; i > 2; --i) {
            if (i <= (cur + i - 1) / i) {
                ans.eb(n, i);
                cur = (cur + i - 1) / i;
            }
            ans.eb(i, n);
        }
        while (cur > 1) {
            cur = (cur + 1) / 2;
            ans.eb(n, 2);
        }
        cout << ans.size() << endl;
        for (pii A : ans) cout << A.X << ' ' << A.Y << endl;
    }
}