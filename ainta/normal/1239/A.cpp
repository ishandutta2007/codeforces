#include<cstdio>
#include<algorithm>
using namespace std;
long long D[101000], Mod = 1000000007;
int n, m;
int main() {
	int i;
	scanf("%d%d", &n, &m);
	D[1] = 2;
	D[2] = 4;
	for (i = 3; i <= 100000; i++) {
		D[i] = (D[i - 1] + D[i - 2]) % Mod;
	}
	printf("%lld\n", (D[n] + D[m] - 2+Mod)%Mod);
}