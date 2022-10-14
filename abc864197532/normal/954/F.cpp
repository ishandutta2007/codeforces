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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17, K = 350;

struct mat {
	vector <vector <lli>> v;
	mat () {
		v.assign(3, vector <lli>(3, 0));
	}
	mat operator * (const mat &b) {
		mat ans;
		fop (i,0,3) fop (j,0,3) fop (k,0,3) {
			ans.v[i][j] = (ans.v[i][j] + v[i][k] * b.v[k][j]) % mod;
		}
		return ans;
	}
};


mat mpow (mat cur, lli k) {
	mat ans;
	fop (i,0,3) ans.v[i][i] = 1;
	for (; k; k >>= 1, cur = cur * cur) {
		if (k & 1) ans = ans * cur;
	}
	return ans;
}

struct obs {
	lli i, l, r;
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <vector <lli>> cur = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
	mat cal[8];
	fop (i,0,8) {
		vector <vector <lli>> tmp = cur;
		fop (j,0,3) if (i & (1 << j)) {
			tmp[j][0] = tmp[j][1] = tmp[j][2] = 0;
		}
		cal[i].v = tmp;
	}
	int n;
	lli m;
	cin >> n >> m;
	vector <obs> q(n);
	vector <pll> v;
	fop (i,0,n) cin >> q[i].i >> q[i].l >> q[i].r, v.eb(q[i].l - 1, -q[i].i), v.eb(q[i].r, q[i].i);
	sort(all(v));
	reverse(all(v));
	lli pre = m;
	vector <int> cnt(3, 0);
	mat ans;
	fop (i,0,3) ans.v[i][i] = 1;
	for (auto A : v) {
		int a = 0;
		fop (i,0,3) if (cnt[i]) a |= (1 << i);
		ans = ans * mpow(cal[a], pre - A.X);
		pre = A.X;
		if (A.Y > 0) cnt[A.Y - 1]++;
		else cnt[-A.Y - 1]--;
	}
	int a = 0;
	fop (i,0,3) if (cnt[i]) a |= (1 << i);
	ans = ans * mpow(cal[a], pre - 1);
	cout << ans.v[1][1] << endl;
}