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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <string> s(n);
	fop (i,0,n) cin >> s[i];
	if (n == 1) {
		cout << 0 << endl;
	} else if (n == 2) {
		vector <int> c(m, 0);
		fop (i,0,n) fop (j,0,m) c[j] += (s[i][j] == '1');
		int ans = 0;
		fop (i,0,m) ans += (c[i] % 2 == (i & 1));
		cout << min(ans, m - ans) << endl;
	} else if (n == 3) {
		vector <vector <int>> v = {{0, 2}, {1, 3}, {2, 0}, {3, 1}};
		vector <int> a(m, 0);
		fop (i,0,n) fop (j,0,m) if (s[i][j] == '1') a[j] |= (1 << i);
		int ans = 1 << 30;
		fop (i,0,4) {
			int tmp = 0;
			fop (j,0,m) {
				if (j & 1) tmp += min(__builtin_popcount(v[i][0] ^ a[j]), __builtin_popcount(v[i][0] ^ a[j] ^ 7)); 
				else tmp += min(__builtin_popcount(v[i][1] ^ a[j]), __builtin_popcount(v[i][1] ^ a[j] ^ 7));
			}
			ans = min(ans, tmp);
		}
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
}