#include<cstdio>
#include<algorithm>
using namespace std;
int n, Mx = -1e9;
int main() {
	int i, a, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		int ck = 0;
		for (j = 0; j <= 1000; j++) {
			if (j*j == a)ck = 1;
		}
		if (!ck)Mx = max(Mx, a);
	}
	printf("%d\n", Mx);
}