#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;
const double eps = 1e-11;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	lli ttmp;
	cin >> n >> m >> ttmp;
	int a[m];
	lli all = 0;
	fop (i,0,m) {
		cin >> a[i];
		all += a[i];
	}
	sort(a, a + m);
	int ans = 0;
	fop (i,0,n + 1) {
		lli t = ttmp;
		int tmp = 0;
		if (t >= all * i) {
			t -= all * i;
			tmp += (m + 1) * i;
			fop (ii,0,m) {
				fop (j,0,n - i) {
					if (t >= a[ii]) {
						t -= a[ii];
						tmp++;
					}
				}
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
}