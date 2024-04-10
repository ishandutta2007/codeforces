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
const int mod = 998244353, x = 864197532, N = 200087, logN = 17;

void solve () {
	int n, k;
	cin >> n >> k;
	vector <int> pos, a(n), cha(n);
	pos.pb(-1);
	bool is = false;
	fop (i,0,n) {
		cin >> a[i];
		if (a[i] >= k) pos.pb(i);
		if (a[i] == k) is = true;
		if (a[i] >= k) cha[i] = 1;
		else cha[i] = -1;
	}
	if (!is) {
		cout << "NO\n";
		return;
	}
	if (n == 1) {
		if (a[0] == k) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}
	pos.pb(n);
	fop (i,1,pos.size() - 2) {
		if (pos[i] + 1 == pos[i + 1]) {
			cout << "YES\n";
			return;
		}
	}
	fop (i,1,pos.size() - 1) {
		int now = -x, tmp = 0, now2 = -x;
		FOP (j,pos[i], pos[i - 1] + 1) {
			tmp += cha[j];
			now = max(now, tmp);
		}
		tmp = 0;
		fop (j,pos[i] + 1, pos[i + 1]) {
			tmp += cha[j];
			now2 = max(now2, tmp);
		}
		if (now >= 0 or now2 >= 0) {
			cout << "YES\n";
			return;
		}
		if (i != pos.size() - 2 and tmp >= -1) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
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