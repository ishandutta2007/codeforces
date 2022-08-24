#include<cstdio>
#include<algorithm>
using namespace std;
char p[100];
bool isPalin(int b, int e) {
	int i;
	for (i = b; i <= e; i++)if (p[i] != p[b + e - i])return false;
	return true;
}
int main() {
	int i, j, res = 0;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		for (j = i; p[j]; j++) {
			if (!isPalin(i, j)) {
				res = max(res, j - i + 1);
			}
		}
	}
	printf("%d\n", res);
}