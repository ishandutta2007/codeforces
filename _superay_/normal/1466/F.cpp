#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int mod = 1000000007;
int num, n, fa[N], lab[N];
int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
inline bool Add1(int x) {
	x = Find(x);
	if (lab[x]) return false;
	lab[x] = 1;
	return true;
}
inline bool Add2(int x, int y) {
	x = Find(x), y = Find(y);
	if (x == y) return false;
	if (lab[x] && lab[y]) return false;
	if (lab[x]) lab[y] = 1;
	else if (lab[y]) lab[x] = 1;
	else {
		if (x > y) swap(x, y);
		fa[y] = x;
	}
	return true;
}
int main() {
		scanf("%d%d", &num, &n);
		for (int i = 1; i <= n; i++) fa[i] = i, lab[i] = 0;
		int prd = 1;
		vector<int> vec;
		for (int i = 1; i <= num; i++) {
			int k;
			scanf("%d", &k);
			if (k == 1) {
				int x;
				scanf("%d", &x);
				if (Add1(x)) {
					prd = 2 * prd % mod;
					vec.push_back(i);
				}
			} else {
				int x, y;
				scanf("%d%d", &x, &y);
				if (Add2(x, y)) {
					prd = 2 * prd % mod;
					vec.push_back(i);
				}
			}
		}
		printf("%d %d\n", prd, (int)vec.size());
		for (int x : vec) printf("%d ", x);
		puts("");
	return 0;
}