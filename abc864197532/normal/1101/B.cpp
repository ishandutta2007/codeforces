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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int l = 0, r = n - 1, a = 0;
    while (l < n && a < 3) {
    	if (a == 1 && s[l] == ':') {
    		a |= 2;
		}
		if (a == 0 && s[l] == '[') {
			a |= 1;
		}
		l++;
	}
	a = 0;
	while (r >= 0 && a < 3) {
		if (a == 1 && s[r] == ':') {
			a |= 2;
		} 
		if (a == 0 && s[r] == ']') {
			a |= 1;
		}
		r--;
	}
	if (l - 1 > r) cout << -1 << endl;
	else {
		int ans = 0;
		fop (i,l,r + 1) ans += (s[i] == '|');
		cout << ans + 4 << endl;
	}
}