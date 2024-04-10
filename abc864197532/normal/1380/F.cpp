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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1 << 19, logN = 17, K = 350;

struct mat {
	int val[2][2];
	mat (int a, int b, int c, int d) {
		tie(val[0][0], val[0][1], val[1][0], val[1][1]) = mt(a, b, c, d);
	}
	mat operator * (const mat &other) {
		mat ans(0, 0, 0, 0);
		fop (i,0,2) fop (j,0,2) fop (k,0,2) {
			ans.val[i][j] += (1ll * val[i][k] * other.val[k][j] % mod);
			if (ans.val[i][j] >= mod) ans.val[i][j] -= mod;
		}
		return ans;
	}
	void operator = (const mat &other) {
		fop (i,0,2) fop (j,0,2) val[i][j] = other.val[i][j];
	}
};

vector <mat> tree(2 * N, mat(0, 0, 0, 0));
string s;
int n;

mat get(int i) {
	if (i) {
		return mat(s[i] - '0' + 1, (s[i - 1] == '1' ? 9 - (s[i] - '0') : 0), 1, 0);
	} else {
		return mat(s[i] - '0' + 1, 0, 1, 0);
	}
}

void update(int p) {
	tree[n - p - 1 + N] = get(p);
	for (int i = n - p - 1 + N; i > 1; i >>= 1) tree[i >> 1] = (i & 1 ? tree[i ^ 1] * tree[i] : tree[i] * tree[i ^ 1]);
}

mat query(int l, int r) {
	vector <mat> tmp;
	mat ans(1, 0, 0, 1);
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans = ans * tree[l++];
		if (r & 1) tmp.pb(tree[--r]);
	}
	FOP (i,tmp.size(),0) {
		ans = ans * tmp[i];
	}
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    char d;
    cin >> n >> q >> s;
    fop (i,0,n) tree[N + i] = get(n - i - 1);
    FOP (i,N,0) tree[i] = tree[i << 1] * tree[i << 1 | 1];
    while (q--) {
    	cin >> x >> d;
    	x--;
    	s[x] = d;
    	update(x);
    	if (x + 1 < n) update(x + 1);
    	cout << query(0, n).val[0][0] << '\n';
	}
}