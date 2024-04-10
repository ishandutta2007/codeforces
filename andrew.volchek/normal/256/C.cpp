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

const int maxn = 1000005;

int dp[maxn];

ll pow2(ll x)
{
	ll res = sqrt(x);
	while (res * res <= x) res++;
	return res - 1;
}

int mex[maxn];
int currUsed = 1;



int tree[4 * maxn];
int sum[4 * maxn];

void modify(int v, int l, int r, int i, int val)
{
	if (l == r)
	{
		tree[v] += val;
		sum[v] = tree[v] > 0;
		return;
	}
	
	int c = (l + r) >> 1;
	
	if (i <= c)
		modify(2 * v, l, c, i, val);
	else
		modify(2 * v + 1, c + 1, r, i, val);
		
	sum[v] = sum[2 * v] + sum[2 * v + 1];
		
}

int get(int v, int l, int r)
{
	if (l == r)
		return l;
		
	int c = (l + r) >> 1;
	
	if (sum[2 * v] == (c - l + 1))
		return get(2 * v + 1, c + 1, r);
	else
		return get(2 * v, l, c);
}

vector < int > q[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	ll m = 0;
	for (int i = 1; i < maxn; i++)
	{
		int p2 = pow2(i);
		ll p4 = max(0.0, pow(i, 1.0 / 4) - 1);
		
		while (p4 * p4 * p4 * p4 < i)
			p4++;
			
		p2 = min(p2, i - 1);
		
			
		currUsed++;
		for (int j = p4; j <= p2; j++)
		{
			mex[dp[j]] = currUsed;
		}
		
		int res = 0;
		while (mex[res] == currUsed) res++;
		dp[i] = res;
	
	}
	
	
	
	int n;
	cin >> n;
	
	ll ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		
		if (x < maxn)
		{
			ans ^= dp[x];
			continue;
		}
		
		ll p2 = pow2(x);
		ll p4 = max(0.0, pow(x, 1.0 / 4) - 1);
		while (p4 * p4 * p4 * p4 < x) p4++;
		
		
		p2 = min(p2, x - 1);
		
	//	cerr << p4 << endl;
		if (p2 >= p4)
			q[p4].pb(p2);
	}
	
	for (int i = 0; i < maxn; i++)
		sort(q[i].begin(), q[i].end());
		
	int r = -1;
	

	for (int i = 0; i < maxn; i++)
	{
		if (r < i)
		{
			r = i;
			modify(1, 0, maxn - 1, dp[i], 1);
		}
		
		for (int j = 0; j < q[i].size(); j++)
		{
			
			while (r < q[i][j])
			{
				modify(1, 0, maxn - 1, dp[r + 1], 1);
				r = r + 1;
			}
			
			int res = get(1, 0, maxn - 1);
			//cerr << i << " " << q[i][j]  << endl;
			//cerr << res << endl;
			ans ^= res;
		}
		
		
		modify(1, 0, maxn - 1, dp[i], -1);
	}
	
	if (ans)
		puts("Furlo");
	else
		puts("Rublo");
	
	return 0;
}