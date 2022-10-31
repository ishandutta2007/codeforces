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

int aa[maxn], bb[maxn];

ll solve(int *a, int *b, int n, int m)
{
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
		
	ll sum2 = 0;
	for (int i = 0; i < m; i++)
		sum2 += b[i];
		
	bool any = false;
	ll mm = 0;
	
	ll ans = 0;
	
	for (int i = 0; i < m; i++)
	{
		if ((ll)b[i] >= sum)
		{
			sum2 -= b[i];
			any = true;
			ans += sum;
		}
		
		mm = max(mm, (ll)b[i]);
	}
	
	if (!any)
	{
		sum2 -= mm;
		ans += sum;
	}
	//cerr << ans + sum2 << endl;
	return ans + sum2;
}

int main(int argc, char *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector < int > cc;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", aa + i);
	}
		
	for (int i = 0; i < m; i++)
	{
		scanf("%d", bb + i);
	}
	
	cout << min(solve(aa, bb, n, m), solve(bb, aa, m, n)) << endl;
	
	return 0;
}