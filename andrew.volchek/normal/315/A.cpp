#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define mp make_pair
#define pb push_back

int cnt[1111];
vector < int > need[1111];
vector < int > has;

int main()
{
	#if 0
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	
	int n;
	cin >> n;
	
	
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		has.pb(a);
		cnt[a]++;
		need[b].push_back(i);
	}
	
	int ans = 0;;
	
	for (int i = 0; i < n; i++)
	{
		int ind = has[i];
		bool good = 0;
		for (int j = 0; j < need[ind].size(); j++)
		{
			if (need[ind][j] != i)
				good = 1;
		}
		if (!good)
			ans++;
	}
	
	cout << ans;
	
	return 0;
}