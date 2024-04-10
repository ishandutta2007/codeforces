#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
vector<int>P[201000], V;
int D[201000], vis[201000], vv[201000], n, f, chk[201000];
bitset<200000>A[200], U;
int main() {
	int i, j;
	scanf("%d%d",&n, &f);
	for (i = 2; i < 200000; i++) {
		if (P[i].empty()) {
			for (j = i; j <= 200000; j += i)P[j].push_back(i);
		}
		if (P[i].size() <= 2) {
			if (P[i].size() == 1 && P[i][0] == i) {
				if(i!=f)V.push_back(i);
			}
			if (P[i].size() == 2 && P[i][0] * P[i][1] == i) {
				if(i!=f)V.push_back(i);
			}
			if (P[i].size() == 1 && 1ll * P[i][0] * P[i][0] == i) {
				if (i != f)V.push_back(i);
			}
		}
	}
	for (auto &x : V) {
		chk[x] = 1;
		U[x] = 1;
	}
	for (i = 0; i < 200000; i++) {
		for (j = 0;; j++)if (!A[j][i])break;
		D[i] = j;
		A[j] |= (U << i);
	}
	int r = 0;
	for (i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		r ^= D[b - a - 1];
		r ^= D[c - b - 1];
	}
	if (r) {
		puts("Alice");
		puts("Bob");
	}
	else {
		puts("Bob");
		puts("Alice");

	}
}