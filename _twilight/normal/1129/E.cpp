#include <bits/stdc++.h>
using namespace std;

const int N = 505;

typedef vector<int> vec;

vec split(const vec& a, int l, int r) {
	vec rt;
	for (int i = l; i <= r; i++) {
		rt.push_back(a[i]);
	}
	return rt;
}

int n;

int query(vec a, vec b, int v) {
	if (a.empty() || b.empty()) {
		return 0;
	}
	printf("%d\n", (signed) a.size());
	for (auto x : a) {
		printf("%d ", x);
	}
	putchar('\n');
	printf("%d\n", (signed) b.size());
	for (auto x : b) {
		printf("%d ", x);
	}
	putchar('\n');
	printf("%d\n", v);
	fflush(stdout);
	int rt;
	scanf("%d", &rt);
	return rt;
}

vec sz;
vec order;
vector<pair<int, int>> ans;

vec leaf;
vec solve(int p) {
	if (p == 1) {
		return leaf;
	}
	int L = 0, R = (signed) leaf.size() - 1;
	auto count = [&] (int l) {
		return query(vec{1}, split(leaf, l, R), p);
	};
	vec pos, rt;
	int rest = count(0);
	while (rest--) {
		int l = L, r = R, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (count(mid) <= rest) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		L = r + 1;
		pos.push_back(r);
		rt.push_back(leaf[r]);
	}
	while (!pos.empty()) {
		leaf.erase(leaf.begin() + pos.back());
		pos.pop_back();
	}
	return rt;
}

int main() {
	scanf("%d", &n);
	sz.resize(n + 1);
	order.resize(n);
	for (int i = 1; i <= n; i++) {
		order[i - 1] = i;
	}
	sz[1] = n;
	for (int i = 2; i <= n; i++) {
		vec v;
		for (int j = 2; j <= n; j++) {
			if (i ^ j) {
				v.push_back(j);
			}
		}
		sz[i] = query(vec{1}, v, i) + 1;
	}
	sort(order.begin(), order.end(), [&] (int x, int y) { return sz[x] < sz[y];	});
	assert(order.back() == 1);
	for (auto p : order) {
		vec v = solve(p);
		for (auto x : v) {
			ans.emplace_back(p, x);
		}
		leaf.push_back(p);
	}
	puts("ANSWER");
	for (auto x : ans) {
		printf("%d %d\n", x.first, x.second);
	}
	fflush(stdout);
	return 0;
}