#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 2000, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, k;
    	cin >> n >> k;
    	lli a[n];
    	fop (i,0,n) cin >> a[i];
    	sort(a, a + n);
    	lli b[k];
    	fop (i,0,k) cin >> b[i];
    	sort(b, b + k);
    	int i = 0, now = n - 1;
    	lli ans = 0;
    	while (i < k && b[i] == 1) {
    		ans += a[now--] * 2;
    		i++;
		}
		fop (j,i,k) {
			ans += a[now--];
		}
		fop (j,i,k) {
			int t = b[j];
			while (b[j] > 2) now--, b[j]--;
			ans += a[now--];
		}
		cout << ans << endl;
	}
}