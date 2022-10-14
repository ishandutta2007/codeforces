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
const int mod = 998244353, x = 864197532, N = 500001, logN = 17;

void solve() {
	string s;
	map <char, pii> m1;
	m1['W'] = {1, 0};
	m1['S'] = {-1, 0};
	m1['A'] = {0, -1};
	m1['D'] = {0, 1};
	cin >> s;
	int n = s.length();
	vector <int> x(n + 1, 0), y(n + 1, 0);
	fop (i,0,n) {
		x[i + 1] = x[i] + m1[s[i]].X;
		y[i + 1] = y[i] + m1[s[i]].Y;
	}
	int mxx = *max_element(all(x)), mxy = *max_element(all(y)), mnx = *min_element(all(x)), mny = *min_element(all(y));
	lli ans = 1ll * (mxx - mnx + 1) * (mxy - mny + 1);
	auto f = [&](char c, int m, vector <int> x) {
		int i = 1;
		while (i < n + 1 && x[i] != m) i++;
		string t = s.substr(0, i - 1) + c + s.substr(i - 1);
		//cout << t << endl;
		vector <int> nx(n + 2, 0), ny(n + 2, 0);
		fop (i,0,n + 1) {
			nx[i + 1] = nx[i] + m1[t[i]].X;
			ny[i + 1] = ny[i] + m1[t[i]].Y;
		}
		int mxx1 = *max_element(all(nx)), mxy1 = *max_element(all(ny)), mnx1 = *min_element(all(nx)), mny1 = *min_element(all(ny));
		//cout << 1ll * (mxx1 - mnx1 + 1) * (mxy1 - mny1 + 1) << endl; 
		return 1ll * (mxx1 - mnx1 + 1) * (mxy1 - mny1 + 1); 
	};
	ans = min(ans, f('W', mnx, x));
	ans = min(ans, f('S', mxx, x));
	ans = min(ans, f('A', mxy, y));
	ans = min(ans, f('D', mny, y));
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