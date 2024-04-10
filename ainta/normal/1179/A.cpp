#include<cstdio>
#include<algorithm>
using namespace std;
int w[301000], R[301000][2];
int n, Q;
int main() {
	int i;
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= n; i++) {
		R[i][0] = w[i];
		R[i][1] = w[i + 1];
		int Mx = max(w[i], w[i + 1]);
		int Mn = min(w[i], w[i + 1]);
		w[i + 1] = Mx;
		w[i + n] = Mn;
	}
	while (Q--) {
		long long a;
		scanf("%lld", &a);
		if (a <= n) {
			printf("%d %d\n", R[a][0], R[a][1]);
		}
		else {
			int t = (a-n-1) % (n - 1);
			printf("%d %d\n",w[n + 1], w[n + 2 + t]);
		}
	}
}