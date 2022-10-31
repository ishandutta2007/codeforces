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

const int maxn = 605;

int a[maxn], b[maxn];

int dp[maxn][maxn];
int nxt[maxn][maxn];

int rec(int l, int r)
{
	if (l > r)
		return 1;
		
	if (dp[l][r] != -1)
		return dp[l][r];
		
	if (l == r)
	{
		return a[l] == 1;
	}
	
	for (int i = l; i <= r; i++)
	{
		int cnt = (i - l) * 2 + 1;
		
		if (a[l] <= cnt && cnt <= b[l] && rec(l + 1, i) && rec(i + 1, r))
		{
			nxt[l][r] = i;
			return dp[l][r] = 1;
		}
	}
	
	return dp[l][r] = 0;
}

string construct(int l, int r)
{
	if (l > r)
		return "";
		
	if (l == r)
		return "()";
		
	return "(" + construct(l + 1, nxt[l][r]) + ")" + construct(nxt[l][r] + 1, r);
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
		
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			dp[i][j] = -1;
			
	if (!rec(0, n - 1))
		cout << "IMPOSSIBLE" << endl;
	else
		cout << construct(0, n - 1) << endl;
	
	
	return 0;
}