#include <cstdio>
#include <algorithm>
int a, b, c;
int main(){
	scanf("%d%d%d", &a, &b, &c);
	--a, --b, --b, --c, --c, --c;
	printf("%d", 3 * std :: min(a, std :: min(b, c)) + 6);
}