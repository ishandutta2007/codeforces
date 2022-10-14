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
const int mod = 998244353, x = 864197532, N = 100, logN = 17;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		fop (i,0,n) cin >> a[i];
		int ans1 = a[0], ans2 = 0, now = a[0], i = 1, j = n - 1, s = 1;
		while (i <= j) {
			int tmp = 0;
			while (i <= j and tmp <= now) {
				if (tmp == 0) s++;
				tmp += a[j];
				j--;
			}
			ans2 += tmp;
			now = tmp;
			tmp = 0;
			while (i <= j and tmp <= now) {
				if (tmp == 0) s++;
				tmp += a[i];
				i++;
			}
			ans1 += tmp;
			now = tmp;
			tmp = 0;
		}
		cout << s << ' ' << ans1 << ' ' << ans2 << endl;
	}
}