#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3f;
struct BIT {
	int n, vis[N], stk[N], tp;
	pair<int, int> bit[N];
	inline void Init(int _n) {
		n = _n;
		tp = 0;
		for (int i = 1; i <= n; i++) bit[i] = make_pair(-INF, -1), vis[i] = 0;
	}
	inline void add(int i, pair<int, int> x) {
		while (i <= n) {
			bit[i] = max(bit[i], x);
			if (!vis[i]) { vis[i] = 1; stk[++tp] = i; }
			i += i & -i;
		}
	}
	inline pair<int, int> qry(int i) {
		pair<int, int> res(-INF, -1);
		while (i > 0) {
			res = max(res, bit[i]);
			i -= i & -i;
		}
		return res;
	}
	inline void Clear() {
		while (tp) {
			int i = stk[tp--];
			bit[i] = make_pair(-INF, -1);
			vis[i] = 0;
		}
	}
} bit1, bit2;
int n, a[N], f[N], fr[N], m, b[N], c[N], ps0[N], ps1[N], psb[N], id1[N], id2[N];
vector<int> val1;
void gao(int l, int r) {
	if (l == r) {
		if (a[l] != -1) f[l]++;
		return;
	}
	int mid = (l + r) >> 1;
	gao(l, mid);
	vector<int> vec;
	for (int i = l; i <= mid; i++) {
		if (a[i] != -1) vec.push_back(i);
	}
	for (int i = mid + 1; i <= r; i++) {
		if (a[i] != -1) vec.push_back(i);
	}
	sort(vec.begin(), vec.end(), [](int i, int j) {
		if (a[i] != a[j]) return a[i] < a[j];
		else return i > j;
	});
	for (int i : vec) {
		if (i <= mid) {
			bit1.add(id1[i], {f[i] - psb[i], i});
			bit2.add(val1.size() - id1[i] + 1, {f[i] - ps0[i], i});
		} else { 
			auto cur1 = bit1.qry(id2[i] - 1);
			cur1.first += psb[i];
			auto cur2 = bit2.qry(val1.size() - id2[i] + 1);
			cur2.first += ps1[i];
			cur1 = max(cur1, cur2);
			if (cur1.second != -1 && f[i] < cur1.first) {
				f[i] = cur1.first;
				fr[i] = cur1.second;
			}
		}
	}
	bit1.Clear();
	bit2.Clear();
	gao(mid + 1, r);
}
int main() {
	scanf("%d", &n);
	psb[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), psb[i] = psb[i - 1] + (a[i] == -1);
	a[0] = 0, a[n + 1] = INF;
	psb[n + 1] = psb[n];
	scanf("%d", &m);
	multiset<int> st;
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), c[i] = b[i], st.insert(b[i]);
	int s = m;
	sort(c + 1, c + 1 + s);
	s = unique(c + 1, c + 1 + s) - c - 1;
	for (int i = 0; i <= n + 1; i++) if (a[i] != -1) {
		ps0[i] = upper_bound(c + 1, c + 1 + s, a[i]) - c - 1;
		ps1[i] = upper_bound(c + 1, c + 1 + s, a[i] - 1) - c - 1;
		val1.push_back(ps0[i] - psb[i]);
	}
	sort(val1.begin(), val1.end());
	val1.resize(unique(val1.begin(), val1.end()) - val1.begin());
	for (int i = 0; i <= n + 1; i++) if (a[i] != -1) {
		id1[i] = lower_bound(val1.begin(), val1.end(), ps0[i] - psb[i]) - val1.begin() + 1;
		id2[i] = lower_bound(val1.begin(), val1.end(), ps1[i] - psb[i]) - val1.begin() + 1;
	}
	bit1.Init(val1.size());
	bit2.Init(val1.size());
	gao(0, n + 1);
	for (int i = n + 1; i > 0; i = fr[i]) {
		int j = fr[i], cc = min(ps1[i] - ps0[j], psb[i] - psb[j]), pos = ps0[j] + 1;
		for (int k = j + 1; k < i && cc; k++) if (a[k] == -1) {
			cc--;
			a[k] = c[pos++];
			st.erase(st.find(a[k]));
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) { a[i] = *st.begin(); st.erase(st.begin()); }
		printf("%d ", a[i]);
	}
	return 0;
}