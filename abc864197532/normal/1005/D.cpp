#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, X = 864197532, N = 100000, logN = 18, K = 350;

string s;
vector <bool> is;

int solve(int l, int r) {
	int ans = 0;
	for (int i = l; i < r; ++i) {
		if (i >= l + 1 && is[i - 1] && is[i]) {
			if (s[i] + s[i - 1] == '1' + '2') {
				ans++;
				is[i] = false;
				is[i - 1] = false;
			}
		}
		if (i >= l + 2 && is[i - 2] && is[i - 1] && is[i]) {
			if (s[i] == s[i - 1] && s[i - 2] == s[i]) {
				ans++;
				is[i] = false;
				is[i - 1] = false;
				is[i - 2] = false;
			}
		}
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int n = s.length();
	is.assign(n, true);
	fop (i,0,n) {
		s[i] = (s[i] - '0') % 3 + '0';
	}
	int pre = 0, ans = 0;
	fop (i,0,n) {
		if (s[i] == '0') {
			ans += solve(pre, i) + 1;
			pre = i + 1;
		}
	}
	ans += solve(pre, n);
	cout << ans << endl;
}