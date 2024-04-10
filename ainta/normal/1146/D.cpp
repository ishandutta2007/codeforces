#include<cstdio>
#include<algorithm>
using namespace std;
int n,A,B, UF[201000], SZ[201000], v[201000], w[201000], cnt, R[201000], cur;
int G;
long long res;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
void DFS(int a) {
	v[a] = 1;
	cnt++;
	if (a + A <= cur && !v[a + A])DFS(a + A);
	if (a - B >= 0 && !v[a - B])DFS(a - B);
}
int main() {
	int i;
	scanf("%d%d%d", &n,&A,&B);
	v[0] = 1;
	cnt = 1;
	R[0] = 1;
	res = 1;
	for (i = 1; i < A+B; i++) {
		cur = i;
		if (i >= A && v[i - A]) {
			DFS(i);
		}
		R[i] = cnt;
		res += cnt;
	}
	G = gcd(A, B);
	if (n < A + B) {
		res = 0;
		for (i = 0; i <= n; i++)res += R[i];
		printf("%lld\n", res);
		return 0;
	}
	int b = (A + B) / G ;
	int e = (n - G + 1) / G ;
	res += 1ll*G*(b + e + 2)*(e - b + 1) / 2;
	for (i = (e + 1)*G; i <= n; i++) {
		res += i / G + 1;
	}
	printf("%lld\n", res);
}