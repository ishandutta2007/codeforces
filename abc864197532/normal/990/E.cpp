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
const int mod = 998244353, x = 864197532, N = 200087, logN = 18, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, tmp;
    cin >> n >> m >> k;
    set <int> s;
    fop (i,0,m) cin >> tmp, s.insert(tmp);
    vector <int> lst(n, -1);
    fop (i,0,n) {
    	if (s.count(i)) {
    		if (i) lst[i] = lst[i - 1];
		} else {
			lst[i] = i;
		}
	}
	lli ans = 1ll << 60;
	fop (i,1,k + 1) {
		cin >> tmp;
		int l = -1, r = 0, cnt = 0;
		while (r < n) {
			int k = lst[r];
			if (k <= l) {
				cnt = -1;
				break;
			}
			tie(l, r) = mp(k, k + i);
			cnt++;
		}
 		if (cnt > -1) ans = min(ans, 1ll * tmp * cnt);
	}
	cout << (ans == 1ll << 60 ? -1 : ans) << endl;
}