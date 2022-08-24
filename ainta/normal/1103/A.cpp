
#include<cstdio>
#include<algorithm>
using namespace std;
int C[2];
char p[1010];
int main() {
	int i, j, k;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		if (p[i] == '1') {
			printf("%d %d\n", C[1] % 4 + 1, 1);
			C[1]++;
		}
		else {
			printf("%d %d\n", C[0] % 2 * 2 + 1, 3);
			C[0]++;
		}

	}
}