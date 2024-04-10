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


ld a[105];

int main(int argc, char *argv[])
{
//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] = min(a[i], (ld)1.0 - 1e-12);
	}
	sort(a, a + n);
	
	ld ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for(int j = n; j >= i; j--)
		{
			vector < ld > v;
			for (int h = 0; h < i; h++)
				v.pb(a[h]);
			for (int h = j; h < n; h++)
				v.pb(a[h]);
			ld s = 1.0;
			for (int h = 0; h < v.size(); h++)
				s *= 1.0 - v[h];
			ld curr = 0.0;
			
			for (int h = 0; h < v.size(); h++)
				curr += s / (1.0 - v[h]) * v[h];
				
			ans = max(curr, ans);
		}
	}
	
	cout.precision(10);
	cout << fixed << ans;
	return 0;
}