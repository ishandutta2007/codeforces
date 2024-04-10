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
    int n;
    string s, t;
    cin >> n >> s >> t;
    /*
    0 1 -1 -1 1 -1 1 1 -1
    */
    set <int> a[2];
    fop (i,0,n) {
    	if (s[i] == '0' && t[i] == '1') a[0].insert(i);
    	if (s[i] == '1' && t[i] == '0') a[1].insert(i);
	}
	if (a[0].size() != a[1].size()) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	while (!a[0].empty() && !a[1].empty()) {
		int now = 0, all = 1, cur;
		if (*a[0].begin() < *a[1].begin()) {
			now = *a[0].begin();
			a[0].erase(a[0].begin());
			cur = 1;
		} else {
			now = *a[1].begin();
			a[1].erase(a[1].begin());
			cur = 0;
		}
		while (true) {
			auto it = a[cur].lower_bound(now);
			if (it == a[cur].end()) {
				if (all % 2 == 1) {
					a[cur ^ 1].insert(now);
				}
				break;
			} else {
				all++;
				now = *it;
				a[cur].erase(it);
				cur ^= 1;
			}
		}
		assert(a[0].size() == a[1].size());
		++ans;
	}
	cout << ans << endl;
}