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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 3e6;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), is(n, 0);
    int al = 0, ans = n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto update = [&](int x, int f) {
        if (x - 1 >= 0 && x + 1 < n && a[x] < a[x + 1] && a[x] < a[x - 1]) al += f;
        if (x - 1 >= 0 && x + 1 < n && a[x] > a[x + 1] && a[x] > a[x - 1]) al += f;
    };
    auto change = [&](int x, int v) {
        update(x - 1, -1);
        update(x, -1);
        update(x + 1, -1);
        int tmp = a[x];
        a[x] = v;
        update(x - 1, 1);
        update(x, 1);
        update(x + 1, 1);
        ans = min(ans, al);
        update(x - 1, -1);
        update(x, -1);
        update(x + 1, -1);
        a[x] = tmp;
        update(x - 1, 1);
        update(x, 1);
        update(x + 1, 1);
    };
    for (int i = 1; i < n - 1; ++i) update(i, 1);
    ans = al;
    for (int i = 0; i < n; ++i) {
        if (i) change(i, a[i - 1]);
        if (i + 1 < n) change(i, a[i + 1]);
    }
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}