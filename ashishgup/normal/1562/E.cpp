// Took 20-25 minutes break

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 5001;

int n;
string s;
int cache[N][N]; //First mismatch len

int dp(int i, int j)
{
	if(s[i] != s[j])
		return 0;
	if(i == n || j == n)
		return 0;
	int &ans = cache[i][j];
	if(ans != -1)
		return ans;
	ans = 1 + dp(i + 1, j + 1);
	return ans;
}

int compare(int i, int j, int l1, int l2) // -1 if i is smaller, 0 if same, 1 if greater
{
	int len = dp(i, j);
	if(i + len > l1 && j + len > l2)
	{
		if(l1 < l2)
			return -1;
		if(l1 > l2)
			return 1;
		return 0;
	}
	if(i + len > l1)
		return -1;
	if(j + len > l2)
		return 1;
	if(s[i + len] < s[j + len])
		return -1;
	return 1;
}

int cache2[N];

int dpLen(int i)
{
	if(i == n)
		return 0;
	int &ans = cache2[i];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int j = i + 1; j < n; j++)
	{
		if(compare(i, j, n - 1, n-1) == -1)
		{
			int lo = j, hi = n - 1;
			while(lo < hi)
			{
				int mid = (lo + hi) / 2;
				if(compare(i, j, n - 1, mid) == -1)
					hi = mid;
				else
					lo = mid + 1;
			}
			ans = max(ans, (n - 1) - lo + 1 + dpLen(j));
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> s;
		for(int i = 0; i < n; i++)
		{
			cache2[i] = -1;
			for(int j = 0; j < n; j++)
				cache[i][j] = -1;
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(n - i + dpLen(i), ans);
		cout << ans << endl;
	}
	return 0;
}