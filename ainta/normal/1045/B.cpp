#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int w[201000], p[201000], q[401000], oto[201000], n, M;
vector<int>res;
int main() {
	int i, j;
	scanf("%d%d", &n,&M);
	for (i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 0; i < n; i++)p[i] = (w[(i + 1) % n] - w[i] + M) % M;
	for (i = 0; i < n; i++)q[i] = q[n+i] = p[n - i - 1];
	oto[0] = -1;
	for (i = 0; i < n; i++) {
		int t = oto[i];
		while (t != -1 && p[t] != p[i])t = oto[t];
		oto[i + 1] = t + 1;
	}
	int pv = 0;
	for (i = 0; i < n+n-1; i++) {
		while (pv != -1 && p[pv] != q[i])pv = oto[pv];
		pv++;
		if (pv == n) {
			int be = i - (n - 1);
			res.push_back((w[(n - be) % n] + w[0])%M);
		}
	}
	if(!res.empty())sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (auto &x : res)printf("%d ", x);
}