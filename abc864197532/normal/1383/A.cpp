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
const int mod = 1e9 + 7, x = 864197532, N = 2500, logN = 17, K = 350;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	fop (i,0,n) {
		if (s[i] > t[i]) {
			cout << "-1\n";
			return;
		}
	}
	int cnt[20][20];
	fop (i,0,20) fop(j,0,20) cnt[i][j] = 0;
	fop (i,0,n) if (s[i] != t[i]) cnt[s[i] - 'a'][t[i] - 'a']++;
	int ans = 0;
	fop (i,0,20) {
		int p = -1;
		fop (j,0,20) {
			if (cnt[i][j] > 0) {
				p = j;
				break;
			}
		}
		if (~p) {
			ans++;
			fop (j,0,20) {
				if (p != j) cnt[p][j] += cnt[i][j];
				cnt[i][j] = 0;
			}
		}
	}
	cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	solve();
	}
}