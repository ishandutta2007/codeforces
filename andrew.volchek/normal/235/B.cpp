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
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100005;

ld a[maxn], b[maxn], c[maxn];
ld p[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> p[i];
		
	ld ans = 0.0;
	
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] * p[i] + p[i] * (1.0 - p[i - 1]);
		b[i] = (b[i - 1] + a[i - 1]) * p[i] + p[i] * (1.0 - p[i - 1]);
		c[i] = (c[i - 1] + 2.0 * b[i - 1] + a[i - 1]) * p[i] + p[i] * (1.0 - p[i - 1]);
		ans += c[i] * (1.0 - p[i + 1]);
	}
	
	cout.precision(7);
	cout << fixed << ans << endl;
	
	
	return 0;
}