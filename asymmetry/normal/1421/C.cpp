#include <bits/stdc++.h>

using namespace std;

int n;
char s[1000001];

int main()
{
	scanf("%s", s+1);
	n=strlen(s+1);
	printf("3\n");
	printf("L 2\n");
	printf("R 2\n");
	printf("R %d\n", n+n-1);
	return 0;
}