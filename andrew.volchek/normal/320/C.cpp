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

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

const int maxn = 10000;
const int inf = 1000000000;
const ll mod = 1000000007;

int n;
char str[111];
unsigned long long dp[111];


int main(int argc, char **argv)
{
	gets(str);
	n = strlen(str);
	ll pp = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		dp[i] = 0;
		if (str[i] == '1')
		{
			dp[i] += pp*pp;
			dp[i] %= mod;
		}
		if (i != n-1)
		{
			dp[i] += dp[i+1] * 2;
			dp[i] %= mod;
		}
		pp *= 2;
		pp	%= mod;
	}
	cout << dp[0] % mod;
	return 0;
}