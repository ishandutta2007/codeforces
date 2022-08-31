#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[1010], P[1010];
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	vector<int>Res;
	for (i = 1; i <= n; i++) {
		int ck = 0;
		for (j = 0; j < n - i; j++) {
			if (w[j + i] - w[j] != w[j + i + 1] - w[j + 1])ck = 1;
		}
		if (!ck)Res.push_back(i);
	}
	printf("%d\n", Res.size());
	for (auto &x : Res)printf("%d ", x);
}