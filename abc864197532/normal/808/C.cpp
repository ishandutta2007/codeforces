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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, w, need = 0;
    cin >> n >> w;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        need += (a[i] + 1) / 2;
    }
    if (need > w) {
        cout << -1 << endl;
    } else {
        vector <int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = (a[i] + 1) / 2, w -= ans[i];
        vector <int> p(n);
        iota(all(p), 0);
        sort(all(p), [&](int i, int j) {
            return a[i] > a[j];
        });
        for (int i = 0; i < n && w; ++i) {
            int mn = min(w, a[p[i]] - ans[p[i]]);
            w -= mn;
            ans[p[i]] += mn;
        }
        printv(ans);
    }
}