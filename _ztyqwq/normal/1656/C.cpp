#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[100010];
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		bool f1 = false;
		for(int i = 1; i <= n; i++)
			if(a[i] == 1)
				f1 = true;
		if(!f1)
			printf("YES\n");
		else
		{
			bool flag = true;
			sort(a + 1, a + n + 1);
			for(int i = 1; i < n; i++)
				if(a[i + 1] == a[i] + 1)
				{
					printf("NO\n"), flag = false;
					break;
				}
			if(flag)
				printf("YES\n");
		}
	}
	return 0;
}