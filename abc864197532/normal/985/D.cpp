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
const int mod = 998244353, x = 864197532, N = 300000, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n, h;
    cin >> n >> h;
    /*
    h = 3
    2321
    23321
    234321
    2344321
    34321
    */
    function<long long(long long)>solve = [&](lli l) {
    	if (l <= h) {
    		return l * (l + 1) / 2;
		} else {
			if (l % 2 == h % 2) {
				lli x = (l - h) / 2;
				return (h + x) * (h + x) - h * (h - 1) / 2;
			} else {
				return solve(l - 1) + (l + h - 1) / 2;
			}
		}
	};
	lli l = 0, r = 1ll << 31;
	while (r - l > 1) {
		lli mid = l + r >> 1;
		if (solve(mid) >= n) r = mid;
		else l = mid;
	}
	cout << r << endl;
}