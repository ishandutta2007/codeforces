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
map < pair < int, ll > , pair < ll, int > > mem;

pair < ll, int > rec(int currLen, int maxFromLeft, ll curr)
{
	//cout << currLen << " " << curr << endl;
	if (mem.find(mp(maxFromLeft, curr)) != mem.end())
		return mem[mp(maxFromLeft, curr)];
	
	ll curr2 = curr;
	if (currLen == 1)
	{
		return mp(1, curr - max((int)curr, maxFromLeft));
	}
	ll ans = 0;
	ll currPow = 1;
		for (int i = 0; i < currLen-1; i++)
			currPow *= 10LL;
	while (curr > 0)
	{
		ll temp = curr;
		for (int i = 0; i < currLen-1; i++)
			temp /= 10;
		int currDigit = temp;
		
		if (curr % currPow == 0)
		{
			int currMax = max(currDigit, maxFromLeft);
			ans++;
			curr -= currMax;
			continue;
		}
		
			
		pair < ll, ll > recAns = rec(currLen-1, max(maxFromLeft, currDigit), curr % currPow);
		ans += recAns.fst;
		curr = currPow * currDigit + recAns.snd;
	}
	return mem[mp(maxFromLeft, curr2)] = mp(ans, curr);
}

int dp[1000005][10];
int dp3[1000005][10];
int dp2[1000005];

int main(int argc, char **argv)
{
	/*ll n;
	cin >> n;
	int len = 0;
	ll nn = n;
	while (nn)
	{
		len++; nn /= 10;
	}
	pair < ll, ll > ans = rec(len, 0, n);
	cout << ans.fst;*/
	/*for (int i = 1; i <= 1000000; i++)
	{
		dp2[i] = max(dp2[i / 10], i % 10);
	}

	for (int i = 1; i <= 1000000; i++)
	for (int j = 0; j < 10; j++)
	{
		int curr = i - max(j, dp2[i]);
		if (curr > 0)
		{
			dp[i][j] = dp[curr][j] + 1;
			dp3[i][j] = dp3[curr][j];
		}
		else
		{
			dp[i][j] = 1;
			dp3[i][j] = curr;
		}
		
	}
	
	ll nn;
	cin >> nn;

	
	ll ans = 0;
	while (nn > 1000000)
	{
		//cout << nn << endl;
		ll aa = nn;
		for (int i = 0; i < 6; i++)
			aa /= 10LL;
		int mm = 0;
		while (aa)
		{
			mm = max(mm,int(aa % 10LL));
			aa /= 10LL;
		}
		int nnmod = nn % 1000000LL;
		if (nnmod == 0)
		{
			nn -= mm;
			ans++;
			continue;
		}
		ans += dp[nnmod][mm];
		
		nn -= nnmod - dp3[nnmod][mm];
	}
	ans += dp[nn][0];
	cout << ans << endl;;
	
	//printf("%.3lf", clock() / (double) CLOCKS_PER_SEC);*/
	ll n;
	cin >> n;
	int len = 0;
	ll nn = n;
	while (nn)
	{
		len++; nn /= 10;
	}
	pair < ll, ll > ans = rec(len, 0, n);
	cout << ans.fst;
	return 0;
}