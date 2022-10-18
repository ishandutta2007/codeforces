
/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
 
#define int long long
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 5e2;
 
int a[N + 10][N + 10];
 
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
	int LCM = 1;
	for (int i = 2; i <= 16; i++) LCM = lcm(LCM, i);
	int n = fr(), m = fr();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) fr(a[i][j]);
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= m; j++) {
			if ((i + j) & 1) printf("%lld ", LCM + a[i][j] * a[i][j] * a[i][j] * a[i][j]);
			else printf("%lld ", LCM);
		}
    return 0;
}