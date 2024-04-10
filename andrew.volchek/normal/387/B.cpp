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
const int maxn = 3005;
int a[maxn], b[maxn];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
		
	for (int i = 0; i < m; i++)
		scanf("%d", b + i);
		
	int i = 0, j = 0;
	
	while (j < m && i < n)
	{
		if (a[i] <= b[j])
		{
			i++;
			j++;
		}
		else
			j++;
	}
	
	cout << n - i << endl;
	
	return 0;
}