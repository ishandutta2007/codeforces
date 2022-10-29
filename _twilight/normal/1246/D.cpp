#include<bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int n;
int dep[N], fa[N];
vector<int> G[N];
vector<int> seq, opt;

void dfsseq(int p) {
	sort(G[p].begin(), G[p].end(), [&] (const int a, const int b) { return dep[a] < dep[b];	});
	seq.push_back(p);
	for (auto e : G[p])
		dfsseq(e);
}

void repeat(int x, int t) {
	while (t--)
		opt.push_back(x);
}
void dfsopt(int p) {
	reverse(G[p].begin(), G[p].end());
	int lsrt = -1;
	for (auto e : G[p]) {
		if (~lsrt) {
			repeat(lsrt, dep[e]);
		}
		dfsopt(e);
		lsrt = e;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i < n; i++) {
		scanf("%d", &x);
		G[x].push_back(i);
		dep[i] = 1;
		fa[i] = x;
	}
	for (int i = n - 1; i; i--)
		dep[fa[i]] = max(dep[fa[i]], dep[i] + 1);
	dfsseq(0);
	dfsopt(0);
	for (auto x : seq)
		printf("%d ", x);
	putchar('\n');
	reverse(opt.begin(), opt.end());
	printf("%d\n", (signed) opt.size());
	for (auto x : opt)
		printf("%d ", x);	
	return 0;
}