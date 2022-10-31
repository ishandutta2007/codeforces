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

const ll mod = 1000000007;
ll dp[2005][2005];

ll rec(int a, int b)
{
	if (dp[a][b] != -1)	
		return dp[a][b];
	
		
	ll res = 0;
	
	if (a > 0)
	{
		if (a > 1)
			res += (a - 1) * rec(a - 2, b + 1);
		
		res %= mod;
		
		if (b > 0)
			res += b * rec(a - 1, b);
	}
	else if (a == 0)
	{
		ll curr = 1;;
		for (int i = 1; i <= b; i++)
			curr = (curr * i) % mod;
			
		res += curr;
	}
	
	return dp[a][b] = res % mod;
}

int arr[2005];
bool ab[2005];

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] != -1)
			ab[arr[i]-1] = 1;
	}
	int a=0, b=0;
	
	for (int i = 0; i < 2005; i++)
		for (int j = 0; j < 2005; j++)
			dp[i][j] = -1;
	
	for (int i =  0; i < n; i++)
	{
		if (arr[i] == -1)
		{
			if (ab[i])
				b++;
			else
				a++;
		}
	}
	
	
	cout << rec(a, b);
	
	return 0;
}