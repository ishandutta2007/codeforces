#include <bits/stdc++.h>
using namespace std;
int b[1010][12];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		int cnt = 0, x = i;
		while(x)
		{
			b[i][++cnt] = x % k;
			x /= k;
		}
		mx = max(mx, cnt);
	}
	printf("%d\n", mx);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			for(int c = mx; c >= 1; c--)
				if(b[i][c] != b[j][c])
				{
					printf("%d ", c);
					break;
				}
		}
	putchar('\n');
	return 0;
}