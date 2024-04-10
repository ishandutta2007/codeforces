#include<cstdio>
#include<algorithm>
using namespace std;
long long n, K, A, B, res = 1e18, res2 = 0;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
void Go(long long a, long long b) {
	b -= a;
	if (b < 0)b += n * K;
	res = min(res, n*K / gcd(b, n*K));
	res2 = max(res2, n*K / gcd(b, n*K));
}
int main() {
	scanf("%lld%lld%lld%lld", &n, &K, &A, &B);
	for (long long i = 0; i < n*K; i += K) {
		Go(A, i + B);
		Go(A, i + K-B);
	}
	printf("%lld %lld\n", res,res2);
}