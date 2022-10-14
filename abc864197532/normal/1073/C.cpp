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
const int mod = 998244353, x = 864197532, N = 1 << 19, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    string s;
	cin >> n >> s >> x >> y;
	int all[4] = {0, 0, 0, 0};
	fop (i,0,n) {
		if (s[i] == 'L') all[0]++;
		if (s[i] == 'R') all[1]++;
		if (s[i] == 'U') all[2]++;
		if (s[i] == 'D') all[3]++;
	}
    if (abs(x) + abs(y) > n || ((n - abs(x) - abs(y)) & 1)) {
    	cout << -1 << endl;
    	return 0;
	}
	auto ask = [&](int len) {
		int all_x = all[1] - all[0], all_y = all[2] - all[3];
		fop (i,0,n) {
			if (s[i] == 'L') all_x++;
			if (s[i] == 'R') all_x--;
			if (s[i] == 'U') all_y--;
			if (s[i] == 'D') all_y++;
			if (i >= len) {
				if (s[i - len] == 'L') all_x--;
				if (s[i - len] == 'R') all_x++;
				if (s[i - len] == 'U') all_y++;
				if (s[i - len] == 'D') all_y--;
			} 
			if (i >= len - 1) {
				if (abs(x - all_x) + abs(y - all_y) <= len) {
					return true;
				}
			}
		}
		return false;
	};
	int l = -1, r = n + 1;
	while (r - l > 1) {
		int mid = l + r >> 1;
		if (ask(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
}