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
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

const int maxn = 150005;

int a[maxn];
int b[maxn];

int mMin[4 * maxn], mMax[4 * maxn], delta[4 * maxn];

void build(int v, int l, int r)
{
	if (l == r)
	{
		mMin[v] = mMax[v] = l;
		return;
	}
	
	int c = (l + r) / 2;
	
	build(2*v, l, c);
	build(2*v + 1, c + 1, r);
	
	mMin[v] = min(mMin[2*v], mMin[2*v + 1]);
	mMax[v] = max(mMax[2*v], mMax[2*v + 1]);
}

void modify(int v, int l, int r, int i, int j, int d)
{
	if (i <= l && r <= j)
	{
		mMin[v] += d;
		mMax[v] += d;
		delta[v] += d;
		return;
	}
	
	int c = (l + r) / 2;
	
	if (i <= c)
		modify(2*v, l, c, i, j, d);
	if (c < j)
		modify(2*v + 1, c+1, r, i, j, d);
		
	mMin[v] = min(mMin[2*v], mMin[2*v + 1]) + delta[v];
	mMax[v] = max(mMax[2*v], mMax[2*v + 1]) + delta[v];
}

int resMin, resMax;

void get(int v, int l, int r, int i, int j, int d)
{
	if (i <= l && r <= j)
	{
		resMin = min(resMin, mMin[v] + d);
		resMax = max(resMax, mMax[v] + d);
		return;
	}
	
	int c = (l + r) / 2;
	
	if (i <= c)
		get(2*v, l, c, i, j, d + delta[v]);
	if (c < j)
		get(2*v + 1, c+1, r, i, j, d + delta[v]);
}

int was[maxn];
const int inf = 1000000005;

int main()
{
	int n, len, h;
	scanf("%d %d %d", &n, &len, &h);
	
	for (int i = 0; i < len; i++)
		scanf("%d", b + i);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
		
	sort(b, b + len);
	
	build(1, 1, len+1);
	
	int ans = 0;
	int badCount = 0;
	for (int i = 0; i < n; i++)
	{
		if (i - len >= 0)
		{
			if (was[i-len] == len)
				badCount--;
			else
				modify(1, 1, len+1, was[i-len]+1, len+1, +1);
		}
		
		was[i] = lower_bound(b, b + len, h - a[i]) - b;
		
		if (was[i] == len)
		{
			badCount++;
			continue;
		}
		
		modify(1, 1, len+1, was[i]+1, len+1, -1);
		
		if (!badCount && i+1 >= len)
		{
			resMax = -inf;
			resMin = inf;
			get(1, 1, len+1, 1, len, 0);
			
			if (resMax <= 0)
				ans++;
		}
	}
	
	printf("%d", ans);
			
	return 0;
}