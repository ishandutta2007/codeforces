#include<cstdio>
#include<algorithm>
using namespace std;
int n, a, b;
int main() {
	int TC, t;
	scanf("%d", &TC);
	while (TC--) {
		int i;
		scanf("%d%d%d", &n, &a, &b);
		int ck = 0;
		for (i = 1; i <= a; i++) {
			scanf("%d", &t);
			if (t == n)ck = 1;
		}
		for (i = 1; i <= b; i++) {
			scanf("%d", &t);
			if (t == n)ck = 2;
		}
		if (ck == 1)puts("YES");
		else puts("NO");
	}
}