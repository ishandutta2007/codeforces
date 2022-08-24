#include<cstdio>
#include<algorithm>
using namespace std;
int n, A[101000], B[101000];
void Solve() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &B[i]);
	}
	int d = 0;
	for (i = 1; i <= n; i++) {
		if (A[i] > B[i]) {
			puts("NO");
			return;
		}
		if (d&&A[i] != B[i] && A[i - 1] == B[i - 1]) {
			puts("NO");
			return;
		}
		if (A[i] != B[i]) {
			if (!d) {
				d = B[i] - A[i];
			}
			else if (d != B[i]-A[i]) {
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}