#include <stdio.h>
#include <string.h>

char s[1123456];

char name[112] = "CODEFORCES";

int
main(void)
{
	scanf("%s", s);
	int l = 0, r = 0, n = strlen(s);
	for(int i = 0; name[i] == s[i] && name[i] != 0 && s[i] != 0; i++)
		l++;
	for(int i = n - 1; i >= 0 && 10-(n-i) >= 0 && name[10-(n-i)] == s[i]; i--)
		r++;
	//printf("%d %d\n", l, r);
	if(l + r >= strlen(name))
		printf("YES\n");
	else
		printf("NO\n");
}