/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9;
int n, a[N], v[N], lim, pep[N], now;
int sta[N], cnt[N], mu[N], vis[N], prime[N], ans, top;
vector<int> d[N];
inline void sieve(int x)
{
	int eq = 0;
	mu[1] = 1;
	for (int i = 2; i <= x; i++)
	{
		if(!vis[i]) prime[++eq] = i, mu[i] = -1;
		for (int j = 1; j <= eq && prime[j] * i <= x; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
			mu[i * prime[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= x; i++)
		for (int j = i; j <= x; j += i)
			d[j].push_back(i);
}
inline int Gcd(int x, int y)
{
	if(y == 0) return x;
	return Gcd(y, x % y);
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), pep[a[i]] = 1, lim = max(lim, a[i]), ans = max(ans, a[i]);
	sieve(lim);
	for (int p = 1; p <= lim; p++)
	{
		now = 0;
		for (int i = (lim / p) * p; i >= p; i -= p)
			for (int j = 1; j <= pep[i]; j++)
				v[++now] = i / p;
		top = 0;
		for (int i = 1; i <= now; i++)
		{
			int sum = 0;
			for (int j = 0; j < d[v[i]].size(); j++) sum += mu[d[v[i]][j]] * cnt[d[v[i]][j]];
			//cout << i << " " << v[i] << " " << sum << endl;
			while(sum)
			{
				int pos = sta[top--];
				if(Gcd(pos, v[i]) == 1) sum--, ans = max(ans, pos * v[i] * p);
				for (int j = 0; j < d[pos].size(); j++) cnt[d[pos][j]]--;
			}
			sta[++top] = v[i];
			for (int j = 0; j < d[v[i]].size(); j++) cnt[d[v[i]][j]]++;
		}
		while(top)
		{
			int pos = sta[top--];
			for (int j = 0; j < d[pos].size(); j++) cnt[d[pos][j]]--;
		}
	}
	cout << ans << endl;
	return 0;
}