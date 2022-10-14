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
const int mod = 1e9 + 7, abc = 864197532, N = 100001, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;
    if (a >= c) {
        cout << 0 << endl;
        return 0;
    }
    lli l = 0, r = 1ll << 50;
    while (r - l > 1) {
        lli mid = l + r >> 1;
        if (c - mid <= a - (max(mid * x - b, 0ll) + w - 1) / w) r = mid;
        else l = mid;
    }
    cout << r << endl;
}