#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int C[301000], n, K, S[301000], chk[301000];
int main() {
	int i, j;
	for (i = 1; i <= 300000; i++)for (j = i + i; j <= 300000; j += i)C[j]++;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		S[i] = S[i - 1] + C[i];
		if (S[i] >= K)break;
	}
	if (i == n + 1) {
		printf("No\n");
		return 0;
	}
	int x = i;
	vector<pii>V;
	for (i = x/2+1; i < x; i++) {
		V.push_back({ C[i],i });
	}
	sort(V.begin(), V.end());
	int U = S[x] - K, cnt = x;
	for (i = V.size() - 1; i >= 0; i--) {
		if (U >= V[i].first) {
			U -= V[i].first;
			chk[V[i].second] = 1;
			cnt--;
		}
	}
	if (U) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	printf("%d\n", cnt);
	for (i = 1; i <= x; i++)if (!chk[i])printf("%d ", i);
}