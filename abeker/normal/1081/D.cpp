#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct edge {
	int u, v, w;
	bool operator <(const edge &rhs) const {
		return w < rhs.w;
	}
};

int N, M, K;
int spec[MAXN];
int dad[MAXN], rnk[MAXN], ans[MAXN];
bool has[MAXN];
vector <edge> all;

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y, int z) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
	if (has[x] && has[y])
		ans[y] = z;
	has[y] |= has[x];
	ans[y] = max(ans[y], ans[x]);
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", spec + i);
		has[spec[i]] = true;
	}
	
	while (M--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		all.push_back({a, b, c});
	}
	
	sort(all.begin(), all.end());
	
	for (int i = 1; i <= N; i++)
		dad[i] = i;
		
	for (auto it : all)
		join(it.u, it.v, it.w);
	
	for (int i = 0; i < K; i++)
		printf("%d ", ans[find(spec[i])]);
	puts("");
	
	return 0;
}