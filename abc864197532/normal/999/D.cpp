#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
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
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 998244353, abc = 864197532, N = 200005, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n), cnt(m, -n / m);
    for (int i = 0; i < n; ++i) cin >> a[i], cnt[a[i] % m]++;
    vector <int> remain;
    vector <vector <int>> change(m);
    for (int t : {0, 1}) {
        for (int i = 0; i < m; ++i) {
            if (cnt[i] > 0) {
                while (cnt[i] > 0) {
                    remain.pb(i);
                    cnt[i]--;
                }
            } else {
                while (!remain.empty() && cnt[i] < 0) {
                    change[remain.back()].pb(i);
                    remain.pop_back();
                    cnt[i]++;
                }
            }
        }
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        int r = a[i] % m;
        if (!change[r].empty()) {
            int to = change[r].back();
            if (r < to) ans += to - r, a[i] += to - r;
            else ans += to + m - r, a[i] += to + m - r;
            change[r].pop_back();
        }
    }
    cout << ans << endl;
    printv(a);
}