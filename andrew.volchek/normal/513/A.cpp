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


int dp[55][55][2];

int n1, k1, n2, k2;


int rec(int i, int j, int p)
{
	if (dp[i][j][p] != -1)
		return dp[i][j][p];
	
	int res = 0;
	if (p == 0)
	{
		for (int h = 1; h <= k1; h++)
			if (i >= h)
				res |= !rec(i - h, j, 1 - p);
	} 
	else
	{
		for (int h = 1; h <= k2; h++)
			if (j >= h)
				res |= !rec(i, j - h, 1 - p);
	}
	
	return dp[i][j][p] = res;
}


int main()
{
//	srand(time(NULL));
//	gen();
//	freopen("a.in", "r", stdin);

	for (int i = 0; i < 55; i++)
		for (int j = 0; j < 55; j++)
			for (int h = 0; h < 2; h++)
				dp[i][j][h] = -1;

		
	
	
	cin >> n1 >> n2 >> k1 >> k2;
	
	if (rec(n1, n2, 0))
		printf("First");
	else
		printf("Second");

	
	
	
	return 0;
}