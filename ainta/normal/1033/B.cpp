#include<cstdio>
#include<algorithm>
using namespace std;
long long a, b;
int main() {
	int i, TC;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%lld%lld", &a, &b);
		if (b == a - 1) {
			a = 2 * a - 1;
			int ck = 0;
			for (i = 2; 1ll * i*i <= a; i++)if (a%i == 0)ck = 1;
			if (!ck)puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
}