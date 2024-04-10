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

char str[2000];
int n;
int cnt[26];
int ncnt[26];

int main(int argc, char **argv)
{
	gets(str);
	cin >> n;
	
	int len = strlen(str);
	
	for (int i = 0; i < len; i++)
	{
		cnt[str[i] - 'a']++;
	}
	
	for (int ans = 1; ans < 2005; ans++)
	{

		int sum = 0;
		for (int j = 0; j < 26; j++)
		{
			int curr = cnt[j] / ans;
			if (curr * ans < cnt[j])
				curr++;
			ncnt[j] = curr;
			sum += curr;
		}
		
		if (sum <= n)
		{
			cout << ans << endl;
			for (int i = 0; i < 26; i++)
			{
				for (int j = 0; j < ncnt[i]; j++)
					cout << char('a' + i);
			}
			for (int i = 0; i < n - sum; i++)
				cout << 'a';
				
			return 0;
		}
	}
	
	cout << -1;

	return 0;
}