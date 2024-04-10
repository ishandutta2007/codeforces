#include <cstdio>
#include <algorithm>
long long a, b, x, y, g;
long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
	g = gcd(x, y), x /= g, y /= g;
	printf("%lld", std :: min(a / x, b / y));
}