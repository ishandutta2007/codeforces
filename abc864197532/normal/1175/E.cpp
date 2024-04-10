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
const int mod = 1e9 + 7, x = 864197532, N = 500007, logN = 20, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, l, r;
    cin >> n >> q;
    int seg[N][logN];
    fop (i,0,N) seg[i][0] = i;
    fop (i,0,n) {
    	cin >> l >> r;
    	seg[l][0] = max(seg[l][0], r);
	}
	fop (i,1,N) seg[i][0] = max(seg[i][0], seg[i - 1][0]);
	fop (i,1,logN) fop (j,0,N) {
		seg[j][i] = seg[seg[j][i - 1]][i - 1];
	}
	while (q--) {
		cin >> l >> r;
		int ans = 0;
		FOP (i,logN,0) {
			if (seg[l][i] < r) {
				ans += (1 << i);
				l = seg[l][i];
			}
		}
		if (seg[l][0] < r) ans = -2;
		cout << ans + 1 << endl;
	}
}