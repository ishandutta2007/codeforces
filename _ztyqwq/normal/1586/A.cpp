#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int primes[20000], pcnt = 0;
bool isp[40000];
inline void Init(int n)
{
	isp[1] = true;
	for(int i = 2; i <= n; i++)
	{
		if(!isp[i])
			primes[++pcnt] = i;
		for(int j = 1; j <= pcnt && i * primes[j] <= n; j++)
		{
			isp[i * primes[j]] = true;
			if(i % primes[j] == 0)
				break;
		}
	}
}
int a[110];
signed main()
{
	Init(20000);
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n, sum = 0;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]), sum += a[i];
		if(n <= 15)
		{
			vector<int> ans;
			int mx = (1 << n);
			for(int i = 0; i < mx; i++)
			{
				int tot = 0;
				vector<int> aans;
				for(int j = 1; j <= n; j++)
					if((i >> (j - 1)) & 1)
						tot += a[j], aans.push_back(j);
				if(isp[tot])
				{
					if(aans.size() > ans.size())
						ans = aans;
				}
			}
			printf("%d\n", ans.size());
			for(auto x: ans)
				printf("%d ", x);
			putchar('\n');
		}
		else
		{
			if(isp[sum])
			{
				printf("%d\n", n);
				for(int i = 1; i <= n; i++)
					printf("%d ", i);
				putchar('\n');
				goto no;
			}
			for(int i = 1; i <= n; i++)
				if(isp[sum - a[i]])
				{
					printf("%d\n", n - 1);
					for(int j = 1; j <= n; j++)
						if(j != i)
							printf("%d ", j);
					putchar('\n');
					goto no;
				}
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					if(i != j && isp[sum - a[i] - a[j]])
					{
						printf("%d\n", n - 2);
						for(int k = 1; k <= n; k++)
							if(k != i && k != j)
								printf("%d ", k);
						putchar('\n');
					}
			no: ;
		}
	}
	return 0;
}