#include <cstdio>
#include <cstring>
#include <algorithm>
int k, b, s;
int qpow(int a, int b){
	int s = 1;
	for (; b; b >>= 1, a = a * a & 1) if (b & 1) s = s * a & 1;
	return s;
}
int main(){
	scanf("%d%d", &b, &k);
	for (register int i = k - 1, x; ~i; --i)
		scanf("%d", &x), (s += qpow(b, i) * x & 1) &= 1;
	if (s) printf("odd"); else printf("even");
}