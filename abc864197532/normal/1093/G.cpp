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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 50, logN = 17, K = 350;

int k;

struct Seg {
	int l, r, m;
	vector <int> val;
	vector <lli> mn, mx;
	Seg* ch[2];
	Seg (int _l, int _r, vector <vector <int>> &a) : l(_l), r(_r), m(l + r >> 1) {
		mn.resize(1 << k); mx.resize(1 << k);
		if (r - l == 1) {
			val = a[l];
			set_leaf();
		} else {
			ch[0] = new Seg(l, m, a);
			ch[1] = new Seg(m, r, a);
			pull();
		}
	}
	void set_leaf() {
		fop (s,0,1 << k) {
			mn[s] = mx[s] = 0;
			fop (i,0,k) mn[s] += val[i] * (s & (1 << i) ? 1 : -1);
			mx[s] = mn[s];
		}
	}
	void set (int p, vector <int> &a) {
		if (r - l == 1) {
			val = a;
			set_leaf();
		} else {
			ch[p >= m]->set(p, a);
			pull(); 
		}
	}
	void pull() {
		fop (s,0,1 << k) {
			mn[s] = min(ch[0]->mn[s], ch[1]->mn[s]);
			mx[s] = max(ch[0]->mx[s], ch[1]->mx[s]);
		}
	}
	pll query(int a, int b, int s) {
		if (a <= l && r <= b) return mp(mn[s], mx[s]);
		pll ans = mp(1ll << 60, -1ll << 60);
		if (a < m) {
			pll tmp = ch[0]->query(a, b, s);
			ans.X = min(ans.X, tmp.X);
			ans.Y = max(ans.Y, tmp.Y);
		}
		if (m < b) {
			pll tmp = ch[1]->query(a, b, s);
			ans.X = min(ans.X, tmp.X);
			ans.Y = max(ans.Y, tmp.Y);
		}
		return ans;
	}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, p, l, r, t;
    cin >> n >> k;
    vector <vector <int>> v(n);
    fop (i,0,n) {
    	v[i].resize(k);
    	fop (j,0,k) cin >> v[i][j];
	}
	Seg root(0, n, v);
	cin >> q;
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> p; p--;
			vector <int> tmp(k);
			fop (i,0,k) cin >> tmp[i];
			root.set(p, tmp);
		} else {
			cin >> l >> r; l--;
			lli ans = 0;
			fop (s,0,1 << k) {
				pll tmp = root.query(l, r, s);
				ans = max(ans, tmp.Y - tmp.X);
			}
			cout << ans << endl;
		}
	}
}