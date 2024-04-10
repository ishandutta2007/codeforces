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
#include <ctime>
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
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

char str[1005];
char ans[1005];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, k;
	scanf("%d %d\n", &n, &k);
	gets(str);
	
	for (int i = 0; i < n; i++)
		ans[i] = str[i];
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = str[i] - 'a' + 1; j < k; j++)
		{
			if (i > 0 && str[i - 1] - 'a' == j)
				continue;
			if (i > 1 && str[i - 2] - 'a' == j)
				continue;
				
			ans[i] = j + 'a';
			bool good = true;
			
			for (int h = i + 1; h < n; h++)
			{
				int g = 0;
				while (g < k)
				{
					if (h > 0 && ans[h - 1] - 'a' == g)
					{
						g++;
						continue;
					}
					if (h > 1 && ans[h - 2] - 'a' == g)
					{
						g++;
						continue;
					}
					break;
				}
				if (g == k)
				{
					good = false;
					break;
				}
				ans[h] = g + 'a';
			}
			
			if (good)
			{
				puts(ans);
				return 0;
			}
		}
	}
	
	puts("NO");
	
	return 0;
}