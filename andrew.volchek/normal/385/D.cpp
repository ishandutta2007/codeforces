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
#include <complex>

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

#define cmx complex < ld >


ld dp[1 << 20];
cmx a[25], rr[25];

ld intersect(cmx &p1, cmx &p2)
{
	ld a1 = p1.imag() - p2.imag();
	ld b1 = p2.real() - p1.real();
	ld c1 = - p1.real() * a1 - p1.imag() * b1;
	
	ld a2 = 0.0;
	ld b2 = 1.0;
	ld c2 = 0.0;
	
	ld det = a1 * b2 - a2 * b1;
	
	if (det < 1e-9)
		return 1e9;
		
	ld res = ((-c1) * b2 - b1 * (-c2)) / det;
	
	return res;
}


ld rec(int mask)
{
	if (dp[mask] > -1e9)
		return dp[mask];
		
	ld res = -1e17;
	
	for (int i = 0; i < 20; i++)
	{
		if (mask & (1 << i))
		{
			ld curr = rec(mask ^ (1 << i));
			cmx p = (cmx(curr, 0) - a[i]) * rr[i] + a[i];
			
			ld t = intersect(a[i], p);
			
			if (t < curr)
				t = 1e9;
			
			res = max(t, res);
		}
	}
	
	dp[mask] = res;
	
	return res;
}

int main()
{
	//freopen("a.in", "r", stdin);
	
	int n;
	cin >> n;
	
	ld l, r;
	cin >> l >> r;
	
	for (int i = 0; i < n; i++)
	{
		ld x, y, ang;
		cin >> x >> y >> ang;
		
		ang = (ang / 180.0) * M_PI;
		
		a[i] = cmx(x, y);
		rr[i] = cmx(cos(ang), sin(ang));
	}
	
	for (int i = 0; i < (1 << n); i++)
		dp[i] = -1e17;
		
	dp[0] = l;
	
	cout.precision(7);
	cout << fixed << min(r, rec((1 << n) - 1)) - l << endl;
	
	return 0;
}