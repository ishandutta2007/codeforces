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

const int maxn = 200005;

int a[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
		
		
	ll ans1 = 0;
	
	ll cnt = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
			cnt++;
		else
			ans1 += cnt;
	}
	
	
	ll ans2 = 0;
	
	cnt = 0;
	
	for (int i = n-1; i >= 0; i--)
	{
		if (a[i] == 0)
			cnt++;
		else
			ans2 += cnt;
	}
	
	
	cout << min(ans1, ans2);
	
	
	return 0;
}