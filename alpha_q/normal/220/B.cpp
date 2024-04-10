#include <bits/stdc++.h> 

using namespace std;

const int SQRT = 320;
const int N = 1e5 + 10;

struct query {
	int id, l, r;
	bool operator < (const query &q) const {
		return l/SQRT == q.l/SQRT ? r < q.r : l/SQRT < q.l/SQRT;
	}
};

query q[N];
int n, m, a[N], cnt[N], res[N], cur;

void add (int p) {
	if (a[p] <= n) {
		if (cnt[a[p]] == a[p]) --cur;
		++cnt[a[p]];
		if (cnt[a[p]] == a[p]) ++cur;
	}
}

void del (int p) {
	if (a[p] <= n) {
		if (cnt[a[p]] == a[p]) --cur;
		--cnt[a[p]];
		if (cnt[a[p]] == a[p]) ++cur;
	}
}

int main (int argc, char const *argv[]) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= m; ++i) {
		q[i].id = i;
		scanf("%d %d", &q[i].l, &q[i].r);
	}
	sort(q + 1, q + m + 1);
	int l = 1, r = 0;
	for (int i = 1; i <= m; ++i) {
		while (r < q[i].r) add(++r);
		while (l > q[i].l) add(--l);
		while (l < q[i].l) del(l++);
		while (r > q[i].r) del(r--);
		res[q[i].id] = cur;
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d\n", res[i]);
	}
    return 0;
}