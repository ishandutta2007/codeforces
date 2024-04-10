#include <stdio.h>
#include <string.h>
#include <iostream>

char s[112345];

int
main(void)
{
	int a[5];
	long long int ans = 0;
	scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
	scanf(" %s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++)
		ans += a[s[i]-'1'];
	std::cout << ans;
	return 0;
}