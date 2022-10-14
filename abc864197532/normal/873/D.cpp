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
    int n, k;
    cin >> n >> k;
    if (k & 1 ^ 1) return cout << -1 << endl, 0;
    if (k > n * 2 - 1) return cout << -1 << endl, 0;
    k = (k - 1) / 2;
    vector <int> ans(n);
    iota(all(ans), 1);
    int l = 0, r = n;
    auto swapp = [&](int l, int m, int r) {
        if (r - m > m - l) r--;
        vector <int> add;
        for (int k = m; k < r; ++k) add.pb(ans[k]);
        for (int k = l; k < m; ++k) add.pb(ans[k]);
        for (int k = l; k < r; ++k) ans[k] = add[k - l];
    };
    while (r - l > 1 && k) {
        int m = l + r >> 1;
        swapp(l, m, r);
        k--;
        if (k >= m - l - 1) {
            k -= m - l - 1;
            reverse(ans.begin() + l, ans.begin() + m);
            l = m;
        } else {
            r = m;
        }
    }
    printv(ans);
}