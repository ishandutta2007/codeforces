#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, a[N], b[N], fa[N];
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
vector<int> S[N];
inline bool cmp(int i, int j) {
	return b[i] > b[j];
}
struct Node {
	int wei, u, v, id;
	inline bool operator < (const Node &oth) const {
		return wei > oth.wei;
	}
};
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	vector<Node> vec;
	for (int i = 1; i <= m; i++) {
		int s;
		scanf("%d", &s);
		S[i].resize(s);
		for (int j = 0; j < (int)S[i].size(); j++) {
			scanf("%d", &S[i][j]);
		}
		sort(S[i].begin(), S[i].end(), cmp);
		for (int j = 1; j < (int)S[i].size(); j++) {
			vec.push_back((Node){a[i] + b[S[i][j]], S[i][0], S[i][j], i});
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= n; i++) fa[i] = i;
	long long ans = 0;
	for (auto &nd : vec) {
		int u = nd.u, v = nd.v;
		if (Find(u) != Find(v)) {
			fa[Find(u)] = Find(v);
		} else ans += nd.wei;
	}
	printf("%lld\n", ans);
	return 0;
}