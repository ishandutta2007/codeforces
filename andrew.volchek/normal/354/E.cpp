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

int dp[25][10];
int a[19];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		for (int i = 0; i < 20; i++)
		{
			a[i] = n % 10;
			n /= 10;
		}
		for (int i = 0; i <= 20; i++)
			for (int j = 0; j < 10; j++)
				dp[i][j] = 0;
				
		dp[20][0] = 1;
		for (int i = 19; i >= 0; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int s = 0; s <= 6; s++)
				{
					for (int f = 0; f <= 6 - s; f++)
					{
						int curr = s * 7 + f * 4 + j;
						
						if (curr % 10 == a[i])
							dp[i][j] |= dp[i + 1][curr / 10];
					}
				}
			}
		}
		
		if (!dp[0][0])
		{
			cout << -1 << endl;
			continue;
		}
		
		ll ans[6] = { 0, 0, 0, 0, 0, 0 };
		ll pp = 1;
		
		int p = 0;
		for (int i = 0; i <= 19; i++)
		{
			bool any = false;
			for (int s = 0; s <= 6 && !any; s++)
			{
				for (int f = 0; f <= 6 - s && !any; f++)
				{
					int curr = s * 7 + f * 4 + p;
					
					if ((curr % 10 == a[i]) && dp[i + 1][curr / 10])
					{
						any = true;
						p = curr / 10;
						for (int j = 0; j < s; j++)
						{
							ans[j] += 7LL * pp;
						}
						for (int j = 0; j < f; j++)
						{
							ans[j + s] += 4LL * pp;
						}
					}
				}
			}
			
			pp *= 10;
		}
		
		for (int i = 0; i < 6; i++)
		{
			if (i)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}

	
	return 0;
}