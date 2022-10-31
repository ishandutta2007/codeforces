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
#define ull long long
#define fst first
#define snd second
#define ld long double

int a[3005], b[3005], c[3005];
int dp[3005][2];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	if (n == 1)
	{
		cout << a[0];
		return 0;
	}

	dp[0][0] = a[0];
	dp[0][1] = b[0];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = -1;
		dp[i][0] = max(dp[i][0], dp[i-1][1] + a[i]);
		dp[i][0] = max(dp[i][0], dp[i-1][0] + b[i]);
		dp[i][1] = -1;
		dp[i][1] = max(dp[i][1], dp[i-1][1] + b[i]);
		dp[i][1] = max(dp[i][1], dp[i-1][0] + c[i]);
	}
	
	cout << dp[n-1][0];

	//cin >> n;

	return 0;
}