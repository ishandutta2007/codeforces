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

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string input[n];
		fop (i,0,n) cin >> input[i];
		bool is[n][n];
		fop (i,0,n) fop (j,0,n) is[i][j] = (i == n - 1 or j == n - 1);
		FOP (i,n,0) {
			FOP (j,n,0) {
				if (is[i][j] and input[i][j] == '1') {
					if (i) is[i - 1][j] = true;
					if (j) is[i][j - 1] = true;
				}
			}
		}
		bool iss = true;
		fop (i,0,n) fop (j,0,n) {
			if (input[i][j] == '1' and !is[i][j]) iss = false; 
		}
		cout << (iss ? "YES\n" : "NO\n");
	}
}