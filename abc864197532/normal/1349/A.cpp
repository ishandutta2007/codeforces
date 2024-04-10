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
const int mod = 998244353, x = 864197532, N = 200087, logN = 17;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    vector <int> minn[N];
    fop (i,0,n) {
    	cin >> tmp;
    	vector <pii> ttmp;
    	for (int i = 2; i * i <= tmp; ++i) {
    		if (tmp % i == 0) {
    			ttmp.pb({i, 0});
    			while (tmp % i == 0) {
    				tmp /= i;
    				ttmp.back().Y++;
				}
			}
		}
		if (tmp > 1) minn[tmp].pb(1);
		for (auto A : ttmp) {
			minn[A.X].push_back(A.Y);
		}
	}
	lli ans = 1;
	fop (i,0,N) {
		if (minn[i].size() <= n - 2) continue;
		if (minn[i].size() == n - 1) minn[i].pb(0);
		sort(minn[i].begin(), minn[i].end());
		while (minn[i][1]--) ans *= i;
	}
	cout << ans << endl;
}