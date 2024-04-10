#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
char str[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str + 1);
		n = strlen(str + 1);
		int ans = 0, now = 0, op = 0;
		for (int i = 1; i <= n; i++)
			if (!now) now++, op = str[i] - '0';
			else if (str[i] - '0' == op) now++;
			else now--, ans++;
		puts((ans & 1) ? "DA" : "NET");
	}
	return 0;
}