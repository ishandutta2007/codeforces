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
        vector <pll> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i].X >> v[i].Y, v[i].X--;
        v.eb(1ll << 40, 0);
        int ans = 0;
        for (int i = 0, from = 0, j = 1; i < n; i = j, j++) {
            while (j < n && v[j].X < v[j - 1].X + abs(v[i].Y - from)) {
                int to;
                if (from < v[i].Y) to = from + v[j].X - v[j - 1].X;
                if (from > v[i].Y) to = from - v[j].X + v[j - 1].X;
                if (from < to) ans += (from <= v[j - 1].Y && v[j - 1].Y <= to);
                else ans += (to <= v[j - 1].Y && v[j - 1].Y <= from);
                from = to;
                j++;
            }
            int to = v[i].Y;
            if (from < to) ans += (from <= v[j - 1].Y && v[j - 1].Y <= to);
            else ans += (to <= v[j - 1].Y && v[j - 1].Y <= from);
            from = to;
        }
        cout << ans << endl;
    }
}