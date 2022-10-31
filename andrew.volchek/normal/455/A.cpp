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
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100009;

ll a[maxn];
ll dp[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		x += 5;
		a[x]++;
	}
	
	ll ans = 0;
	
	for (int i = 5; i < maxn; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * (i - 5));
		ans = max(dp[i], ans);
	}
	
	cout << ans << endl;
	
	return 0;
}