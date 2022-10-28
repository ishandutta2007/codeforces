#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int M = 5e6 + 5;

int n;
int a[N];
int sieve[M], mult[M], dp[M];

int32_t main()
{
	IOS;
	cin >> n;
	int g = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		g = __gcd(g, a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		a[i] /= g;
		sieve[a[i]]++;
	}
	for(int i = 1; i < M; i++)
	{
		for(int j = 1; i * j < M; j++)
			mult[i] += sieve[i * j];
	}
	for(int i = M - 1; i >= 1; i--)
	{
	    dp[i] = i * sieve[i];
		for(int j = 1; i * j < M; j++)
			dp[i] = max(dp[i], dp[i * j] + (mult[i] - mult[i * j]) * i);
	}
	cout << dp[1] * g;
	return 0;
}