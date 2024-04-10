#include<cstdio>
#include<algorithm>
using namespace std;
long long  b, e, i;
int main() {
	scanf("%lld%lld", &b, &e);
	puts("YES");
	for (i = b; i <= e; i += 2) {
		printf("%lld %lld\n", i, i + 1);
	}
}