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

ll n;

void mul(ll a[6][6], ll b[6][6])
{
	ll res[6][6];
	
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			res[i][j] = 0;
			
			for (int k = 0; k < 6; k++)
			{
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % n;
			}
		}
	}
	
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			a[i][j] = res[i][j];
}

ll t[6][6] = 
{
	1, 0, 1, 0, 0, 0,
	0, 1, 0, 1, 0, 0,
	1, 1, 2, 1, 1, 2,
	1, 1, 1, 2, 1, 2,
	0, 0, 0, 0, 1, 1,
	0, 0, 0, 0, 0, 1,
};

ll s[6] = {0, 0, 0, 0, 1, 1, };

void binpow(ll x[6][6], ll res[6][6], ll m)
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			res[i][j] = (i == j) ? 1 : 0;

	while (m)
	{
		if (m & 1)
			mul(res, x);
			
		mul(x, x);
		m >>= 1;
	}
}

int main()
{
	//freopen("a.in", "r", stdin);
	cin >> n;
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	ll m;
	cin >> m;
	
	s[2] += s[0] + s[1] + n;
	s[3] += s[0] + s[1] + n;
	s[2] %= n;
	s[3] %= n;
	
	s[0]--;
	s[1]--;
	
	ll res[6][6];

	binpow(t, res, m);
	
	ll ansX = 0, ansY = 0;
	
	for (int i = 0; i < 6; i++)
	{
		ansX = (ansX + res[0][i] * s[i]) % n;
		ansY = (ansY + res[1][i] * s[i]) % n;
	}
	
	cout << ansX + 1 << " " << ansY + 1 << endl;
	
	return 0;
}