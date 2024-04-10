#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans = 0, idx = 1;
int a[N], answer[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		int cur = a[i], val = a[i];
		for(int j = i - 1; j >= 1; j--)
		{
			cur = min(cur, a[j]);
			val += cur;
		}
		cur = a[i];
		for(int j = i + 1; j <= n; j++)
		{
			cur = min(cur, a[j]);
			val += cur;
		}
		if(val > ans)
		{
			ans = val;
			idx = i;
		}
	}
	answer[idx] = a[idx];
	int cur = a[idx];
	for(int i = idx - 1; i >= 1; i--)
	{
		cur = min(cur, a[i]);
		answer[i] = cur;
	}
	cur = a[idx];
	for(int i = idx + 1; i <= n; i++)
	{
		cur = min(cur, a[i]);
		answer[i] = cur;
	}		
	for(int i = 1; i <= n; i++)
		cout << answer[i] << " ";
	return 0;
}