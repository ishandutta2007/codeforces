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
const int mod = 1e9 + 7, x = 864197532, N = 2000, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, k;
    	string s;
    	cin >> n >> k >> s;
    	int pre[n + 1];
    	pre[0] = 0;
  		fop (i,0,n) {
			pre[i + 1] = pre[i] + (s[i] == '1');
		}
		bool pos[n];
		fop (i,0,n) pos[i] = false;
		fop (i,0,n) if (s[i] == '0') {
			int r = min(i + k + 1, n), l = max(i - k, 0);
			if (pre[r] - pre[l] == 0) {
				pos[i] = true;
			}
		}
		vector <int> v;
		fop (i,0,n) if (pos[i]) {
			if (v.empty() || i - v.back() > k) {
				v.pb(i);
			}
		}
		cout << v.size() << endl;
	}
}