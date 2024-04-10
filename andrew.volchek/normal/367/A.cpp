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
#define ull long long
#define fst first
#define snd second
#define ld long double

template < typename T > T abs(T x)
{
	return x > 0 	? x : -x;
}

char str[100005];
int cnt[3][100005];

int main()
{
	//freopen("a.in", "r", stdin);
	
	gets(str);
	int len = strlen(str);
	
	cnt[0][0] = cnt[1][0] = cnt[2][0] = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 3; j++)
			cnt[j][i+1] = cnt[j][i] + (str[i] == ('x'+j));
	}
	
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		
		bool good = false;
		
		if (r - l + 1 < 3)
		{
			puts("YES");
			continue;
		}
		
		for (int j = 0; j < 3; j++)
		{
			int curr = (r - l + 1) / 3;
			if ((r - l + 1) % 3)
				curr++;
				
				
			int curr2 = (r - l + 1) / 3;
			if ((r - l + 1) % 3 > 1)
				curr2++;
			
			int curr3 = (r - l + 1) / 3;
			
			if ((cnt[j][r] - cnt[j][l-1] == curr) && (cnt[(j+3-1)%3][r] - cnt[(j+3-1)%3][l-1] == curr2)
				&& (cnt[(j+3-2)%3][r] - cnt[(j+3-2)%3][l-1] == curr3))
				{
					good = true;
					break;
				}
		}
		
		if (good)
			puts("YES");
		else
			puts("NO");
	}
	
	
	return 0;
}