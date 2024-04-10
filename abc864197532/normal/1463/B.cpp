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
        int n;
        cin >> n;
        vector <int> a(n);
        lli sum[2] = {0, 0};
        for (int i = 0; i < n; ++i) cin >> a[i], sum[i & 1] += a[i];
        int st = -1;
        if (sum[0] > sum[1]) {
            st = 1;
        } else {
            st = 0;
        }
        for (int i = 0; i < n; ++i) {
            if ((i & 1) == st) cout << 1 << ' ';
            else cout << a[i] << ' ';
        }
        cout << endl;
    }
}