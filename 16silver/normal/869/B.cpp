#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
	long long a, b;
	int x=1,i;
	scanf("%I64d %I64d", &a, &b);
	if (a / 10 < b / 10) printf("0");
	else {
		for (i = 1 + (int)(a % 10); i <= (int)(b % 10); i++) x = (x*i) % 10;
		printf("%d", x);
	}
}