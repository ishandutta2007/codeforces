#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
struct Edge
{
	int to, nxt;
}e[200010];
int head[100010], ecnt = 0;
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int deg[100010], dcnt[100010];
inline void AddDiv(int x)
{
	int s = sqrt(x);
	for(int i = 1; i <= s; i++)
		if(x % i == 0)
		{
			dcnt[i]++;
			if(i * i != x)
				dcnt[x / i]++;
		}
}
int dfs(int u, int fa, int x) // 1: after father, 0: before father, -1: nope
{
	int cnt = 0;
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa)
			continue;
		int st = dfs(v, u, x);
		if(st == -1)
			return -1;
		cnt += st;
	}
	if(cnt % x == 0)
		return 1;
	else if(cnt % x == x - 1)
		return 0;
	else
		return -1;
}
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = (ll)ans * a % mod;
		a = (ll)a * a % mod;
		n >>= 1;
	}
	return ans;
}
int ans[100010];
int primes[100010], mu[100010], pcnt = 0;
bool isp[100010];
inline void Init(int n)
{
	isp[1] = true;
	mu[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!isp[i])
			primes[++pcnt] = i, mu[i] = -1;
		for(int j = 1; j <= pcnt && i * primes[j] <= n; j++)
		{
			isp[i * primes[j]] = true;
			if(i % primes[j] == 0)
			{
				mu[i * primes[j]] = 0;
				break;
			}
			mu[i * primes[j]] = -mu[i];
		}
	}
}
int main()
{
	Init(100000);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		ecnt = 0;
		for(int i = 1; i <= n; i++)
			head[i] = -1, deg[i] = dcnt[i] = ans[i] = 0;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			addedge(u, v), deg[u]++;
			addedge(v, u), deg[v]++;
		}
		if(n == 2)
		{
			printf("2 0\n");
			continue;
		}
		int r = 0;
		for(int i = 1; i <= n; i++)
			if(deg[i] >= 2)
			{
				r = i;
				break;
			}
		int dtot = 0;
		for(int i = 1; i <= n; i++)
		{
			int cnt = 0;
			for(int j = head[i]; j != -1; j = e[j].nxt)
				cnt += (deg[e[j].to] == 1);
			if(deg[i] >= 2 && deg[i] - cnt <= 1)
			{
				AddDiv(deg[i]);
				AddDiv(deg[i] - 1);
				dtot++;
			}
		}
		for(int i = 2; i <= n; i++)
			if(dcnt[i] == dtot)
			{
				int st = dfs(r, r, i);
				if(st == 1)
					ans[i] = 1;
			}
		ans[1] = fastpow(2, n - 1);
		for(int i = 1; i <= n; i++)
			for(int j = 2; i * j <= n; j++)
				ans[i] += mu[j] * ans[i * j];
		for(int i = 1; i <= n; i++)
			printf("%d ", (ans[i] + mod) % mod);
		putchar('\n');
	}
	return 0;
}