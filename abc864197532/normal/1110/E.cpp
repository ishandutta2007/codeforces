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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 18, K = 350;

vector <int> cnt;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	lli a[n], b[n];
	vector <int> v1, v2;
	fop (i,0,n) {
		cin >> a[i];
		if (i) v1.pb(a[i] - a[i - 1]);
	}
	fop (i,0,n) {
		cin >> b[i];
		if (i) v2.pb(b[i] - b[i - 1]);
	}
	if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
		cout << "NO\n";
		return 0; 
	}
	sort(all(v1));
	sort(all(v2));
	cout << (v1 == v2 ? "YES" : "NO") << endl;
}