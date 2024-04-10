#include<stdio.h>
char p[1010], q[11] = "CODEFORCES";
int main(){
	int i, n, c1 = 0, c2 = 0;
	scanf("%s", p);
	for (i = 0; p[i]; i++);
	n = i;
	if (n < 11){
		printf("NO\n");
		return 0;
	}
	for (i = 0; i < 10; i++)if (q[i] != p[i])break;
	c1 = i;
	for (i = 0; i < 10; i++)if (q[9 - i] != p[n - 1 - i])break;
	c2 = i;
	if (c1 + c2 >= 10)printf("YES\n");
	else printf("NO\n");
}