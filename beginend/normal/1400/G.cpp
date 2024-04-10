#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 300005;
const int M = 25;
const int MOD = 998244353;

int n, m, fac[N], ifac[N], cho[N], tot, f[M * 2];
bool vis[N];
struct data{int x, y;}edg[M];
vector<int> e[N], ins[N], del[N];

void pre()
{
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= n; i++) fac[i] = (LL)fac[i - 1] * i % MOD, ifac[i] = (LL)(MOD - MOD / i) * ifac[MOD % i] % MOD;
	for (int i = 2; i <= n; i++) ifac[i] = (LL)ifac[i - 1] * ifac[i] % MOD;
}

int C(int n, int m)
{
	return n < m ? 0 : (LL)fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

void del_edge(int x, int y)
{
	if (x > y) swap(x, y);
	for (int i = 1; i <= tot; i++) if (edg[i].x == x && edg[i].y == y)
	{
		for (int j = i; j < tot; j++) edg[j] = edg[j + 1];
		break;
	} 
	tot--;
}

void ins_edge(int x, int y)
{
	if (x > y) swap(x, y);
	edg[++tot] = (data){x, y};
}

void dfs(int x, int y, int s)
{
	if (x > tot) {f[s] += y; return;}
	dfs(x + 1, y, s);
	s += (!cho[edg[x].x]) + (!cho[edg[x].y]);
	cho[edg[x].x]++; cho[edg[x].y]++;
	dfs(x + 1, -y, s);
	cho[edg[x].x]--; cho[edg[x].y]--;
}

void calc()
{
	for (int i = 0; i <= m * 2; i++) f[i] = 0;
	dfs(1, 1, 0);
}

int main()
{
	scanf("%d%d", &n, &m);
	pre();
	for (int i = 1; i <= n; i++)
	{
		int l, r; scanf("%d%d", &l, &r);
		ins[l].push_back(i); del[r + 1].push_back(i);
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		e[x].push_back(y); e[y].push_back(x);
	}
	int sum = 0, ans = 0;
	calc();
	for (int i = 1; i <= n; i++)
	{
		bool flag = 0;
		for (int x : del[i])
		{
			for (int y : e[x]) if (vis[y]) del_edge(x, y), flag = 1;
			vis[x] = 0; sum--;
		}
		for (int x : ins[i])
		{
			for (int y : e[x]) if (vis[y]) ins_edge(x, y), flag = 1;
			vis[x] = 1; sum++;
		}
		if (flag) calc();
		for (int j = 0; j <= min(i, tot * 2); j++) (ans += (LL)C(sum - j, i - j) * f[j] % MOD) %= MOD;
	}
	printf("%d\n", (ans + MOD) % MOD);
	return 0;
}