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
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

char str[2005];
int n;

int main(int argc, char **argv)
{
	scanf("%d\n", &n);
	gets(str);
	int len = strlen(str);
	int ans = 0;
	for (int i = 1; i <= len; i++)
	{
		if (i >= 4 && ((i-1) % n) == 0)
		{
			if ((str[i-2] == str[i-3]) && (str[i-3] == str[i-4]))
				ans++;
		}
	}
	cout << ans;
	return 0;
}