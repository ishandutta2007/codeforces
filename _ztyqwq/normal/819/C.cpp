#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
bool isp[1000010];
int pcnt = 0, primes[1000010], num[1000010];
inline void Init(int n)
{
	isp[1] = true;
	for(int i = 2; i <= n; i++)
	{
		if(!isp[i])
			primes[++pcnt] = i, num[i] = i;
		for(int j = 1; j <= pcnt && i * primes[j] <= n; j++)
		{
			isp[i * primes[j]] = true;
			num[i * primes[j]] = primes[j];
			if(i % primes[j] == 0)
				break;
		}
	}
}
inline void Work(map<int, int> &n, int x)
{
	while(x != 1)
	{
		n[num[x]]++;
		x /= num[x];
	}
}
inline int Read(map<int, int> &n)
{
	int a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	Work(n, a), Work(n, b), Work(n, c);
	return a * b * c;
}
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}
inline int dfs(int u, vector<int> &vec, int x)
{
	if(!x)
		return 0;
	if(u == vec.size())
		return x;
	return dfs(u + 1, vec, x) - dfs(u + 1, vec, x / vec[u]);
}
inline int dfs2(int u, vector< pair<int, int> > &vec, int N, int rem, int x)
{
	if(u == vec.size())
		return 1;
	if(x >= N)
		return rem;
	int ans = 0, p = vec[u].first, num = vec[u].second;
	N /= fastpow(vec[u].first, vec[u].second);
	rem /= (vec[u].second + 1);
	for(int i = 0; i <= num; i++)
	{
		ans += dfs2(u + 1, vec, N, rem, x);
		if(!(x /= p))
			break;
	}
	return ans;
}
signed main()
{
	Init(1000000);
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		map<int, int> n, m, s;
		int N = Read(n), M = Read(m), S = Read(s);
		s[2]++, S *= 2;
		vector<int> vec;
		for(auto p: n)
		{
			int k = p.first;
			if(p.second > s[k])
				vec.push_back(fastpow(k, s[k] + 1));
		}
		int ans = dfs(0, vec, M), tot = 1;
		vector< pair<int, int> > vec2;
		for(auto p: s)
			vec2.push_back(p), tot *= (p.second + 1);
		ans += dfs2(0, vec2, S, tot, N);
		printf("%lld\n", ans);
	}
	return 0;
}