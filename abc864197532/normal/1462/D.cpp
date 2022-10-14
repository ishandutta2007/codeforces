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
const int mod = 1e9 + 7, abc = 864197532, N = 100007, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int al = accumulate(all(a), 0);
        for (int ans = n; ans > 0; --ans) {
            if (al % ans != 0) continue;
            int need = al / ans, tmp = 0;
            bool fail = false;
            for (int i = 0; i < n; ++i) {
                tmp += a[i];
                if (tmp > need) {
                    fail = true;
                    break;
                } else if (tmp == need) {
                    tmp = 0;
                }
            }
            if (!fail) {
                cout << n - ans << endl;
                break;
            }
        }
    }
}