#include<bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, k;
char str[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		scanf("%s", str + 1);
		bool flag = 0;
		int s0 = 0, s1 = 0;
		for (int i = 1; i <= k; i++)
		{
			int s = 0;
			for (int j = i; j <= n; j += k)
			{
				if (str[j] == '0') s |= 1;
				else if (str[j] == '1') s |= 2;
			}
			if (s == 3) {flag = 1; break;}
			if (s == 1) s0++;
			else if (s == 2) s1++;
		}
		if (s0 <= k / 2 && s1 <= k / 2 && !flag) puts("YES");
		else puts("NO");
	}
	return 0;
}