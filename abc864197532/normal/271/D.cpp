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
const int x = 864197532, N = 50000, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const double eps = 1e-6, Pi = 3.1415926535;
 
lli v[26][2];
 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fop (i,0,26) fop (j,0,2) v[i][j] = uniform_int_distribution<int>(1, x - 87)(rng);
	string s, t;
	int k;
	cin >> s >> t >> k;
	int n = s.length();
	set <pll> ans;
	fop (i,0,n) {
		string tmp = "";
		int now = 0;
		lli aa = 0, bb = 0;
		fop (j,i,n) {
			tmp += s[j];
			if (t[s[j] - 'a'] == '0') now++;
			if (now > k) break;
			aa = ((aa * x) + v[s[j] - 'a'][0]) % mod1;
			bb = ((bb * x) + v[s[j] - 'a'][1]) % mod2;
			ans.insert({aa, bb});
		}
	}
	cout << int(ans.size()) << endl;
}