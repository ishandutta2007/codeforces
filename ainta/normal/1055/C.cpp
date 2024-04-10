#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, L;
struct point {
	long long b, e, T, d;
}A, B;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	scanf("%lld%lld%lld", &A.b, &A.e, &A.T);
	scanf("%lld%lld%lld", &B.b, &B.e, &B.T);
	A.d = A.e - A.b + 1;
	B.d = B.e - B.b + 1;
	long long g = gcd(A.T, B.T);
	if (B.b <= A.b && A.e <= B.e) {
		printf("%lld\n", A.e - A.b + 1);
		return 0;
	}
	swap(A, B);
	if (B.b <= A.b && A.e <= B.e) {
		printf("%lld\n", A.e - A.b + 1);
		return 0;
	}
	if (B.T <= A.T) swap(A, B);
	B.b += B.T, B.e += B.T;
	long long d = (B.b - A.b) / g*g, res = 0;
	A.b += d, A.e += d;
	res = max(res, min(A.e, B.e) - max(B.b, A.b) + 1);
	A.b += g, A.e += g;
	res = max(res, min(A.e, B.e) - max(B.b, A.b) + 1);
	printf("%lld\n", res);
}