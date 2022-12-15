#include <stdio.h>

int n;
char str[100100];

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	int a = 0, d = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'A') a++;
		else if(str[i] == 'D') d++;
	}
	if (a > d) printf("Anton");
	else if (a < d) printf("Danik");
	else printf("Friendship");
	return 0;
}