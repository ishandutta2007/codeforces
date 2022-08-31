#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int a, b, c, TC;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d%d", &a, &b, &c);
		if (a <= b + c + 1 && b <= c + a + 1 && c <= a + b + 1)puts("Yes");
		else puts("No");
	}
}