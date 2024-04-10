#include <bits/stdc++.h>
using namespace std;
int a[10010];
signed main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int l = 1, r = n;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			printf("? %d %d\n", l, mid);
			fflush(stdout);
			int tot = 0;
			for(int i = l; i <= mid; i++)
			{
				int x;
				scanf("%d", &x);
				tot += (x >= l && x <= mid);
			}
			if(tot & 1)
				r = mid;
			else
				l = mid + 1;
		}
		printf("! %d\n", l);
		fflush(stdout);
	}
	return 0;
}