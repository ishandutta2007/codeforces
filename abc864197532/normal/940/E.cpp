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
const int mod = 1e9 + 7, abc = 864197532, N = 1001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector <int> a(n);
    vector <lli> pre = {0};
    for (int i = 0; i < n; ++i) cin >> a[i], pre.pb(pre.back() + a[i]);
    if (n < c) {
        cout << pre[n] << endl;
        return 0;
    }
    vector <int> val;
    deque <int> dq;
    for (int i = 0; i < c; ++i) {
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
    }
    val.pb(-a[dq.front()]);
    for (int i = 0; i + c < n; ++i) {
        if (dq.front() == i) dq.pop_front();
        while (!dq.empty() && a[dq.back()] >= a[i + c]) dq.pop_back();
        dq.push_back(i + c);
        val.pb(-a[dq.front()]);
    }
    vector <lli> dp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (i + c <= n) dp[i + c] = min(dp[i + c], dp[i] + val[i]);
        dp[i + 1] = min(dp[i + 1], dp[i]);
    }
    cout << pre[n] + dp[n] << endl;
}