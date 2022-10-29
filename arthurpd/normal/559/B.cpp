#include <stdio.h>
#include <string.h>

char s1[212345], s2[212345];

int foo(int a, int b, int c, int d)
{
	int ok = true;
	for(int i = a, j = c; i <= b; i++, j++)
		if(s1[i] != s2[j])
			ok = false;
	if(ok) return ok;
	if(((b-a) % 2) == 0)
		return false;
	return (foo(a, (a+b)/2, c, (c+d)/2) && foo(((a+b)/2) + 1, b, ((c+d)/2) + 1, d)) || (foo(((a+b)/2) + 1, b, c, (c+d)/2) && foo(a, (a+b)/2, ((c+d)/2) + 1, d));
}

int
main(void)
{
	scanf("%s %s", s1, s2);
	printf("%s\n", foo(0, strlen(s1) - 1, 0, strlen(s2) - 1) ? "YES" : "NO");
}