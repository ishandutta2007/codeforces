#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, i, s = 0;
	scanf("%d", &n);
	for (i = 0;; i++) {
		s += (1 << i);
		if (s >= n) {
			printf("%d\n", i + 1);
			break;
		}
	}
}