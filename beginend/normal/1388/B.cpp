#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		int num = (n + 3) / 4;
		for (int i = 1; i <= n - num; i++) putchar('9');
		for (int i = 1; i <= num; i++) putchar('8');
		puts("");
	}
	return 0;
}