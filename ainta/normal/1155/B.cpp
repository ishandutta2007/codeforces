#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char p[301000];
int main() {
	int i;
	scanf("%d", &n);
	scanf("%s", p);
	int T = (n - 11) / 2;
	int c = 0;
	for (i = 0; i < 2 * T + 1; i++) {
		if (p[i] == '8')c++;
	}
	if (c > T ) {
		puts("YES");
	}
	else puts("NO");
}