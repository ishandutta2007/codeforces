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


const int maxn = 100005;
ll a[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	sort(a, a + n);
	
	
	
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	
	if (n == 2)
	{
		
		vector < ll > ans;
		
		ans.pb(a[0] - (a[1] - a[0]));
		if (((a[1] - a[0]) & 1) == 0)
		{
			ans.pb((a[1] + a[0]) / 2);
		}
		ans.pb(a[1] + a[1] - a[0]);
		
		sort(ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			if (i)
				cout << " ";
			cout << ans[i];
		}
		return 0;
	}
	
	vector < ll > ans;
	
	bool good = true;
	ll need = a[1] - a[0];
	
	for (int i = 2; i < n; i++)
		need = min(need, a[i] - a[i-1]);
		
	
	for (int i = 1; i < n; i++)
	{
		good &= (a[i] - a[i-1]) == need;
	}
	
	if (good == true)
	{
		ans.pb(a[n-1] + need);
		ans.pb(a[0] - need);
	}
	else
	{
		bool bad = false;
		for (int i = 1; i < n; i++)
		{
			if (a[i] - a[i-1] != need)
			{
				if (((a[i] - a[i-1]) & 1) == 0)
				{
					if (need == (a[i] - a[i-1]) / 2)
					{
						ans.pb(a[i-1] + need);
					}
					else
					{
						bad = true;
					}
				}
				else
				{
					bad = true;
				}
			}
		}
		
		if (ans.size() > 1 || bad)
		{
			ans.clear();
		}
	}
	
	
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			cout << " ";
		cout << ans[i];
	}
	return 0;
}