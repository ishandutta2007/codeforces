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

int a[105];


int p[] = {2,       3,      5,      7,     11,     13,     17,     19,     23,     29 ,
     31,     37,     41,     43,     47,     53, };
const int pc = 16;

int mask[100];

ll dp[105][1 << pc];
int ans[105][1 << pc];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	for (int i = 1; i < 100; i++)
		for (int j = 0; j < pc; j++)
			if (i % p[j] == 0)
				mask[i] |= 1 << j;
				
	const ll inf = 1e9;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < (1 << pc); j++)
		{
			dp[i][j] = inf;
			for (int h = 1; h <= 60; h++)
			{
				if ((mask[h] & j) != mask[h])
					continue;
				ll curr = (ll)abs(a[i] - h) + dp[i - 1][j ^ mask[h]];
				if (curr < dp[i][j])
				{
					dp[i][j] = curr;
					ans[i][j] = h;
				}
			}
		}
	}
	
	int r = 0;
	for (int i = 0; i < (1 << pc); i++)
		if (dp[n][r] > dp[n][i])
			r = i;
			
	vector < int > b;
	
	for (int i = n; i >= 1; i--)
	{
		b.pb(ans[i][r]);
		r ^= mask[ans[i][r]];
	}
	
	reverse(b.begin(), b.end());
	
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
		cout << b[i];
	}
	
	return 0;
}