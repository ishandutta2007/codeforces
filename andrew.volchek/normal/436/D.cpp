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
//#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}


int a[300005], b[2005];
int dp[300005];

int ll[300005], rr[300005];



int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	
	for (int j = 0; j < m; j++)
	{
		scanf("%d", b + j);
	}
	
	sort(a, a + n);
	sort(b, b + m);
	
	for (int i = 0; i < n; i++)
	{
		ll[i] = i;
		
		if (i && a[i] - 1 == a[i - 1])
			ll[i] = ll[i - 1];
	}
	
	for (int j = n - 1; j >= 0; j--)
	{
		rr[j] = j;
		if (j < n - 1 && a[j] + 1 == a[j + 1])
			rr[j] = rr[j + 1];
	}
	
	int bp = 0;
	
	for (int i = 0; i < n; i++)
	{
		while (bp < m && b[bp] < a[i]) bp++;
		
		int left = 0;
		
		if (bp < m && b[bp] == a[i])
			left++;
			
		int curr = 0;
		
		if (ll[i] - 1 >= 0)
			curr = dp[ll[i] - 1];
		
		for (int j = bp - 1; j >= 0; j--)
		{
			int diff = a[i] - b[j];
		//	cerr << i << " " << diff << endl;
			
			if (diff > i)
				break;
				
			int v = bp - j;
			
			int g = ll[i - diff];
			
			if (g - 1 >= 0)
				v += dp[g - 1];
				
			curr = max(curr, v);
		}
		
		left += curr;
		
		//cerr << i << " " << left << endl;
		
		
	//	cerr << i << " " << dp[i] << endl;
		dp[rr[i]] = max(dp[rr[i]], left);
		
		int j = bp;
		if (b[j] == a[i])
			j++;
		
		int cnt = 1;
		for (; j < m; j++)
		{
			int diff = b[j] - a[i];
			//cerr << i << " " << diff << endl;
			
			if (n - i - 1 < diff)
				break;
				
			int v = cnt;
			
			int g = rr[i + diff];
			
			if (g < n)
				dp[g] = max(dp[g], left + v);
			
			cnt++;
		}
	}
	
	int ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		//cerr << dp[i] << endl;
		ans = max(ans, dp[i]);
	}
		
	cout << ans << endl;
	
	return 0;
}