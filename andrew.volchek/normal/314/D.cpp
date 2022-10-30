#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define ll long long

const int maxn = 111111;
pair < ll , ll > p[maxn];
int n;
ll maxl[maxn], maxr[maxn], minl[maxn], minr[maxn];
const ll inf = 2000000000;

int main()
{
	#if 0
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		p[i].fst = y - x;
		p[i].snd = y + x;
	}
	
	sort(p, p + n);
	
	maxl[0] = -inf;
	minl[0] = inf;
	
	for (int i = 1; i <= n; i++)
	{
		maxl[i] = max(maxl[i-1], p[i-1].snd);
		minl[i] = min(minl[i-1], p[i-1].snd);
	}
	
	maxr[n] = -inf;
	minr[n] = inf;
	
	for (int i = n-1; i >= 0; i--)
	{
		maxr[i] = max(maxr[i+1], p[i].snd);
		minr[i] = min(minr[i+1], p[i].snd);
	}
	
	ll l = 0;
	ll r = 2LL*inf;
	
	while (l <= r)
	{
		ll d = (l + r) / 2 + 1;
		if (l == r)
			d--;
		//cout << l << " " << r << " " << d << endl;
		
		int j = 1; 
		
		bool good = false;
		
		for (int i = 0; i < n; i++)
		{
			while (j < n && p[j].fst - p[i].fst <= d) j++;
			
			if (p[max(i, j-1)].fst - p[i].fst <= d)
			{
				if (i == 0 && j == n)
				{
					good = true;
					break;
				}
				else
				{
					ll ma = max(maxl[i], maxr[j]);
					ll mi = min(minl[i], minr[j]);
					
					if (ma - mi <= d)
					{
						good = true;
						break;
					}
				}
				
			}
		}
		
		if (l == r)
		{
			//cout << "aaa " << good << endl;
			if (!good)
				l++;
			break;
		}
		
		if (!good)
		{
			l = d;
		}
		else
		{
			r = d-1;
		}
		
	}
	cout.precision(7);
	cout << fixed << double(l) / 2;
	
	
	return 0;
}