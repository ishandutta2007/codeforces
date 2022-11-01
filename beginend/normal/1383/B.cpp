#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int p = -1, s1, s2;
		for (int i = 30; i >= 0; i--)
		{
			s1 = s2 = 0;
			for (int j = 1; j <= n; j++)
				if (a[j] & (1 << i)) s1++;
				else s2++;
			if (s1 & 1) {p = i; break;}
		}
		if (p == -1)
		{
			puts("DRAW");
			continue;
		}
		s1 %= 4; s2 %= 2;
		if (s2) puts("WIN");
		else if (s1 == 1) puts("WIN");
		else puts("LOSE");
	}
	return 0;
}