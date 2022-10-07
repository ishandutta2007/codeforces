#include <cstdio>
#include <cstring>
#include <algorithm>
int a, b, c, x, y, z;
int main(){
	scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
	if (x < a) return printf("NO\n"), 0; else b += a - x;
	if (y < b) return printf("NO\n"), 0; else c += b - y;
	if (z < c) printf("NO\n"); else printf("YES\n");
}