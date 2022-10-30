#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

int n, m, p;
const int maxn = 1000005;
const ll mod = 1000000007;
int pows[maxn];
int next[maxn][2];
int cnt[maxn];
bool good[maxn];
bool used[maxn];

void die()
{
	cout << 0;
	exit(0);
}

void dfs(int v, int d)
{
	if (!(v - 1 == d || v - 1 - p == d))
		die();
	if (used[v])
		return;
	used[v] = 1;
	for (int i = 0; i < cnt[v]; i++)
	{
		dfs(next[v][i], d+1);
	}
}

int sum[maxn];

int main(int argc, char **argv)
{
	pows[0] = 1;
	for (int i = 1; i <= maxn; i++)
		pows[i] = (pows[i-1]*2) % mod;
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		if (u >= v)
			die();
		if (cnt[u] == 2)
			die();
		next[u][cnt[u]++] = v;
		if (u + 1 == v)
			good[u] = 1;
	}
	
	for (int i = 1; i < n; i++)
	{
		if (!good[i] && cnt[i] == 2)
			die();
		if (!good[i])
			next[i][cnt[i]++] = i+1;
	}
	
	dfs(1, 0);
	
	sum[0] = 0;
	
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i-1] + (cnt[i] == 2);
		//cout << sum[i] << endl;
	}
		
		
	ll ans = 1;
	
	for (int i = 1; i <= n - p - 1; i++)
	{
		if (sum[i-1] == 0 && sum[n] - sum[i + p] == 0)
		{
			//cout << i;
			int cc = max(min(n - p - 1, i + p) - i, 0);
			cc -= sum[min(n - p - 1, i+p)] - sum[i];
			if (cc == 0 && cnt[i] == 2)
			{
			}
			else if (cc == 0)
			{
				ans += 1;
				ans %= mod;
			}
			else
			{
				//cout <<i<<" "<< cc << endl;;
				ans += pows[cc] - (cnt[i] == 2);
				ans %= mod;
			}
		}
	}
	
	cout << ans;
	return 0;
}