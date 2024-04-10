#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, w[201000];
void Solve() {
	scanf("%d%d", &n,&K);
	int i;
	vector<int>V;
	long long s = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (w[i] >= n - K + 1) {
			V.push_back(i);
			s += w[i];
		}
	}
	long long t = 1;
	for (i = 1; i < V.size(); i++) {
		t = t * (V[i] - V[i - 1]) % 998244353;
	}
	printf("%lld %lld\n", s,t);
}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}