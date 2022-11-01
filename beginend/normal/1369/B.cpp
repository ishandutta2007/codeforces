#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
char str[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", str + 1);
		int s1 = 0, s2 = 0;
		for (int i = 1; i <= n; i++)
			if (str[i] == '0') s1++;
			else break;
		for (int i = n; i >= 1; i--)
			if (str[i] == '1') s2++;
			else break;
		if (s1 + s2 == n) printf("%s", str + 1);
		else
		{
			for (int i = 1; i <= s1 + 1; i++) putchar('0');
			for (int i = 1; i <= s2; i++) putchar('1');
		}
		puts("");
	}
	return 0;
}