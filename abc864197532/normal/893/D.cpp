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
    int n, d;
    cin >> n >> d;
    vector <int> a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            tmp += a[i];
            if (tmp > d) {
                cout << -1 << endl;
                return 0;
            }
        } else {
            if (tmp < 0) {
                tmp = 0;
            }
        }
    }
    int ans = 0;
    vector <int> pre(n, 0);
    for (int i = 0; i < n; ++i) pre[i] = a[i] + (i ? pre[i - 1] : 0);
    vector <int> suf = pre;
    for (int i = n - 2; ~i; --i) suf[i] = max(suf[i], suf[i + 1]);
    int add = 0;
    for (int i = 0; i < n; ++i) {
        if (pre[i] + add < 0 && a[i] == 0) {
            add = d - suf[i];
            ans++;
        }
    }
    
    cout << ans << endl;
}