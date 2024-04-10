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
const int mod = 1e9 + 7, abc = 864197532, N = 400008, logN = 17, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> l(n, n), r(n, -1), cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i], --a[i];
        cnt[a[i]]++;
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    vector <int> dp(n + 1, 0), cur(n, 0);
    for (int i = n - 1; ~i; --i) {
        int x = a[i];
        cur[x]++;
        dp[i] = max(dp[i + 1], cur[x]);
        if (l[x] == i) dp[i] = max(dp[i], dp[r[x] + 1] + cnt[x]);
    }
    cout << n - dp[0] << endl;
}