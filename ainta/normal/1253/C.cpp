#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int A[201000];
long long S[201000];
int main() {
	int i;
	scanf("%d%d", &n,&m);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + n);
	long long res = 0;
	long long s = 0;
	for (i = 0; i < n; i++) {
		S[i%m] += A[i];
		res += S[i%m];
		printf("%lld ", res);
	}
}