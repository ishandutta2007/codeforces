
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

int a[200];

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	sort(a, a + n);
	
	vector < int > ans;
	
	for (int i = 0; i < n; i++)
	{
		if (ans.empty())
		{
			ans.pb(1);
		}
		else if (ans[0] <= a[i])
		{
			ans[0]++;
			sort(ans.begin(), ans.end());
		}
		else
		{
			ans.pb(1);
			sort(ans.begin(), ans.end());
		}
	}
	
	cout << ans.size();
	return 0;
}