#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Node {
	int l1, r1, l2, r2;
} a[N];
inline bool cmp(const Node &t1, const Node &t2) {
	return t1.l1 < t2.l1;
}
int n;
vector<int> vec[N];
set<int> st1;
set<pair<int, int> > st2;
inline bool In(int i, int l, int r) {
	return l <= i && i <= r;
}
inline void Insert(int L, int R) {
	auto it = --st2.lower_bound(make_pair(L + 1, 0));
	if (it -> first <= L && R <= it -> second) return;
	it = --st2.lower_bound(make_pair(R + 1, 0));
	int nl = L, nr = R;
	while (In(it -> first, L, R) || In(it -> second, L, R)) {
		int t1 = In(it -> first, L, R), t2 = In(it -> second, L, R);
		if (!t1) {
			nl = it -> first;
		}
		if (!t2) {
			nr = it -> second;
		}
		st2.erase(it--);
	}
	st2.insert(make_pair(nl, nr));
}
inline void check() {
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) vec[i].clear();
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(a + 1, a + 1 + n, (Node){a[i].r1, 0, 0, 0}, cmp) - a;
		if (j <= n) vec[j].push_back(i);
	}
	st1.clear();
	st2.clear();
	st2.insert(make_pair(0, 0));
	st2.insert(make_pair(2000000000, 2000000000));
	for (int i = n; i >= 1; i--) {
		st1.insert(a[i].l2);
		st1.insert(a[i].r2);
		Insert(a[i].l2, a[i].r2);
		for (int v : vec[i]) {
			{
			auto it = st1.lower_bound(a[v].l2);
			if (it != st1.end() && (*it) <= a[v].r2) {
				puts("NO");
				exit(0);
			}
			}
			{
			auto it = --st2.lower_bound(make_pair(a[v].l2 + 1, 0));
			if (In(a[v].l2, it -> first, it -> second)) {
				puts("NO");
				exit(0);
			}
			it = --st2.lower_bound(make_pair(a[v].r2 + 1, 0));
			if (In(a[v].r2, it -> first, it -> second)) {
				puts("NO");
				exit(0);
			}
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &a[i].l1, &a[i].r1, &a[i].l2, &a[i].r2);
	}
	check();
	for (int i = 1; i <= n; i++) {
		swap(a[i].l1, a[i].l2);
		swap(a[i].r1, a[i].r2);
	}
	check();
	puts("YES");
	return 0;
}