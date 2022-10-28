#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long

const int N = 1e5 + 5;

int n, cur = 0, ans = 0;
char on[N];
int a[N], b[N], val[N];

int32_t main()
{
	IOS;	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> on[i];
		cur += (on[i] - '0');
	}
	ans = cur;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		int cur = (on[i] == '0');
		if(!cur)
			cur = -1;
		for(int j = b[i]; j <= 1e5; j += a[i])
		{
			val[j] += cur;
			cur *= -1;
		}
	}
	for(int i = 1; i <= 1e5; i++)
	{
		cur += val[i];
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}