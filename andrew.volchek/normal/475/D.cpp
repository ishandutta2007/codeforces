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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

int gcd(int a, int b)
{
	return a ? gcd(b % a, a) : b;
}

map < int, ll > ans;

int main()
{
	int n;
	scanf("%d", &n);
	
	vector < pair < int, int > > dp;
	int x;
	scanf("%d", &x);
	dp.pb(mp(x, 0));
	ans[x]++;
	
	for (int i = 1; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		vector < pair < int, int > > ndp;
		pair < int, int > curr = mp(x, i);
		for (int j = 0; j < dp.size(); j++)
		{
			int g = gcd(dp[j].fst, x);
			if (g == curr.fst)
			{
				curr.snd = dp[j].snd;
			}
			else
			{
				ndp.pb(curr);
				curr.fst = g;
				curr.snd = dp[j].snd;
			}
		}
		ndp.pb(curr);
		int prv = i + 1;
		for (int j = 0; j < ndp.size(); j++)
		{
			ans[ndp[j].fst] += prv - ndp[j].snd;
			prv = ndp[j].snd;
		}
		dp = ndp;
	}
	
	int q;
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%I64d\n", ans[x]);
	}
	
	return 0;
}