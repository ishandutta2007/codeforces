#include <cstdio>
using namespace std;

typedef long long ll;

ll solve(ll a, ll b) {
	return b ? solve(b, a % b) + a / b : 0;
}

int main() {
	ll A, B;
	scanf("%I64d%I64d", &A, &B);
	printf("%I64d\n", solve(A, B));
	return 0;
}