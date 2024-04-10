#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n, A[101000], B[101000], m;
long long s = 0;
map<int, int>Map;
int main() {
	int i, j;
	scanf("%d%d", &n,&m);
	int Mx = 0, Mn = 1e9;
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		Mx = max(Mx, A[i]);
		s += 1ll * A[i] * m;
	}
	int ck = 0;
	for (i = 1; i <= m; i++) {
		scanf("%d", &B[i]);
		Mn = min(Mn, B[i]);
		if (B[i] != Mx) {
			s += B[i] - Mx;
		}
		if (B[i] == Mx)ck = 1;
	}
	if (Mx > Mn) {
		puts("-1");
		return 0;
	}
	if (!ck) {
		int c = 0;
		for (i = 1; i <= n; i++) {
			if (Mx == A[i])c++;
		}
		if (c == 1) {
			sort(A + 1, A + n + 1);
			s += A[n] - A[n - 1];
		}
	}
	printf("%lld\n", s);
}