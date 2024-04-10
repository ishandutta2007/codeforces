#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 8000, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    string s;
    cin >> n >> p >> s; p--;
    lli tmp = 0;
	FOP (i,n / 2, 0) tmp += min(26 - abs(s[i] - s[n - i - 1]), abs(s[i] - s[n - i - 1]));
	if (tmp == 0) {
		cout << tmp << endl;
		return 0;
	}
	lli ans = 1 << 30;
	lli left = 0, right = (n - 1) / 2;
	for (; s[left] == s[n - left - 1]; ++left);
	for (; s[right] == s[n - right - 1]; --right);
	if (left <= p && p <= right) {
		ans = min(ans, min(p - left, right - p) + (right - left));
	} else {
		if (right < p) {
			ans = min(ans, p - left);
		} else {
			ans = min(ans, right - p);
		}
	}
	left = n - left - 1;
	right = n - right - 1;
	swap(left, right);
	if (left <= p && p <= right) {
		ans = min(ans, min(p - left, right - p) + (right - left));
	} else {
		if (right < p) {
			ans = min(ans, p - left);
		} else {
			ans = min(ans, right - p);
		}
	}
	cout << ans + tmp << endl;
}