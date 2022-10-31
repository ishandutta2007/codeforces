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


const int maxn = 50005;
char str[maxn];
int cnt[26];
int dp[3000][3000];

int main(int argc, char **argv)
{
	gets(str);
	int len = strlen(str);
	
	if (len >= 2600)
	{
		for (int i = 0; i < len; i++)
			cnt[str[i] - 'a']++;
			
		for (int i = 0; i < 26; i++)
			if (cnt[i] >= 100)
			{
				for (int j = 0; j < 100; j++)
					printf("%c", char(i + 'a'));
				
				return 0;
			}
	}
	else
	{
		for (int i = 1; i <= len; i++)
		{
			for (int j = 1; j <= len; j++)
			{
				if (str[i - 1] == str[len - j])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	
		int u = len;
		int v = len;
		
		vector < char > ans;
		
		while (u > 0 && v > 0)
		{
			if (str[u - 1] == str[len - v])
			{
				ans.pb(str[u-1]);
				u--;
				v--;
			}
			else
			{
				if (dp[u-1][v] > dp[u][v-1])
					u--;
				else
					v--;
			}
		}
		
		if (ans.size() <= 100)
		{
			for (int i = 0; i < ans.size(); i++)
				printf("%c", ans[i]);
		}
		else
		{
			for (int i = 0; i < 50; i++)
				printf("%c", ans[i]);
			for (int i = 0; i < 50; i++)
				printf("%c", ans[49 - i]);
		}
		
	}
	
	return 0;
}