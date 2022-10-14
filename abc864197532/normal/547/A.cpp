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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 350;

int main () {
	lli m, h1, a1, x1, y1, h2, a2, x2, y2, sza = 0, szb = 0, cya, cyb, la, lb;
	cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
	lli h11 = h1, h22 = h2;
	vector <int> A(m, -1), B(m, -1);
	A[h1] = sza++;
	vector <int> aa, bb;
	aa.pb(h1);
	while (true) {
		lli h = (h1 * x1 + y1) % m;
		if (~A[h]) {
			cya = h;
			break;
		}
		aa.pb(h);
		A[h] = sza++;
		h1 = h;
	}
	B[h2] = szb++;
	bb.pb(h2);
	while (true) {
		lli h = (h2 * x2 + y2) % m;
		if (~B[h]) {
			cyb = h;
			break;
		}
		bb.pb(h);
		B[h] = szb++;
		h2 = h;
	}
	if (A[a1] == -1 || B[a2] == -1) {
		cout << -1 << endl;
		return 0;
	}
	bool is = false;
	int cnt = 0;
	for (int i : aa) {
		if (i == cya) is = true;
		if (is && i == a1) cnt++;
	}
	is = false;
	for (int i : bb) {
		if (i == cyb) is = true;
		if (is && i == a2) cnt++;
	}
	if (cnt == 2) {
		fop (i,0,m) {
			lli cur = (sza - A[cya]) * i + A[a1];
			if (cur >= B[a2] && cur % (szb - B[cyb]) == B[a2] % (szb - B[cyb])) {
				cout << cur << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	} else {
		fop (i,0,m) {
			h11 = (h11 * x1 + y1) % m;
			h22 = (h22 * x2 + y2) % m;
			if (h11 == a1 && h22 == a2) {
				cout << i + 1 << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	}
}