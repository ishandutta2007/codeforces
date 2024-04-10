#include<cstdio>
#include<algorithm>
using namespace std;
char p[100];
int n, c;
int main() {
	scanf("%s", p);
	int i;
	for (i = 0; p[i]; i++) {
		if (p[i] == 'a')c++;
	}
	n = i;
	printf("%d\n", min(c * 2 - 1, n));
}