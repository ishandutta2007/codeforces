#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const int INF = 1 << 30;

int N, W;
int t[1 << 21];
ll ans[MAXN];
int len, offset;

void update(int x, int val) {
	x += offset;
	t[x] = val;
	for (x /= 2; x; x /= 2)
		t[x] = max(t[2 * x], t[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return -INF;
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return max(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int query(int from, int to) {
	return query(1, 0, offset, from, to);
}

void add(int lo, int hi, int val) {
	ans[lo] += val;
	ans[hi + 1] -= val;
}

void update_small() {
	for (int i = 1; i < len; i++) {
		add(i, i, max(query(0, i), 0));
		add(W - i + 1, W - i + 1, max(query(len - i, len), 0));
	}
	add(len, W - len + 1, max(query(0, len), 0));
}

void update_large() {
	int diff = W - len + 1;
	for (int i = 1; i < diff; i++) {
		add(i, i, max(query(0, i), 0));
		add(W - i + 1, W - i + 1, max(query(len - i, len), 0));
	}
	for (int i = diff; i <= len; i++)
		add(i, i, query(i - diff, i));
}

int main() {
	scanf("%d%d", &N, &W);
	while (N--) {
		scanf("%d", &len);
		offset = 1;
		while (offset < len)
			offset *= 2;
		for (int i = 0; i < 2 * offset; i++)
			t[i] = -INF;
		for (int i = 0; i < len; i++) {
			int x;
			scanf("%d", &x);
			update(i, x);
		}
		if (2 * len <= W)
			update_small();
		else
			update_large();
	}
	
	for (int i = 1; i <= W; i++) {
		ans[i] += ans[i - 1];
		printf("%lld ", ans[i]);
	}
	puts("");
	
	return 0;
}