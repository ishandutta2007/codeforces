#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;

int n, ans = 0;
int a[N], freq[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		freq[a[i]]++;
	}
	int ans = 0, mx = 0;
	for(int i = 1; i <= 1000; i++)
	{
		ans += min(mx, freq[i]);
		mx = max(mx, freq[i]);
	}
	cout << ans;
	return 0;
}