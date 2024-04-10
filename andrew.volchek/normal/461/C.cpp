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

const int maxn = 100005;
ll t[maxn];
void inc(int i, ll x)
{
	while (i < maxn)
	{
		t[i] += x;
		i = i | (i + 1);
	}
}

ll sum(ll r)
{
	ll res = 0;
	while (r >= 0)
	{
		res += t[r];
		r = (r & (r + 1)) - 1;
	}
	return res;
}


int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, q;
	scanf("%d %d", &n, &q);
	int l = 0, r = n - 1;
	bool inv = false;
	for (int i = 0; i < n; i++)
		inc(i, 1);
	for (int i = 0; i < q; i++)
	{
		int type;
		scanf("%d", &type);
		
		if (type == 1)
		{
			int x;
			scanf("%d", &x);
			
			if (!inv)
			{
				if (r - l + 1 - x >= x)
				{
					for (int j = 0; j < x; j++)
					{
						ll y = sum(j + l) - sum(j + l - 1);
						inc(l + x + x - 1 - j, y);
					}
					l += x;
				}
				else
				{
					x = r - l + 1 - x;
					for (int j = 0; j < x; j++)
					{
						ll y = sum(r - j) - sum(r - j - 1);
						inc(r - x - x + 1 + j, y);
					}
					r -= x;
					inv = true;
				}
			}
			else
			{
				if (r - l + 1 - x >= x)
				{
					for (int j = 0; j < x; j++)
					{
						ll y = sum(r - j) - sum(r - j - 1);
						inc(r - x - x + 1 + j, y);
					}
					r -= x;
				}
				else
				{
					x = r - l + 1 - x;
					for (int j = 0; j < x; j++)
					{
						ll y = sum(l + j) - sum(l + j - 1);
						inc(l + x + x - 1 - j, y);
					}
					inv = false;
					l += x;
				}
			}
		}
		else
		{
			int u, v;
			scanf("%d %d", &v, &u);
			if (!inv)
			{
				cout << sum(l + u - 1) - sum(l + v - 1) << endl;
			}
			else
			{
				cout << sum(r - v) - sum(r - u) << endl;
			}
		}
	}
	//cerr << l << " " << r << endl;
	
	return 0;
}