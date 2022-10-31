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

const int maxn = 200005;

char s[maxn], t[maxn];
int dpL[maxn], dpR[maxn];
int cnt[26][maxn];


int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	gets(s);
	gets(t);
	
	int n = strlen(s), m = strlen(t);
	
	int p = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (p < m && t[p] == s[i])
		{
			p++;
		}
		
		dpL[i] = p - 1;
	}
	
	
	p = m - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (p >= 0 && t[p] == s[i])
		{
			p--;
		}
		
		dpR[i] = p + 1;
	}
	
	cnt[t[0] - 'a'][0]++;
	
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			cnt[j][i] = cnt[j][i - 1];
		}
		cnt[t[i] - 'a'][i]++;
	}
	
	for (int i = 0; i < n; i++)
	{
		int l = dpR[i], r = dpL[i];

		if (l > r || (cnt[s[i] - 'a'][r] - (l ? cnt[s[i] - 'a'][l - 1] : 0) == 0))
		{
			puts("No");
			return 0;
		}
	}
	
	puts("Yes");
	
	return 0;
}