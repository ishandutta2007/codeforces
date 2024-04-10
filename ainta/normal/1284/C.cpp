#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long Mod, F[260000];
int main() {
	int i;
	scanf("%d%lld", &n, &Mod);
	F[0] = 1;
	for (i = 1; i <= n; i++)F[i] = F[i - 1] * i%Mod;
	long long res = 0;
	for (i = 1; i <= n; i++) {
		res=(res + 1ll * (n - i + 1)*(n - i + 1) % Mod*F[i] % Mod*F[n - i ]) % Mod;
	}
	printf("%lld\n", res);
}