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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, n;
    cin >> n >> l;
    vector <int> a(n + 1, 0);
    vector <int> cur(n + 1, 0);
    for (int i = 1; i < n; ++i) cin >> a[i];
    cur[0] = 1 << 30;
    a[n] = 1 << 30;
    set <int> s;
    for (int i = 0; i <= n; ++i) s.insert(i);
    for (int i = 1; i <= n; ++i) {
        vector <int> del;
        for (auto it = s.lower_bound(i - l); it != s.end() && *it < i && a[i]; ++it) {
            int j = *it;
            int mn = min(a[i], cur[j]);
            a[i] -= mn;
            cur[j] -= mn;
            cur[i] += mn;
            if (cur[j] == 0) del.pb(j);
        }
        for (int i : del) s.erase(i);
        if (cur[i] == 0) s.erase(i);
    }
    cout << cur[n] << endl;
}