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


pair < ll, ll > dp[63][1005];

int main()
{
	//freopen("a.in", "r", stdin);
	ll a, b, w, x, c;
	
	cin >> a >> b >> w >> x >> c;
	
	
	for (int i = 0; i < w; i++)
	{
		ll curr = i;
		ll cnt = 0;
		
		while (curr >= x)
		{
			curr -= x;
			cnt++;
		}
		
		ll to = w - (x - curr);
		//cnt++;
		
		dp[0][i] = mp(cnt, to);
	}
	
	for (int i = 1; i < 63; i++)
	{
		for (int j = 0; j < w; j++)
		{
			ll cnt = dp[i-1][j].fst + dp[i-1][dp[i-1][j].snd].fst;
			ll to = dp[i-1][dp[i-1][j].snd].snd;
			
			dp[i][j] = mp(cnt, to);
		}
	}
	
	
	if (c <= a)
	{
		cout << 0;
		return 0;
	}
	
	//cerr << dp[0][2].fst << " "  << dp[0][2].snd << endl;
	
	//return 0;
	
	ll ans = 0;
	ll need = c - a;
	
	while (need)
	{
		int p = 0;
		while (dp[p][b].fst < need) p++;
		
		//cerr << p << endl;
		
		
		
		
		if (p == 0)
		{
			
		
			while (c > a && need)
			{
				if (b >= x)
				{
					b -= x;
					ans++;
					need--;
				}
				else
				{
					b = w - (x - b);
					ans++;
					
				}
			}
		}
		else
		{
			p--;
			ans += dp[p][b].fst + (1LL << p);
			
		
			need -= dp[p][b].fst;;
			b = dp[p][b].snd;
		}
		
		
		
	}
	
	cout << ans;
	
	
	
	return 0;
}