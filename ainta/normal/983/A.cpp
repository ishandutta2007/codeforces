#include<cstdio>
#include<algorithm>
using namespace std;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		long long p, q, b;
		scanf("%lld%lld%lld", &p, &q, &b);
		long long g = gcd(p, q);
		p /= g, q /= g;
		long long u = gcd(q, b);
		while (u != 1) {
			q /= u;
			u = gcd(u, q);
		}
		if (q != 1)puts("Infinite");
		else puts("Finite");
	}
}