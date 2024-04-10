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
const int mod = 1e9 + 7, abc = 864197532, N = 1000001, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        /*
         * 001110
         * 0mn -> false
         * 1mn -> true
         * 2mn -> false
         * 3mn -> false
         */
        int n;
        cin >> n;
        vector <bool> a(n * 2, false);
        for (int i = 0, tmp; i < n; ++i) cin >> tmp, a[--tmp] = true;
        int pre = 0, l = 0, r = n;
        for (int i = 2 * n - 1; ~i; --i) {
            pre += a[i] ? -1 : 1;
            if (pre < 0 && a[i]) {
                r--;
                pre = 0;
            }
        }
        pre = 0;
        for (int i = 0; i < 2 * n; ++i) {
            pre += a[i] ? -1 : 1;
            if (pre < 0 && a[i]) l++, pre = 0;
        }
        cout << r - l + 1 << endl;
    }
}