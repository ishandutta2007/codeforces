#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	cin >> k;
	int l = 1;
	for(int r = 1; r <= n; r++)
	{
		while(a[r] - a[l] > k)
			l++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}