#include<cstdio>
#include<algorithm>
using namespace std;
int n, c;
char p[1111];
int main() {
	int i;
	scanf("%d", &n);
	scanf("%s", p);
	for (i = 0; i < n; i++)if (p[i] == '8')c++;
	printf("%d\n", min(n / 11, c));
}