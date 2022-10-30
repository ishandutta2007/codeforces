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
#define fst first
#define snd second
#define ld long double

const int maxn = 100005;

int n, m, p;
ll s[maxn];
ll c[maxn];
ll dp[maxn][2];
pair < ll, ll > hull[maxn];
int hcnt = 0;
int hprt = 0;


ld inter(ll a1, ll b1, ll a2, ll b2)
{
	return (b1 - b2) / (a2 - a1);
}

inline ll func(ll x, int i)
{
	return x * hull[i].fst + hull[i].snd;
}

bool bad(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3)
{
	return (b1 - b2) * (a3 - a1) <= (b1 - b3) * (a2 - a1); 
}

void add(ll a, ll b)
{
	hull[hcnt].fst = a;
	hull[hcnt].snd = b;
	hcnt++;
	
	
	
	while (hcnt > 2)
	{
		//if (inter(hull[hcnt-1].fst, hull[hcnt-1].snd, hull[hcnt-2].fst, hull[hcnt-2].snd) <
		//	inter(hull[hcnt-1].fst, hull[hcnt-1].snd, hull[hcnt-3].fst, hull[hcnt-3].snd))
		if (bad(hull[hcnt-1].fst, hull[hcnt-1].snd,
				hull[hcnt-2].fst, hull[hcnt-2].snd,
				hull[hcnt-3].fst, hull[hcnt-3].snd))
		{
			hull[hcnt-2] = hull[hcnt-1];
			if (hprt == hcnt-1)
				hprt--;
			hcnt--;
		}
		else
		{
			break;
		}
	}
}

ll get(ll x)
{
	/*int lo = -1;
	int hi = hcnt;
	
	while (hi - lo  > 1)
	{
		int mid = (hi + lo) / 2;
		
		if (func(x, mid) <= func(x, mid-1))
			lo = mid;
		else
			hi = mid;
	}*/
	
	while (hprt < hcnt-1 && func(x, hprt) > func(x, hprt+1)) hprt++;
	
	return func(x, hprt);;//min(func(x, lo), func(x, min(hcnt-1, hi)));
}

bool comp(const ll &a, const ll &b)
{
	return a > b;
}

int main(int argc, char **argv)
{
	scanf("%d %d %d", &n, &m, &p);
	
	s[0] = 0;
	for (int i = 0; i < n-1; i++)
	{
		int x;
		scanf("%d", &x);
		s[i+1] = s[i] + x;
	}
	
	for (int i = 0; i < m; i++)
	{
		int h, t;
		scanf("%d %d", &h, &t);
		h--;
		c[i] = (ll)t - s[h];
	}
	
	sort(c, c+m, comp);
	
	
	ll ss = 0;
	for (int i = 0; i < m; i++)
		ss += c[0] - c[i];
	
	for (int i = 0; i < m; i++)
	{
		dp[i][1] = ss;
	}
	
	
	for (int i = 2; i <= p; i++)
	{
		hcnt = 0;
		int curr = i&1;
		int prev = 1 - curr;
		hprt = 0;
		dp[0][curr] = dp[0][prev];
		for (int j = 1; j < m; j++)
		{
			add(c[j-1], dp[j-1][prev]);
			dp[j][curr] = dp[j][prev];
			
			if (i > 2)
				//for (int k = 0; k < j; k++)
					dp[j][curr] = min(dp[j][curr], get(-(m-j)) + c[j] * (m - j));///*dp[k][!(i&1)] + c[j]*(m-j) - c[k]*(m-j)*/);
			else
				dp[j][curr] = min(dp[j][curr], dp[0][1] + c[j] * (m - j) - c[0] * (m - j));
		}
	}
	
	
	ll ans = ss;
	for (int i = 0; i < m; i++)
		ans = min(ans, dp[i][p&1]);
	cout << ans;
	
	return 0;
}