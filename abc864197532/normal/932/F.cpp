#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

struct Line {
	long long m, k; // y = mx + k
	long long v(int x) {
		return 1ll * m * x + k;
	}
};

struct LiChao {
	int l, r, m;
	vector <Line> v;
	Line line;
	LiChao* ch[2] = {NULL, NULL};
	LiChao (int l, int r) : l(l), r(r), m(l + r >> 1) {
		line.m = 0;
		line.k = 1ll << 60;
	} 
	void insert(Line seg) {
		if (r - l == 1) {
			if (seg.v(l) < line.v(l)) {
				line = seg;
			}
		} else {
		    if (m == 0) v.pb(seg);
			if (line.m > seg.m) swap(seg, line);
			if (line.v(m) > seg.v(m)) {
				swap(seg, line);
				if (!ch[1]) ch[1] = new LiChao(m, r);
				ch[1]->insert(seg);
			} else {
				if (!ch[0]) ch[0] = new LiChao(l, m);
				ch[0]->insert(seg);
			}
		}
	}
	long long query(int x) {
		if (r - l == 1) return line.v(x);
		if (x < m and ch[0]) return min(ch[0]->query(x), line.v(x));
		else if (x >= m and ch[1]) return min(ch[1]->query(x), line.v(x));
		else return line.v(x);
	}
	void erase() {
	    if (ch[0]) {
	        if (ch[0]->r - ch[0]->l != 1) ch[0]->erase();
	        delete ch[0];
	    }
	    if (ch[1]) {
	        if (ch[1]->r - ch[1]->l != 1) ch[1]->erase();
	        delete ch[1];
	    }
	}
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	long long dp[n];
	int a[n], b[n], aa, bb;
	vector <int> nums[n];
	fop (i,0,n) cin >> a[i];
	fop (i,0,n) cin >> b[i];
	fop (i,0,n-1) {
		cin >> aa >> bb;
		nums[aa-1].pb(bb-1);
		nums[bb-1].pb(aa-1);
	}
	/* dp[i] = dp[j] + b_j * a_i*/
	LiChao* root[n];
	fop (i,0,n) root[i] = new LiChao(-100004, 100004);
	
	function <void(int, int)> merge = [&](int a, int b) {
	    if (root[a]->v.size() < root[b]->v.size()) swap(root[a], root[b]);
	    for (Line A : root[b]->v) {
	        root[a]->insert(A);
	    }
	    root[b]->erase();
	};
	
	function <void(int, int)> dfs = [&](int n, int pa) {
	    bool is = true;
		for (int i : nums[n]) {
			if (i == pa) continue;
			dfs(i, n);
			merge(n, i);
			is = false;
		}
		dp[n] = is ? 0 : root[n]->query(a[n]);
		root[n]->insert({b[n], dp[n]});
	};
	
	dfs(0, -1);
	fop (i,0,n) cout << dp[i] << " \n"[i == n - 1];
}