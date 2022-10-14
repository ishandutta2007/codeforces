#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
const int mod = 1e9 + 7, abc = 864197532, N = 100008, logN = 17, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> tmp;
    vector <pii> A;
    for (int i = 0, x; i < n; ++i) {
        cin >> x, --x;
        if (A.empty() || A.back().X != x) A.eb(x, 1);
        else A.back().Y = min(A.back().Y + 1, 2);
    }
    vector <int> a;
    for (int i = 0; i < A.size(); ++i) for (int j = 0; j < A[i].Y; ++j) a.pb(A[i].X);
    int al = 0;
    vector <int> dp(a.size() + 1, 0), cnt(n, 0), mn(n, 0);
    for (int j = 0; j < a.size(); ++j) {
        int i = a[j];
        mn[i] = min(mn[i], cnt[i] * 2 - al - dp[j]);
        cnt[i]++;
        al++;
        dp[j + 1] = max(dp[j], cnt[i] * 2 - al - mn[i] - 2);
        mn[i] = min(mn[i], cnt[i] * 2 - al - dp[j + 1]);
    }
    cout << al - dp.back() << endl;
}