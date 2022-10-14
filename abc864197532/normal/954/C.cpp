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
const int mod = 1e9 + 7, x = 864197532, N = 1000, logN = 18, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	fop (i,0,n) cin >> a[i];
	set <int> s;
	fop (i,1,n) {
		s.insert(abs(a[i] - a[i - 1]));
	}
	if (s.count(0)) {
		cout << "NO\n";
		return 0;
	}
	int mx = 1e9;
	s.erase(1);
	if (s.empty()) {
		cout << "YES\n" << mx << ' ' << 1 << endl;
	} else if (s.size() == 1) {
		int y = *s.begin();
		fop (i,0,n) a[i]--;
		fop (i,1,n) {
			if (a[i] / y != a[i - 1] / y && a[i] % y != a[i - 1] % y) {
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n" << mx << ' ' << y << endl;
	} else {
		cout << "NO\n";
	}
}