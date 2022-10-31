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
	return x > 0 ? x : -x;
}

int a[100005];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int q, w;
		cin >> q >> w;
		a[i] = w;
	}
	sort(a, a+m);
	reverse(a, a+m);
	ll cnt = 0;
	if (n == 1)
		cnt = 1;
	else 
	{
		cnt = 1;
		
		while (true)
		{
			if (cnt & 1)
			{
				if (cnt * (cnt - 1) / 2 > n - 1)
					break;
			}
			else
			{
				if (cnt * (cnt - 1) / 2 + cnt / 2 - 1 > n - 1)
					break;
			}
			cnt++;
		}
		
		cnt--;
	}
	
	ll ans = 0;
	for (int i = 0; i < min((int)cnt, m); i++)
		ans += a[i];
		
	cout << ans;
	
	
	return 0;
}