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
const int mod = 1e9 + 7, abc = 864197532, N = 100001, K = 111;

int solve_ans(vector <int> a, vector <int> b) {
    a.pb(mod);
    int n = a.size(), m = b.size();
    vector <bool> ok(m, false);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(all(b), a[i]);
        if (it != b.end() && *it == a[i]) ok[it - b.begin()] = true, ans++;
    }
    int now = ans;
    for (int i = 0, j = 0; i < m; ++i) {
        now -= ok[i];
        while (j < n && a[j] <= b[i]) {
            j++;
        }
        ans = max(ans, i - int(upper_bound(all(b), b[i] - j) - b.begin()) + now + 1);
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> posa, nega, posb, negb;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x > 0) posa.pb(x);
        else nega.pb(-x);
    }
    reverse(all(nega));
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        if (x > 0) posb.pb(x);
        else if (x < 0) negb.pb(-x);
    }
    reverse(all(negb));
    cout << solve_ans(posa, posb) + solve_ans(nega, negb) << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}