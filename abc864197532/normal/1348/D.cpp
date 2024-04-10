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
	int n;
	cin >> n;
	int k = 0;
	while (n >= (1 << k)) k++;
	int aa = (1 << k) - n - 1;
	k--;
	vector <int> ans(k, 0);
	fop (i,0,k) ans[i] = 1 << i;
	while (ans[k - 1] < aa) {
		aa -= ans[k - 1];
		ans[k - 1] = 0;
		FOP (i,k - 1,0) {
			if (ans[i] < aa) {
				aa -= ans[i];
				swap(ans[i], ans[i + 1]);
			} else {
				ans[i] -= aa;
				ans[i + 1] += aa;
				aa = 0;
				break;
			}
		}
		if (aa == 0) break;
	}
	ans[k - 1] -= aa;
	cout << k << endl;
	for (int i : ans) cout << i << ' ';
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