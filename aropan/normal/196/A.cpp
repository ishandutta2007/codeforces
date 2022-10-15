#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


const int MAXL = 100007;

char s[MAXL];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif


	gets(s);
	int n = strlen(s);
	int last = 0;
	for (int c = 'z'; c >= 'a'; c--)
	{
		for (int i = last; i < n; i++)
			if (s[i] == c)
			{
				printf("%c", s[i]);
				last = i;
			}
	}
	printf("\n");
	return 0;	
}