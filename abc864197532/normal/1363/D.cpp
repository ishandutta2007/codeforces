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
const int mod = 998244353, x = 864197532, N = 50000;
const double eps = 1e-6, Pi = 3.1415926535;

int ask(vector <int> &s) {
	cout << "? " << s.size();
	for (int i : s) cout << ' ' << i;
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}

int ask2(vector <int> &s, int n) {
	cout << "? " << n - s.size();
	set <int> tmp;
	for (int i : s) tmp.insert(i);
	fop (i,1,n+1) if (!tmp.count(i)) cout << ' ' << i;
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}

void solve() {
	int n, k, tmp;
	cin >> n >> k;
	vector <vector <int>> subset(k);
	vector <int> aa(n + 1);
	fop (i,0,k) {
		cin >> tmp;
		subset[i].resize(tmp);
		fop (j,0,tmp) cin >> subset[i][j], aa[subset[i][j]] = i;
	}
	vector <int> ttmp;
	fop (i,1,n+1) ttmp.pb(i);
	int all = ask(ttmp);
	int l = 1, r = n + 1;
	while (r - l > 1) {
		int mid = l + r >> 1;
		vector <int> tmp;
		fop (i,l,mid) tmp.pb(i);
		int now = ask(tmp);
		if (now != all) {
			l = mid;
		} else {
			r = mid;
		}
	}
	vector <int> ans(k);
	fop (i,0,k) {
		if (aa[l] != i) ans[i] = all;
		else ans[i] = ask2(subset[i], n);
	}
	cout << '!';
	for (int i : ans) cout << ' ' << i;
	cout << endl;
	string ya;
	cin >> ya;
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