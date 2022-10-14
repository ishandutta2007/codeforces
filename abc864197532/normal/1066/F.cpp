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

int dis(pii a, pii b) {
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    a.pb({0, 0});
    n++;
    sort(all(a), [](pii i, pii j) {
        if (max(i.X, i.Y) == max(j.X, j.Y)) return i.X - i.Y < j.X - j.Y;
        return max(i.X, i.Y) < max(j.X, j.Y);
    });
    vector <lli> dp;
    vector <int> id;
    vector <pii> b;
    for (int i = 0, j = 0, cnt = 0; i < n; i = j, cnt++) {
        while (j < n && max(a[i].X, a[i].Y) == max(a[j].X, a[j].Y)) j++;
        if (j - i == 1) {
            b.pb(a[i]);
            id.pb(cnt);
        } else {
            b.pb(a[i]);
            id.pb(cnt);
            b.pb(a[j - 1]);
            id.pb(cnt);
        }
    }
    a = b;
    n = a.size();
    dp.assign(n, 1ll << 60);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (i + 1 < n && id[i] == id[i + 1]) {
            if (i - 2 >= 0 && id[i - 2] == id[i - 1]) {
                dp[i] = min(dp[i], dp[i - 2] + dis(a[i - 2], a[i + 1]) + dis(a[i + 1], a[i]));
                dp[i + 1] = min(dp[i + 1], dp[i - 2] + dis(a[i - 2], a[i]) + dis(a[i],  a[i + 1]));
                dp[i] = min(dp[i], dp[i - 1] + dis(a[i - 1], a[i + 1]) + dis(a[i + 1], a[i]));
                dp[i + 1] = min(dp[i + 1], dp[i - 1] + dis(a[i - 1], a[i]) + dis(a[i],  a[i + 1]));
            } else {
                dp[i] = min(dp[i], dp[i - 1] + dis(a[i - 1], a[i + 1]) + dis(a[i + 1], a[i]));
                dp[i + 1] = min(dp[i + 1], dp[i - 1] + dis(a[i - 1], a[i]) + dis(a[i],  a[i + 1]));
            }
            i++;
        } else {
            if (i - 2 >= 0 && id[i - 2] == id[i - 1]) {
                dp[i] = min(dp[i], dp[i - 2] + dis(a[i - 2], a[i]));
                dp[i] = min(dp[i], dp[i - 1] + dis(a[i - 1], a[i]));
            } else {
                dp[i] = min(dp[i], dp[i - 1] + dis(a[i - 1], a[i]));
            }
        }
    }
    if (id[n - 2] == id[n - 1]) cout << min(dp[n - 1], dp[n - 2]) << endl;
    else cout << dp[n - 1] << endl;
}