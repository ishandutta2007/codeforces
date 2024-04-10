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
const int mod = 1e9 + 7, x = 864197532, N = 2000001, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> cnt(n + 1, 0), l(q), r(q);
    fop (i,0,q) {
    	cin >> l[i] >> r[i];
    	fop (j,l[i],r[i]+1) cnt[j]++;
	}
	int ans = 0;
	fop (i,0,q) {
		vector <int> pos;
		int tmp = 0;
		fop (j,l[i],r[i]+1) cnt[j]--;
		fop (i,1,n + 1) if (cnt[i] == 1) pos.pb(i);
		fop (i,1,n + 1) tmp += (cnt[i] > 0);
	//////	printv(cnt);
		fop (j,i + 1,q) {
			int aa = upper_bound(all(pos), r[j]) - lower_bound(all(pos), l[j]);
			//cout << i << ' ' << j << ' ' << aa << endl;
			ans = max(ans, tmp - aa);
		}
		fop (j,l[i],r[i] + 1) cnt[j]++;
	}
	cout << ans << endl;
}