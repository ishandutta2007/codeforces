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

const int dirs[8][2] = 
{
	1, 0,
	0, 1,
	-1, 0,
	0, -1,
	1, 1, 
	1, -1,
	-1, 1, 
	-1, -1,
};

const int maxn = 100005;
int a[maxn];
int b[maxn];
int n;
ll dp[maxn];
pair < ll, ll > hull[maxn];
int hcnt = 0;

ld intersect(ll a1, ll b1, ll a2, ll b2)
{
	return (ld)(b2 - b1) / (a1 - a2);
}

ll func(ll x, int i)
{
	return x * hull[i].fst + hull[i].snd;
}

void add(ll a, ll b)
{
	hull[hcnt] = mp(a, b);
	hcnt++;
	
	while (hcnt > 2)
	{
		if (intersect(hull[hcnt-1].fst, hull[hcnt-1].snd, hull[hcnt-2].fst, hull[hcnt-2].snd) <
			intersect(hull[hcnt-1].fst, hull[hcnt-1].snd, hull[hcnt-3].fst, hull[hcnt-3].snd))
		{
			hull[hcnt-2] = hull[hcnt-1];
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
	int lo = 0;
	int hi = hcnt-1;
		
	while (lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		
		
		if (func(x, mid) <= func(x, mid-1))
			lo = mid;
		else
			hi = mid - 1;
		//cout << x << " " << lo << " " << hi << endl;
	}
	
	return func(x, lo);
}





int main(int argc, char **argv)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
	for (int i = 0; i < n; i++)
		scanf("%d", b+i);
		
	dp[0] = b[0];
	add(b[0], dp[0]);
	
	for (int i = 1; i < n; i++)
	{
		dp[i] = get(a[i]-1) + b[i];
		add(b[i], dp[i]);
	}
	
	cout << dp[n-1];
	return 0;
}