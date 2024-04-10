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
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500007;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s[n];
	fop (i,0,n) cin >> s[i];
	int count[n][m];
	fop (i,0,n) {
		FOP (j,m,0) {
			count[i][j] = (s[i][j] == '1' ? (j == m - 1 ? 1 : count[i][j + 1] + 1) : 0);
		}
	}
	int ans = 0;
	fop (i,0,m) {
		vector <int> tmp(n);
		fop (j,0,n) tmp[j] = count[j][i];
		sort(all(tmp));
		FOP (j,n,0) {
			ans = max(ans, tmp[j] * (n - j));
		}
	}
	cout << ans << endl;
}