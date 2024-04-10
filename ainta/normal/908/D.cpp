#include<cstdio>
#include<algorithm>
using namespace std;
int Mod = 1000000007;
int Inv(int a) {
	int b = Mod - 2, r = 1;
	while (b) {
		if (b & 1)r = 1ll * r*a%Mod;
		a = 1ll * a*a%Mod; b >>= 1;
	}
	return r;
}
int Pa, Pb, D[1010][1010], K, M, res;
int main() {
	int i, j;
	scanf("%d%d%d",&K, &Pa, &Pb);
	M = Inv(Pa + Pb);
	Pa = 1ll * Pa*M%Mod, Pb = 1ll * Pb*M%Mod;
	D[0][1] = 1;
	for (i = 0; i <= K; i++) {
		for (j = 1; j <= K; j++) {
			if (i + j >= K) {
				res = (res + 1ll*(i + j + 1ll*Pa*Inv(Pb)%Mod)*D[i][j])%Mod;
			}
			else {
				D[i + j][j] = (D[i + j][j] + 1ll * D[i][j] * Pb) % Mod;
				D[i][j + 1] = (D[i][j + 1] + 1ll * D[i][j] * Pa) % Mod;
			}
		}
	}
	printf("%d\n", res);
}