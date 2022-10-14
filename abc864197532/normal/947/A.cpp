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
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 1000087;
const long long mod = 9223372036854775807;
const double eps = 1e-6, Pi = 3.1415926535;
 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	cin >> x;
	int tmp = x;
	vector <int> v[N];
	for (int i = 2; i < N; ++i) {
		if (v[i].size() == 0) {
			for (int j = i; j < N; j += i) {
				v[j].pb(i);
			}
		}
	}
	/*
	x2 >= x1 > p
	x2 % p == 0
	x1 >= x0 > p
	x1 % p == 0
	*/
	set <int> x1;
    int now = tmp;
    int k = v[tmp].back();
	x1.insert(now);
	now--;
	while (now % k != 0) {
		x1.insert(now);
		now--;
	}
	int ans = 864197532;
	for (int i : x1) {
		for (int j : v[i]) if (i != j) {
			ans = min(ans, (i / j - 1) * j + 1);
		}
	}
	cout << ans << endl;
}