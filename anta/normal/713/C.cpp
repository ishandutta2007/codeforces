#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct GetRangeSegmentTree {
	typedef pair<int, int> Val;
	static Val combineVal(const Val &x, const Val &y) { return max(x, y); }
	static void combinesVal(Val &x, const Val &y) { amax(x, y); }
	static Val identityVal() { return make_pair(-INF, -1); }

	vector<Val> nodes;
	int n;
	void init(int n_, const Val &v = Val()) { init(vector<Val>(n_, v)); }
	void init(const vector<Val> &u) {
		n = 1; while(n < (int)u.size()) n *= 2;
		nodes.resize(n);
		nodes.insert(nodes.end(), u.begin(), u.end());
		nodes.resize(n * 2, Val());
		for(int i = n - 1; i > 0; -- i)
			nodes[i] = combineVal(nodes[i * 2], nodes[i * 2 + 1]);
	}
	Val get(int i) {
		return nodes[i + n];
	}
	Val getRange(int l, int r) const {
		Val m = identityVal();
		static int indices[100]; int k = 0;
		for(; l && l + (l&-l) <= r; l += l&-l)
			combinesVal(m, nodes[(n + l) / (l&-l)]);
		for(; l < r; r -= r&-r)
			indices[k ++] = (n + r) / (r&-r) - 1;
		while(-- k >= 0) combinesVal(m, nodes[indices[k]]);
		return m;
	}
	void set(int i, const Val &x) {
		i += n; nodes[i] = x;
		for(i >>= 1; i > 0; i >>= 1)
			nodes[i] = combineVal(nodes[i * 2], nodes[i * 2 + 1]);
	}
};

vector<int> t_parent;
vector<int> t_left, t_right;

void tree_signedeulertour(const vector<vi> &g, int root) {
	int n = g.size();
	t_parent.assign(n, -1);
	t_left.assign(n, -1);
	t_right.assign(n, -1);
	int pos = 0;

	vector<int> stk; stk.push_back(root);
	while(!stk.empty()) {
		int i = stk.back(); stk.pop_back();
		if(i < 0) {
			i = -i - 1;
			pos ++;
			t_right[i] = pos;
			continue;
		}
		t_left[i] = pos;
		pos ++;

		stk.push_back(-(i + 1));
		for(int j = (int)g[i].size() - 1; j >= 0; j --) {
			int c = g[i][j];
			if(t_parent[c] == -1 && c != root)
				stk.push_back(c);
			else
				t_parent[i] = c;
		}
	}
}


int C[100000], depth[100000];

int main() {
	int n;
	while(~scanf("%d", &n)) {
		vector<int> a(n);
		for(int i = 0; i < n; ++ i)
			scanf("%d", &a[i]);

		rep(i, n)
			C[i] = a[n - 1 - i];

		vector<vi> g(n);
		rep(i, n - 1)
			g[i].push_back(i + 1);

		tree_signedeulertour(g, 0);
		depth[0] = 0;
		rep(i, n)
			for(int j : g[i]) depth[j] = depth[i] + 1;

		ll base = 0;
		vector<pii> initseq(n * 2);
		rep(i, n) {
			int c = C[i] + depth[i];
			initseq[t_left[i]] = make_pair(c, t_left[i]);
			initseq[t_right[i] - 1] = make_pair(c, t_right[i] - 1);
			base += c;
		}

		GetRangeSegmentTree segt;
		segt.init(initseq);

		ll sum = 0;
		for(int i = n - 1; i >= 0; i --) {
			pii p = segt.getRange(t_left[i], t_right[i]);
			sum += p.first;
			segt.set(p.second, make_pair(-INF, -1));
		}

		ll ans = sum - base;
		printf("%lld\n", ans);
	}
	return 0;
}