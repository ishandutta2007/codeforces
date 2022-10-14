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
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087;

void solve() {
	int n, k, c = 0;
	string s;
	cin >> n >> k >> s;
	vector <int> cnt(26, 0);
	fop (i,0,n) cnt[s[i] - 'a']++;
	sort(all(s));
	string ans;
	int now = 0;
	fop (i,0,26) {
		if (cnt[i] and ans.size() == 0) ans.pb(char('a' + i));
		now += cnt[i];
		if (now >= k) {
			cnt[i] = now - k;
			if (ans[0] - 'a' != i) {
				cout << char('a' + i) << endl;
				return;
			}
			break;
		} else {
			cnt[i] = 0;
		}
	}
	fop (i,0,26) if (cnt[i]) c++;
	if (c == 0) {
		cout << ans << endl;
	} else if (c == 1) {
		int id = -1;
		fop (i,0,26) if (cnt[i]) id = i;
		cout << ans;
		fop (i,0,(cnt[id] + k - 1) / k) cout << char('a' + id);
	} else {
		cout << ans;
		fop (i,0,26) fop (j,0,cnt[i]) cout << char('a' + i);
	} 
	cout << endl;
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