#include<cstdio>
#include<algorithm>
using namespace std;
char p[110];
int c;
int main() {
	int i;
	scanf("%s", p);
	for (i = 0; p[i]; i++) {
		if (p[i] == 'a' || p[i] == 'e' || p[i] == 'o' || p[i] == 'i' || p[i] == 'u' || p[i] == '1' || p[i] == '3' || p[i] == '5' || p[i] == '7' || p[i] == '9')c++;
	}
	printf("%d\n", c);
}