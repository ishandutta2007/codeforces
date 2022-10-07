#include <cstdio>
int n, m, x[2005], y[2005];
bool is_prime(int x){
	if (x < 2) return 0;
	for (register int i = 2; i * i <= x; ++i)
		if (x % i == 0) return 0;
	return 1;
}
int main(){
	scanf("%d", &n);
	m = n;
	for (register int i = 1; i < n; ++i) x[i] = i, y[i] = i + 1;
	x[m] = n, y[m] = 1;
	int t = 1;
	while (!is_prime(m)){
		x[++m] = t, y[m] = t + 2, ++t;
		while (t % 4 == 0 || t % 4 == 3) ++t;
	}
	printf("%d\n", m);
	for (register int i = 1; i <= m; ++i) printf("%d %d\n", x[i], y[i]);
}