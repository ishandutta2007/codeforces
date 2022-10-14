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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500000, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	string s;
    	cin >> s;
    	s.pb('0');
    	vector <int> v;
    	char cur = s[0];
    	int now = 1, n = s.length();
    	fop (i,1,n) {
    		if (cur == s[i]) {
    			now++;
			} else {
				if (cur == '1') v.pb(now);
				cur = s[i];
				now = 1;
			}
		}
		sort(all(v));
		int ans = 0;
		for (int i = v.size() - 1; i >= 0; i -= 2) {
			ans += v[i];
		}
		cout << ans << endl;
    }
}