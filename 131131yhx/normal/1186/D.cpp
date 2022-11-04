#include <bits/stdc++.h>
#define M 100010

using namespace std;

int n;

int A[M], B[M];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		double tmp;
		scanf("%lf", &tmp);
		long long ovo = tmp * 100000 + (tmp < 0 ? -0.5 : 0.5);
		if(ovo >= 0) {
			A[i] = ovo / 100000;
			B[i] = ovo % 100000;
		} else {
			A[i] = ovo / 100000;
			B[i] = ovo % 100000;
			if(B[i]) B[i] += 100000, A[i]--;
		}
	}
	int tot = 0;
	for(int i = 1; i <= n; i++) tot += A[i];
	tot = -tot;
	if(tot) for(int i = 1; i <= n; i++) if(B[i]) {
		A[i]++;
		if(--tot == 0) break;
	}
	for(int i = 1; i <= n; i++) printf("%d\n", A[i]);
	return 0;
}