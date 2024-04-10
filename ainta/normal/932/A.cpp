#include<cstdio>
#include<algorithm>
using namespace std;
char p[101000];
int main() {
	int i;
	scanf("%s", p);
	for (i = 0; p[i]; i++)printf("%c", p[i]);
	for (i = i - 1; i >= 0; i--)printf("%c", p[i]);
	printf("\n");
}