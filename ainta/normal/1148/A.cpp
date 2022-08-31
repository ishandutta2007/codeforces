#include<cstdio>
#include<algorithm>
using namespace std;
long long A, B, C;
int main() {
	scanf("%lld%lld%lld", &A, &B, &C);
	
	printf("%lld\n", min(min(A, B) * 2 + 1, max(A, B) * 2) + C*2);
}