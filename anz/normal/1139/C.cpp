#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

long long n, k;
vector <long long> graph[100001];

const long long MOD = 1000000007;

long long mPow(long long n, long long a)
{
	if (a == 1) return n;
	if (a & 1)
	{
		return (mPow(n, a - 1)*n) % MOD;
	}
	else
	{
		long long t = mPow(n, a / 2);
		return t * t%MOD;
	}
}

int cache[100001];

long long DFS(int start)
{
	cache[start] = 1;
	long long result = 1;
	for (int i = 0; i < graph[start].size(); i++)
	{
		if (cache[graph[start][i]]) continue;
		result += DFS(graph[start][i]);
	}
	return result;
}

int main()
{
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n - 1; i++)
	{
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (c == 0)
		{
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}

	long long result = mPow(n, k);

	for (int i = 1; i <= n; i++)
	{
		if (cache[i]) continue;
		long long tmp = DFS(i);

		result -= mPow(tmp, k);
		result = (result + MOD) % MOD;

	}

	printf("%lld", result);
}