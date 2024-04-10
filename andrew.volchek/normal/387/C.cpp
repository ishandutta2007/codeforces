#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}
const int maxn = 100005;

char str[maxn];


int main()
{
	gets(str);
	int len = strlen(str);
	
	ll ans = 0;
	
	int p = len - 1;
	while (true)
	{
		int curr = 0;
		p = len - 1;
		
		while ((len - p) < p)
		{
			if (str[p] != '0')
			{
				curr = len - p;
				break;
			}
			p--;
		}
		//cerr << curr << endl;
		if (curr != 0)
		{
			ans++;
			len -= curr;
		}
		else
		{
			if (len - p == p && str[p] != '0')
			{
				bool good = true;
				for (int i = 0; i < p; i++)
				{
					if (str[i] < str[i + p])
					{
						good = false;
						break;
					}
				}
				
				if (good)
				{
					
					ans++;
					len -= p;
					continue;
				}
			}
			
			break;
		}
	}
	
	cout << ans + 1;
	
	return 0;
}