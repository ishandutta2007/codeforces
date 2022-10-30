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

int a[222222];
vector < int > ans;
int n, k, curr_n;

int main()
{
	#if 0
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a+i+1);
	}
	
	curr_n = n;
	int curr_cnt = 1;
	
	long long add = 0;
	long long kk = k;
	for (int i = 2; i <= n; i++)
	{
		long long curr = add - ((long long)a[i]) * (long long)(curr_n - (curr_cnt+1)) * curr_cnt;
		if (curr < kk)
		{
			ans.pb(i);
			curr_n--;
		}
		else
		{
			add += ((long long)a[i]) * curr_cnt;
			curr_cnt++;
		}
	}
	
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d\n", ans[i]);
	}
	
	
	return 0;
}