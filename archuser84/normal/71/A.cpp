#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	char s[102][102];
	cin >> n;
	
	for (int i = 0; i < n; i++)
		scanf("%s", &s[i]);
	
	for (int i = 0; i < n; i++)
	{
		int l = strlen(s[i]);
		if (l > 10)
			printf("%c%i%c\n", s[i][0], l - 2, s[i][l - 1]);
		else
			printf("%s\n", s[i]);
	}
}