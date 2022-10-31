#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 1 << 20;
const ll mod = 1000000007;

int a[maxn], b[maxn];
ll c[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	c[0] = 1;
	
	for (int i = 1; i < maxn; i++)
	{
		c[i] = (2LL * c[i - 1]) % mod;
	}
	
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		x ^= maxn - 1;
		b[x]++;
	}
	
	for (int len = 2; len <= maxn; len <<= 1)
	{
		for (int i = 0; i < maxn; i += len)
		{
			int cnt = 0;
			for (int j = i + len / 2; j < i + len; j++)
				cnt += b[j];
			for (int j = i + len / 2; j < i + len; j++)
			{
				int t = a[j];
				a[j] = cnt + a[j - len / 2];
				a[j - len / 2] += t;
				
				//while (a[j] < 0) a[i] += mod;
				//while (a[j] >= mod) a[i] -= mod;
			}
		}
		
	}
	
	ll ans = c[n] - 1;
	
	for (int i = 1; i < maxn; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 20; j++)
			cnt += bool(i & (1 << j));
			
		if (cnt & 1)
			ans = (ans + mod - c[n - a[i]] + 1) % mod;
		else
			ans = (ans + c[n - a[i]] - 1) % mod;
	}
	
	cout << ans << endl;
	
	return 0;
}