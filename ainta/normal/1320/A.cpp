#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[501000];
vector<int>U[1010000];
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		U[w[i] - i + n].push_back(i);
	}
	long long res = 0;
	for (i = 0; i <= 400000 + n; i++) {
		long long s = 0;
		for (auto &x : U[i]) {
			s += w[x];
		}
		res = max(res, s);
	}
	printf("%lld\n", res);
}