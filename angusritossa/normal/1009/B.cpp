#include <bits/stdc++.h>
using namespace std;
char str[100010];
int n, numones;
int main()
{
	scanf(" %s", str);
	n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '1') numones++;
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '2')
		{
			while (numones-- > 0) printf("1");
		}
		if (str[i] != '1') printf("%c", str[i]);
	}
	while (numones-- > 0) printf("1");
	printf("\n");
}