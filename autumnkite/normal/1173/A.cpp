#include <cstdio>
int a, b, c, s1, s2;
int main(){
	scanf("%d%d%d", &a, &b, &c);
	s1 = a - b + c, s2 = a - b - c;
	if (s1 < 0 && s2 < 0) printf("-");
	else if (s1 > 0 && s2 > 0) printf("+");
	else if (s1 == 0 && s2 == 0) printf("0");
	else printf("?");
}