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
    	string s;
    	int n;
    	cin >> s >> n;
    	vector <int> cnt(26, 0);
    	fop (i,0,s.length()) cnt[s[i] - 'a']++;
		vector <int> a(n);
    	fop (i,0,n) cin >> a[i];
    	int now = 25;
		vector <int> ans(n, -1);
    	while (count(all(ans), -1)) {
    		vector <int> v;
    		fop (j,0,n) {
    			if (a[j] == 0 && ans[j] == -1) v.pb(j);
			}
			while (cnt[now] < v.size()) {
				now--;
			}
			for (int j : v) ans[j] = now;
			fop (i,0,n) {
				for (int j : v) if (i != j) {
					a[i] -= abs(i - j);
				}
			}
			now--;
		}
		fop (i,0,n) cout << char(ans[i] + 'a');
		cout << endl;
	}
}