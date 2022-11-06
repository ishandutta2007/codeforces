#include <cstdio>
#include <algorithm>
using namespace std;

char s[99];

void Print(int x)
{
	for (int i = 1; i <= x; i ++)
	{
		puts("..X..");
		puts(".XXX.");
		puts(".....");
	}
	puts("..X..");
	puts(".XXX.");
	puts("..X..");
	puts(".....");
	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("G.txt", "w", stdout);
	#endif
	
	scanf("%s", s);
	for (int i = 0; s[i]; i ++)
		Print((255 - s[i] + (i == 0 ? 0 : s[i - 1])) % 256);
	return 0;
}