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
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

vector <lli> sum1, sum2;

void solve(vector <int> &a, int from, int d) {
	if (d == 0) return; 
	solve(a, from, d - 1);
	solve(a, from + (1 << d - 1), d - 1);
	vector <int> tmp;
	for (int i = from, j = from + (1 << d - 1); i < from + (1 << d - 1); i++) {
		while (j < from + (1 << d) and a[i] > a[j]) j++;
		sum1[d - 1] += j - from - (1 << d - 1);
	}
	// 35 47
	for (int i = from, j = from + (1 << d - 1); i < from + (1 << d - 1); i++) {
		while (j < from + (1 << d) and a[i] >= a[j]) j++;
		sum2[d - 1] += (1 << d - 1) - (j - from - (1 << d - 1));
	}
	int i, j;
	for (i = from, j = from + (1 << d - 1); i < from + (1 << d - 1) and j < from + (1 << d);) {
		if (a[i] < a[j]) {
			tmp.pb(a[i++]);
		} else {
			tmp.pb(a[j++]);
		}
	}
	while (i < from + (1 << d - 1)) tmp.pb(a[i++]);
	while (j < from + (1 << d)) tmp.pb(a[j++]);
	for (i = from; i < from + (1 << d); ++i) a[i] = tmp[i - from];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	sum1.resize(n, 0);
	sum2.resize(n, 0);
	int m = 1 << n;
	vector <int> a(m);
	fop (i,0,m) cin >> a[i];
	solve(a, 0, n);
	int q, x;
	cin >> q;
	vector <int> now(n, 0);
	while (q--) {
		cin >> x;
		fop (i,0,x) now[i] ^= 1;
		lli ans = 0;
		fop (i,0,n) {
			if (now[i]) ans += sum2[i];
			else ans += sum1[i];
		}
		cout << ans << '\n';
	}
}