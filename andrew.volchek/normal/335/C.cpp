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

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

int dp[105][4][4];

int rec(int len, int l, int r)
{	
	if (!len)
		return 0;
		
	if (dp[len][l][r] != -1)
		return dp[len][l][r];
		
	set < int > mex;
		
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			if (i == 0 && l == (3 - j))
				continue;
			if (i == (len-1) && r == (3 - j))
				continue;
				
			int res = rec(i, l, j) ^ rec(len - i - 1, j, r);
			
			mex.insert(res);
		}
	}
	int res = 0;
	
	for (int i = 0; i < 10000; i++)
	{
		if (mex.find(i) == mex.end())
		{
			res = i;
			break;
		}
	}
	
	return dp[len][l][r] = res;
}

int arr[200];

int main(int argc, char **argv)
{
	for (int i = 0; i < 200; i++)
		arr[i] = 3;
		
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 4; j++)
			for (int h = 0; h < 4; h++)
				dp[i][j][h] = -1;
		
	int r, n;
	cin >> r >> n;
	
	for (int i = 0; i < n; i++)
	{
		int rr, cc;
		cin >> rr >> cc;
		arr[rr] = cc;
	}
	
	int ans = 0;
	
	for (int i = 1; i <= r; i++)
	{
		if (arr[i] != 3)
			continue;
			
		int j = i;
		while (j <= r && arr[j] == 3)
			j++;
		//cout << j - i << " " << arr[i-1] << " " << arr[j] << endl;
		ans ^= rec(j - i, arr[i-1], arr[j]);
		i = j;
	}
	
	if (!ans)
		cout << "LOSE";
	else
		cout << "WIN";

	return 0;
}