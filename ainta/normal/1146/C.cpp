#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
void Solve() {
	int i, j, Mx = 0, t;
	scanf("%d", &n);
	for (i = 0; i < 7; i++) {
		vector<int>V1, V2;
		for (j = 1; j <= n; j++) {
			if((j>>i)&1)V1.push_back(j);
			else V2.push_back(j);
		}
		if (V1.empty() || V2.empty())continue;
		printf("%d %d ", V1.size(), V2.size());
		for (auto &x : V1)printf("%d ", x);
		for (auto &x : V2)printf("%d ", x);
		puts("");
		fflush(stdout);
		scanf("%d", &t);
		Mx = max(Mx, t);
	}
	printf("%d %d\n", -1, Mx);
	fflush(stdout);
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}