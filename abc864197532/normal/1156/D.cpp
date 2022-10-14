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
const int mod = 998244353, x = 864197532, N = 200087, logN = 18, K = 350;

struct Dsu {
	int n;
	vector <int> dsu, size;
	Dsu (int n): n(n) {
		dsu.resize(n);
		size.resize(n);
		for (int i = 0; i < n; ++i) {
			dsu[i] = i;
			size[i] = 1;
		}
	}
	int Find(int a) {
		if (dsu[a] == a) return a;
		return dsu[a] = Find(dsu[a]);
	}
	bool Union(int a, int b) {
		int x = Find(a), y = Find(b);
		if (x == y) return false;
		if (size[x] < size[y]) swap(x, y);
		dsu[y] = x;
		size[x] += size[y];
		size[y] = 0;
		return true;
	}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v, w;
    cin >> n;
    Dsu dsu0(n), dsu1(n);
    vector <int> has(n, 0);
    fop (i,0,n - 1) {
    	cin >> u >> v >> w;
    	u--; v--;
    	if (w) dsu1.Union(u, v), has[u] |= 2, has[v] |= 2;
    	else dsu0.Union(u, v), has[u] |= 1, has[v] |= 1;
	}
	lli ans = 0;
	fop (i,0,n) ans += 1ll * dsu0.size[i] * (dsu0.size[i] - 1);
	fop (i,0,n) ans += 1ll * dsu1.size[i] * (dsu1.size[i] - 1);
	fop (i,0,n) if (has[i] == 3) ans += 1ll * (dsu0.size[dsu0.Find(i)] - 1) * (dsu1.size[dsu1.Find(i)] - 1);
	cout << ans << endl;
}