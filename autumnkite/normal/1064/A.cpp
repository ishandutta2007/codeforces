#include <cstdio>
#include <algorithm>
int a[3];
int main(){
	scanf("%d%d%d", a, a + 1, a + 2);
	std :: sort(a, a + 3);
	if (a[0] + a[1] > a[2]) printf("0");
	else printf("%d\n", a[2] + 1 - a[0] - a[1]);
}