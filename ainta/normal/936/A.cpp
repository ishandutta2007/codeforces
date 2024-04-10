#include<cstdio>
#include<algorithm>
using namespace std;
long long K, D, T;
int main() {
	scanf("%lld%lld%lld", &K, &D, &T);
	long long TT = (K + D - 1) / D*D;
	T *= 2;
	long long res = (T / (TT + K))*TT;
	T %= (TT + K);
	if (T <= 2*K) {
		printf("%.10f\n", res + T*0.5);
	}
	else {
		res += K;
		T -= 2 * K;
		printf("%lld\n", res + T);
	}
}