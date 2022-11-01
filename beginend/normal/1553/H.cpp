#include<bits/stdc++.h>
using namespace std;

const int K = 20;
const int N = (1 << (K - 1)) + 5;
const int inf = 1e9;

int n, k, bin[K], sz, a[N];
vector<int> vec[N * K];
struct tree{int l, r, ans, mn, mx;}t[N * K];

int newnode() {
	sz++;
	t[sz].mn = t[sz].ans = inf;
	return sz;
}

void update(int d, int k) {
	if (t[d].l) {
		t[d].ans = min(t[d].ans, t[t[d].l].ans);
		t[d].mn = t[t[d].l].mn;
	}
	else t[d].mn = t[t[d].r].mn + bin[k - 1];
	if (t[d].r) {
		t[d].ans = min(t[d].ans, t[t[d].r].ans);
		t[d].mx = t[t[d].r].mx + bin[k - 1];
	}
	else t[d].mx = t[t[d].l].mx;
	if (t[d].l && t[d].r)
		t[d].ans = min(t[d].ans, t[t[d].r].mn + bin[k - 1] - t[t[d].l].mx);
}

void ins(int &d, int x, int k) {
	if (!d) d = newnode();
	t[d].mn = min(t[d].mn, x & (bin[k] - 1));
	t[d].mx = max(t[d].mx, x & (bin[k]-  1));
	if (!k) return;
	if (x & bin[k - 1]) ins(t[d].r, x, k - 1);
	else ins(t[d].l, x, k - 1);
	update(d, k);
}

void work(int d, int k) {
	vec[d].push_back(d);
	if (!k) return;
	if (t[d].l) work(t[d].l, k - 1);
	if (t[d].r) work(t[d].r, k - 1);
	for (int i = 1; i < bin[k]; i++) {
		int u = newnode();
		if (i & bin[k - 1]) {
			if (t[d].r) t[u].l = vec[t[d].r][i ^ bin[k - 1]];
			if (t[d].l) t[u].r = vec[t[d].l][i ^ bin[k - 1]];
		}
		else {
			if (t[d].l) t[u].l = vec[t[d].l][i];
			if (t[d].r) t[u].r = vec[t[d].r][i];
		}
		update(u, k);
		vec[d].push_back(u);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	bin[0] = 1;
	for (int i = 1; i <= k; i++) bin[i] = bin[i - 1] * 2;
	int rt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ins(rt, a[i], k);
	}
	work(rt, k);
	for (int i = 0; i < bin[k]; i++)
		printf("%d ", t[vec[rt][i]].ans);
	return 0;
}