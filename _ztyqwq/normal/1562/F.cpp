#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
bool isp[200010];
int primes[200010], pcnt = 0;
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
inline int gcd(int x, int y)
{
	return __gcd(x, y);
}
int TOT = 0;
inline int Ask(int x, int y)
{
	printf("? %lld %lld\n", x, y);
	fflush(stdout);
	int res;
	scanf("%lld", &res);
	return res;
}
int ans[100010];
vector<int> ansid[400010];
int b[200010];
signed main()
{
	srand(20060723);
	Init(200000);
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= 400000; i++)
			if(ansid[i].size())
				ansid[i].clear();
		vector<int> dones1;
		int pos1, pos2;
		while(true)
		{
			int x = rand() % n + 1;
			if(ans[x])
				continue;
			int TIMES = 100, res = 0;
			while(TIMES--)
			{
				int y = rand() % n + 1;
				if(x == y)
				{
					TIMES++;
					continue;
				}
				res = gcd(res, Ask(x, y));
			}
			ans[x] = res, ansid[res].push_back(x);
			dones1.push_back(x);
			for(auto val: dones1)
				if(gcd(ans[val], ans[x]) == 1)
				{
					pos1 = val, pos2 = x;
					goto done1;
				}
			if(dones1.size() == n)
			{
				for(int i = 400000; i >= 1; i--)
					if(ansid[i].size() && !ansid[i - 1].size())
					{
						ans[ansid[i][0]] = i / 2;
						goto done1;
					}
			}
		}
		done1:
		if(n <= 3000)
		{
			for(int i = 1; i <= n; i++)
				if(!ans[i])
					ans[i] = gcd(Ask(i, pos1), Ask(i, pos2));
		}
		else
		{
			int prime;
			while(true)
			{
				int x = rand() % n + 1;
				if(ans[x])
					continue;
				int res = gcd(Ask(x, pos1), Ask(x, pos2));
				ans[x] = res, ansid[res].push_back(x);
				if(!isp[res] && res >= 1000)
				{
					prime = x;
					break;
				}
			}
			for(int i = 1; i <= n; i++)
				if(!ans[i])
				{
					ans[i] = Ask(i, prime) / ans[prime];
					ansid[ans[i]].push_back(i);
				}
			for(int i = 200000; i >= 1; i--)
			{
				if(i % ans[prime] == 0)
				{
					int u = i / ans[prime];
					if(!ansid[i - 1].size() && !ansid[i + 1].size())
						continue;
					for(vector<int> :: iterator iter = ansid[u].begin(); iter != ansid[u].end(); iter++)
					{
						int x = *iter;
						int res = gcd(Ask(x, pos1), Ask(x, pos2));
						if(res != u)
						{
							ans[x] = res, ansid[res].push_back(x);
							ansid[u].erase(iter);
							break;
						}
					}
				}
			}
			
		}
		putchar('!');
		for(int i = 1; i <= n; i++)
			printf(" %lld", ans[i]);
		putchar('\n');
		fflush(stdout);
	}
	return 0;
}