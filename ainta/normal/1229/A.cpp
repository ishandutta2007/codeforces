#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long A[8000], B[8000], res, G;
vector<long long>U;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &A[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%lld", &B[i]);
	}
	for (i = 1; i <= n; i++) {
		int c = 0;
		for (j = 1; j <= n; j++) {
			if (A[i] == A[j])c++;
		}
		if (c >= 2)U.push_back(A[i]);
	}
	if (U.empty()) {
		puts("0");
		return 0;
	}
	for (i = 1; i <= n; i++) {
		int ck = 0;
		for (auto &t : U) {
			if ((A[i] & t) == A[i]) {
				ck = 1;
				break;
			}
		}
		if (ck)res += B[i];
	}
	printf("%lld\n", res);
}