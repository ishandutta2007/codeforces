#include <bits/stdc++.h>
using namespace std;
int b[30];
int main()
{
	string s;
	cin >> s;
	memset(b, 0, sizeof(b));
	int len = s.size();
	for(int i = 1; i <= len; i++)
		b[i] = s[i - 1] - 'A';
	for(int i = 1; i <= len - 2; i++)
		if(b[i + 2] != (b[i] + b[i + 1]) % 26)
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}