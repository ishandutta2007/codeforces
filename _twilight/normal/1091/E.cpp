#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const signed ll llf = (signed ll) (~0ull >> 1);

typedef class SegTreeNode {
	public:
		int cnt;
		ll sum;
		SegTreeNode *l, *r;

		SegTreeNode() : cnt(0), sum(0), l(NULL), r(NULL) {}

		void pushUp() {
			cnt = l->cnt + r->cnt;
			sum = l->sum + r->sum;
		}
} SegTreeNode;

const int Lim = 5e5 + 5;

SegTreeNode pool[Lim << 1];
SegTreeNode *top = pool;

SegTreeNode* newnode() {
	return top++;
}

typedef class SegTree {
	public:
		int n;
		SegTreeNode* rt;

		SegTree() : rt(NULL) {	}
		SegTree(int n) : n(n) {
			build(rt, 0, n);
		}

		void build(SegTreeNode*& p, int l, int r) {
			p = newnode();
			if (l == r)
				return;
			int mid = (l + r) >> 1;
			build(p->l, l, mid);
			build(p->r, mid + 1, r);
		}

		void update(SegTreeNode* p, int l, int r, int idx) {
			if (l == r) {
				p->cnt++;
				p->sum += l;
				return;
			}
			int mid = (l + r) >> 1;
			if (idx <= mid)
				update(p->l, l, mid, idx);
			else
				update(p->r, mid + 1, r, idx);
			p->pushUp();
		}

		ll query(SegTreeNode* p, int l, int r, int k) {
			if (r <= k)
				return p->sum;
			if (l > k)
				return p->cnt * 1ll * k;
			int mid = (l + r) >> 1;
			return query(p->l, l, mid, k) + query(p->r, mid + 1, r, k);
		}

		void update(int val) {
			update(rt, 0, n, val);
		} 

		ll query(int k) {
			return query(rt, 0, n, k);
		}
} SegTree;

int n;
int *d;
int parity = 0;
ll *pd, *sd, *sdr, *msd, *rmsd;
SegTree st;

inline void init() {
	scanf("%d", &n);
	d = new int[(n + 1)];
	pd = new ll[(n + 1)];
	sd = new ll[(n + 2)];
	sdr = new ll[(n + 2)];
	msd = new ll[(n + 1)];
	rmsd = new ll[(n + 2)];
	for (int i = 1; i <= n; i++) {
		scanf("%d", d + i);
		parity ^= (d[i] & 1);
	}
}

int allow = 1; // k <= min(degree, rank)
boolean check(int degree) {	// degree < allow
	static int R = 0;	// 
	if ((degree + parity) & 1)
		return false;
	while (R < n && d[R + 1] >= degree)
		R++;
	if (min(degree, R) >= allow)
		return false;
	return (degree >= R || msd[R] <= degree) && rmsd[R + 1] <= -degree;
}

inline void solve() {
	st = SegTree(n);
	sort(d + 1, d + n + 1, greater<int>());
	sd[n + 1] = 0;
	for (int i = n; i; i--) {
		st.update(d[i]);
		sd[i] = st.query(i);
	}
	for (int i = 1; i <= n; i++)
		sdr[i] = sd[i] - min(d[i], i);
	pd[0] = 0;
	for (int i = 1; i <= n; i++)
		pd[i] = pd[i - 1] + d[i];
	while (allow <= n && pd[allow] - (sdr[allow] + allow * 1ll * allow) <= 0)
		allow++;
	
	msd[0] = -llf;
	for (int i = 1; i <= n; i++) {
		msd[i] = pd[i] - (sdr[i] + i * 1ll * (i - 1));
		msd[i] = max(msd[i - 1], msd[i]);
	}
	rmsd[n + 1] = -llf;
	for (int i = n; i; i--) {
		rmsd[i] = pd[i - 1] - (sd[i] + i * 1ll * (i - 1));
		rmsd[i] = max(rmsd[i], rmsd[i + 1]);
	}
	vector<int> ans;
	for (int i = n; ~i; i--) {
		if (check(i)) {
			ans.push_back(i);
		}
	}
	if (!ans.size()) {
		puts("-1");
	} else {
		reverse(ans.begin(), ans.end());
		for (unsigned i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
	}
}

int main() {
	init();
	solve();
	return 0;
}