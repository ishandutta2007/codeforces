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
const int mod = 998244353, x = 864197532, N = 200000, logN = 18, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	string s;
    	cin >> s;
    	int n = s.length();
    	vector <int> cnt(10, 0);
    	fop (i,0,n) {
    		cnt[s[i] - '0']++;
		}
		int ans = 0;
		fop (i,0,10) ans = max(ans, cnt[i]);
		int c = 0;
		fop (i,0,10) fop (j,0,10) if (i != j) {
			int tmp = 0;
			c = 0;
			fop (now,0,n) {
				if (c) {
					if (s[now] == '0' + i) {
						tmp++;
						c ^= 1;
					}
				} else {
					if (s[now] == '0' + j) {
						tmp++;
						c ^= 1;
					}
				}
			}
			if (tmp & 1) tmp--; 
			ans = max(ans, tmp);
		}
		cout << n - ans << endl;
	}
}