#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long n, m;
int main() {
	scanf("%lld%lld", &n, &m);
	if (n <= 35) {
		printf("%lld\n", m % (1ll << n));
	}
	else {
		printf("%lld\n", m);
	}
}