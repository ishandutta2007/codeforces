#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		long long a;
		scanf("%lld", &a);
		if (a >= 14 && a % 14 >= 1 && a % 14 <= 6) {
			puts("YES");
		}
		else puts("NO");
	}
}