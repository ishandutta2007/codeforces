#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int S[101000], P[101000], K, L[101000], R[101000];
int main() {
	int i, b, e;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &b, &e);
		S[b]++, S[e + 1]--;
	}
	for (i = 1; i <= m; i++)S[i] += S[i - 1];
	int cnt = 0;
	for (i = 1; i <= m; i++) {
		if (!cnt || P[cnt] <= S[i]) {
			P[++cnt] = S[i];
			L[i] = cnt;
		}
		else {
			b = 1, e = cnt;
			int r = 0;
			while (b <= e) {
				int mid = (b + e) >> 1;
				if (P[mid] > S[i]) {
					r = mid;
					e = mid - 1;
				}
				else b = mid + 1;
			}
			P[r] = S[i];
			L[i] = r;
		}
	}
	cnt = 0;
	for (i = m; i >= 1; i--) {
		if (!cnt || P[cnt] <= S[i]) {
			P[++cnt] = S[i];
			R[i] = cnt;
		}
		else {
			b = 1, e = cnt;
			int r = 0;
			while (b <= e) {
				int mid = (b + e) >> 1;
				if (P[mid] > S[i]) {
					r = mid;
					e = mid - 1;
				}
				else b = mid + 1;
			}
			P[r] = S[i];
			R[i] = r;
		}
	}
	int res = 0;
	for (i = 1; i <= m; i++)res = max(res, L[i] + R[i] - 1);
	printf("%d\n", res);
}