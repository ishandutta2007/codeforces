#include <cstdio>
#include <algorithm>
long long n, k;
int main(){
	scanf("%I64d%I64d", &n, &k);
	long long a = (k - 1) / 2, b = k - a;
	printf("%I64d", std :: max(0ll, std :: min(a, n - b + 1)));
}