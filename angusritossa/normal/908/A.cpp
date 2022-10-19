#include <bits/stdc++.h>
using namespace std;
char s[10010];
int ans;
int main()
{
	scanf(" %s", s);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ans++;
		if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9') ans++;
	}
	printf("%d\n", ans);
}