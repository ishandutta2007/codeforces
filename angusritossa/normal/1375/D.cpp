#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int rangetree[1010*4];
int leaf[1010*4];
void update(int a, int val, int curr = 1, int cstart = 0, int cend = 1010) {
	if (cstart == cend) {
		leaf[a] += val;
		if (!leaf[a]) rangetree[curr] = a;
		else rangetree[curr] = 1010;
		return;
	}
	int mid = (cstart+cend)/2;
	if (a <= mid) update(a, val, 2*curr, cstart, mid);
	else update(a, val, 2*curr+1, mid+1, cend);
	rangetree[curr] = min(rangetree[2*curr], rangetree[2*curr+1]);
}
int a[1010], n;
set<int> is[1010];
int lowestnotinplace;
int main() {
	int t;
	scanf("%d", &t);
	fill_n(rangetree, 1010*4, 1010);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		lowestnotinplace = 0;
		for (int i = 0; i <= n; i++) is[i].clear();
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), is[a[i]].insert(i);
		for (int i = 0; i <= n; i++) update(i, -leaf[i]);
		for (int i = 0; i < n; i++) update(a[i], 1);
		vector<int> op;
		while (1) {
			int mx = rangetree[1];
		//	D("%d\n", mx);
		//	assert(rand()%20);
			if (mx == n) {
				while (lowestnotinplace < n) {
					if (a[lowestnotinplace] == lowestnotinplace) lowestnotinplace++;
					else break;
				}
				if (lowestnotinplace == n) break;
				int rem = *is[lowestnotinplace].begin();
				is[lowestnotinplace].erase(rem);
				update(lowestnotinplace, -1);
				update(n, 1);
				is[n].insert(rem);
				a[rem] = n;
				op.push_back(rem);
			} else {
				update(a[mx], -1);
				is[a[mx]].erase(mx);
				a[mx] = mx;
				is[a[mx]].insert(mx);
				update(a[mx], 1);
				op.push_back(mx);
			}
		}
		printf("%lu\n", op.size());
		for (auto i : op) printf("%d ", i+1);
		printf("\n");

	}
}