#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int N = 1 << 21;
ull n, A[N], B[N];
char a[N + 1], b[N + 1];
void FMT(ull *f, int tp) {
	for(int j = 0; j < n; j++) for(int i = 0; i < 1 << n; i++) if(i >> j & 1) f[i] += tp * f[i - (1 << j)];
}
int main() {
	scanf("%llu %s %s", &n, a, b);
	for(int i = 0; i < 1 << n; i++) A[i] = (ull)(a[i] - '0') << (2 * __builtin_popcount(i));
	for(int i = 0; i < 1 << n; i++) B[i] = (ull)(b[i] - '0') << (2 * __builtin_popcount(i));
	FMT(A, 1), FMT(B, 1);
	for(int i = 0; i < 1 << n; i++) A[i] = A[i] * B[i];
	FMT(A, -1);
	for(int i = 0; i < 1 << n; i++) putchar('0' + (A[i] >> (2 * __builtin_popcount(i)) & 3));
	return 0;
}