#include <cstdio>
long long n, s;
int main(){
	scanf("%lld", &n);
	for (register int i = 1; 1ll * i * i <= n; ++i)
		if (n % i == 0){
			++s;
			if (1ll * i * i < n) ++s;
		}
	printf("%lld\n", s);
}