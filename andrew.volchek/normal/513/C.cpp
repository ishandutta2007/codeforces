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
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

int l[6], r[6];

ld below(int i, int x)
{
	if (r[i] < x)
		return 1;
	if (l[i] > x)
		return 0;
		
	return ((ld)x - l[i]) / (r[i] - l[i] + 1);
}

ld exact(int i, int x)
{
	if (r[i] < x)
		return 0;
	if (l[i] > x)
		return 0;
	return 1.0 / (r[i] - l[i] + 1);
}


ld greater2(int i, int x)
{
	if (l[i] > x)
		return 1;
	if (r[i] < x)
		return 0;
	return ((ld)r[i] - x) / (r[i] - l[i] + 1);
}


const int maxn = 10003;
ld dp[7][maxn];

int main()
{
//	srand(time(NULL));
//	gen();
//	freopen("a.in", "r", stdin);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] >> r[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int val = 10000; val >= 0; val--)
			dp[i][val] = dp[i][val + 1] + exact(i, val);
	}
	
	ld ans = 0;
	for (int val = 0; val < maxn; val++)
	{
		for (int win = 1; win < (1 << n); win++)
		{
			ld p = 1;
			int cnt = 0;
			for (int i = 0; i < n; i++)
				if (win & (1 << i))
				{
					p *= exact(i, val);
					cnt++;
				}
				else
					p *= below(i, val);
			if (cnt > 1)
				ans += val * p;
		}
	}
	
	for (int val = 0; val < maxn; val++)
	{
		for (int win = 0; win < n; win++)
		{
			for (int second = 1; second < (1 << n); second++)
			{
				if (second & (1 << win))
					continue;
					
				int lose = ((1 << n) - 1) ^ second ^ (1 << win);
				ld p = dp[win][val + 1];
				for (int j = 0; j < n; j++)
					if (second & (1 << j))
						p *= exact(j, val);
				for (int j = 0; j < n; j++)
					if (lose & (1 << j))
						p *= below(j, val);
				ans += p * val;
			}
		}
	}
	
	/*for (int val = 0; val <= 10000; val++)
	{
		ld p = 1;
		for (int j = 0; j < n; j++)
			p *= exact(j, val);
		ans += val * p;
	}*/
	
	
	cout.precision(10);
	cout << fixed << ans << endl;
	

	return 0;
}