#include<cstdio>
#include<algorithm>
#define N_ 201000
using namespace std;
int n, L;
long long A[201000], B[601000];
bool Pos(int d) {
	int i;
	int Mn = -1e9, Mx = 1e9;
	for (i = 0; i < n; i++) {
		int b = lower_bound(B, B + n + n + n, A[i] + L - d) - B;
		int e = lower_bound(B, B + n + n + n, A[i] + L + d + 1) - B - 1;
		if (b > e)return false;
		Mn = max(Mn, b - i);
		Mx = min(Mx, e - i);
		if (Mn > Mx)return false;
	}
	return true;
}
int main() {
	int i, x;
	scanf("%d%d", &n,&L);
	for (i = 0; i < n; i++) {
		scanf("%lld", &A[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%lld", &B[i]);
	}
	sort(A, A + n);
	sort(B, B + n);
	for (i = 0; i < n + n; i++)B[i + n] = B[i] + L;
	int res = L / 2;
	int b = 0, e = L / 2 - 1, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Pos(mid))res = mid, e = mid - 1;
		else b = mid + 1;
	}
	printf("%d\n", res);
}