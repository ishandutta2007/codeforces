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
const int mod = 998244353, x = 864197532, N = 500087, logN = 18, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, tmp;
    cin >> n >> k;
    vector <int> pre(n + 1, 0), num[N];
    fop (i,0,n) {
    	cin >> tmp;
    	num[tmp].pb(i + 1);
    	pre[i + 1] = pre[i] + (tmp == k);
	}
	int ans = pre[n];
	fop (i,1,N) if (i != k) {
		tmp = 0;
		fop (j,0,num[i].size()) {
			if (!j) {
				tmp -= pre[num[i][j]];
			} else {
				tmp -= (pre[num[i][j]] - pre[num[i][j - 1]]);
			}
			if (tmp < 0) tmp = 0;
			tmp++;
			ans = max(ans, pre[n] + tmp);
		}
	}
	cout << ans << endl;
}