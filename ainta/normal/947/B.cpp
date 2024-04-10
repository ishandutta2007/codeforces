#include<cstdio>
#include<algorithm>
using namespace std;
int w[101000], n, P[101000];
long long S[101000], Res[101000];
int main() {
	int i, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	for (i = 1; i <= n; i++) {
		scanf("%d", &t);
		S[i] = S[i - 1] + t;
	}
	for (i = 1; i <= n; i++) {
		int b = 1, e = n, r = n + 1, mid;
		long long tt = w[i] + S[i - 1];
		while (b <= e) {
			mid = (b + e) >> 1;
			if (S[mid] > tt) {
				r = mid;
				e = mid - 1;
			}
			else b = mid + 1;
		}
		P[r - 1]++;
		if(r!=n+1)Res[r] += tt - S[r - 1];
	}
	for (i = n; i >= 1; i--)P[i] += P[i + 1];
	for (i = 1; i <= n; i++) {
		printf("%lld ", 1ll * (P[i]-(n-i)) * (S[i] - S[i - 1]) + Res[i]);
	}
}