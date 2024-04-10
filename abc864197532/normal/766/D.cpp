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
const int mod = 1e9 + 7, x = 864197532, N = 100007, logN = 17, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

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
        bool same (int u, int v) {
                return Find(u) == Find(v);
        }
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q, a;
	cin >> n >> m >> q;
	string s, t;
	map <string, int> name;
	fop (i,0,n) cin >> s, name[s] = i;
	Dsu dsu(2 * n);
	fop (i,0,m) {
		cin >> a >> s >> t;
		int u = name[s], v = name[t];
		if (a == 1) {
			if (dsu.same(u, n + v)) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
				dsu.Union(u, v);
                                dsu.Union(u + n, v + n);
			}
		} else {
			if (dsu.same(u, v)) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
				dsu.Union(u, n + v);
                                dsu.Union(u + n, v);
			}
		}
	}
	while (q--) {
		cin >> s >> t;
		int u = name[s], v = name[t];
		if (dsu.same(u, v)) {
			cout << "1\n";
		} else if (dsu.same(u, v + n)) {
			cout << "2\n";
		} else {
			cout << "3\n";
		}
	}
}