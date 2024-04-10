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

const int maxn = 100005;

int a[maxn];
vector < int > p[maxn];
ll s[maxn];

int main(int argc, char *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", a + i);
		p[a[i]].pb(i);
	}
	
	if (m == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	a[0] = a[2];
	a[m + 1] = a[m - 1];
	
	
	ll ans = 0;
	
	for (int i = 1; i < m; i++)
	{
		ans += abs(a[i] - a[i + 1]);
	}
	

		
	ll ans2 = ans;
	
	
	for (int i = 1; i <= n; i++)
	{
		if (p[i].empty())
			continue;
		
		vector < int > v;
		
		ll sum = 0;
		
		for (int j = 0; j < p[i].size(); j++)
		{
			if (p[i][j] > 1 && a[p[i][j] - 1] != i)
			{
				v.pb(a[p[i][j] - 1]);
				sum += abs(a[p[i][j] - 1] - i);
			}
			if (p[i][j] < m && a[p[i][j] + 1] != i)
			{
				v.pb(a[p[i][j] + 1]);
				sum += abs(a[p[i][j] + 1] - i);
			}
		}
		
		sort(v.begin(), v.end());
		
		ll leftSum = 0, rightSum = 0;
		
		for (int j = 0; j < v.size(); j++)
			rightSum += v[j];
			
		for (int j = 0; j < v.size(); j++)
		{
			rightSum -= v[j];
			
			ll curr = ((ll)v[j]) * j - leftSum + rightSum - ((ll)v[j]) * ((int)v.size() - j - 1);
			ans2 = min(ans2, ans - sum + curr);
			
			leftSum += v[j];
		}
	}
	
	cout << ans2 << endl;
	
	return 0;
}