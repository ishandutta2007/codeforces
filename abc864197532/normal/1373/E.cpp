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
const int mod = 1e9 + 7, x = 864197532, N = 1000007, logN = 20, K = 350;

lli get (int a, int b) {
	if (a < 9 * b) return -1;
	a -= 9 * b;
	lli now = 0;
	if (a < 9) {
		now = a;
	} else {
		a -= 8;
		now = a % 9;
		a -= a % 9;
		while (a) {
			a -= 9;
			now = now * 10 + 9;
		}
		now = now * 10 + 8;
	}
	while (b) {
		b--;
		now = now * 10 + 9;
	}
	return now;
}

void solve() {
	int n, k;
	cin >> n >> k;
	k++;
	lli cur_ans = 1ll << 60;
	/*
	k = 3
	x0
	x1
	x2
	x9
	(x+1)0
	(x+1)1
	f(x + 1) - f(x) = 1, -8, -17
	f(x + 1) = f(x) + 1 - 9a
	all = f(x) * left + f(x + 1) * right
	    = f(x) * (left + right) + right - right * 9 * a = n
	    f(x) = (n + 9 * a * right - right) / k
	*/
	fop (i,0,10) {
		int left = min(k, 10 - i), right = k - left;
		//test(i);
		fop (j,0,20) {
			int all = n + 9 * j * right - right;
			for (int t = i, cnt = 0; cnt < k; ++cnt, t = (t + 1) % 10) all -= t;
			if (~all && all % k == 0) {
				//cout << all << ' ' << k << ' ' << j << endl; 
				lli l = get(all / k, j);
				if (~l) cur_ans = min(cur_ans, l * 10 + i);
			}
		}
	}
	if (cur_ans == 1ll << 60) cur_ans = -1;
	cout << cur_ans << endl; 
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}