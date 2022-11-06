#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

struct Query { int id, l, r; };

int n, t;
int a[200000];
int occ[(int)1e6 + 1] = { 0 };
long long power = 0;
int L = 0;
int R = -1;
long long ans[200000];

void addOcc(const int x, const int c = 1) {
	power -= (long long)x * occ[x] * occ[x];
	occ[x] += c;
	power += (long long)x * occ[x] * occ[x];
}

void remOcc(const int x, const int c = 1) {
	power -= (long long)x * occ[x] * occ[x];
	occ[x] -= c;
	power += (long long)x * occ[x] * occ[x];
}

int bitsPB;

int getBlock(int x) {
	return x >> bitsPB;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	cin >> n >> t;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	bitsPB = max(0, (int)ceil(log(sqrt(n)) / log(2)));
	
	vector<Query> queries(t);
	for (int i = 0; i < t; ++i) {
		queries[i].id = i;
		cin >> queries[i].l >> queries[i].r;
		--queries[i].l;
		--queries[i].r;
	}

	std::sort(queries.begin(), queries.end(), [](const Query &lhs, const Query &rhs) {
		int diff = getBlock(lhs.l) - getBlock(rhs.l);
		if (diff)
			return diff < 0;
		return lhs.r < rhs.r;
	});

	for (auto &&q : queries) {
		while (L > q.l)
			addOcc(a[--L]);
		while (R < q.r)
			addOcc(a[++R]);
		while (L < q.l)
			remOcc(a[L++]);
		while (R > q.r)
			remOcc(a[R--]);
		ans[q.id] = power;
	}

	for (int i = 0; i < t; ++i)
		cout << ans[i] << '\n';
	return 0;
}