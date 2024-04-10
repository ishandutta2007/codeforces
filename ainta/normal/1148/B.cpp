#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
int n, m, K;
long long TA, TB, A[N_], B[N_];
bool Pos(long long T) {
	int i;
	T -= TA+TB;
	int p1 = 0, p2 = 0;
	for (i = 1; i <= n; i++) {
		if (A[i] <= T)p1 = i;
	}
	for (i = 1; i <= m; i++) {
		if (B[i] <= T)p2 = i;
	}
	if (p1 <= K || p2 <= K)return false;
	for (i = 0; i <= K; i++) {
		if (A[i + 1] > B[p2 - K + i])return false;
	}
	return true;
}
int main() {
	int i;
	scanf("%d%d%lld%lld%d", &n, &m, &TA, &TB, &K);
	for (i = 1; i <= n; i++)scanf("%lld", &A[i]);
	for (i = 1; i <= m; i++) {
		scanf("%lld", &B[i]);
		B[i] -= TA;
	}
	long long b = 0, e = 1e10, res = -1, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Pos(mid)) {
			res = mid;
			e = mid - 1;
		}
		else b = mid + 1;
	}
	printf("%lld\n", res);
}