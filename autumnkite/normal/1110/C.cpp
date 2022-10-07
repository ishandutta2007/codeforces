#include <cstdio>
#include <cstring>
#include <algorithm>
int q, x, y, ans;
const int s[] = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
int reverse(int x){
	int y = 0, s = 1;
	while (x)
		y += (!(x & 1)) * s, x >>= 1, s <<= 1;
	return y;
}
int Log(int x){
	int s = 0;
	while (x) x >>= 1, ++s;
	return s;
}
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	scanf("%d", &q);
	while (q--){
		scanf("%d", &x), y = reverse(x);
		if (y) ans = gcd(x ^ y, x & y); else ans = s[Log(x) - 2];
		printf("%d\n", ans);
	}
}