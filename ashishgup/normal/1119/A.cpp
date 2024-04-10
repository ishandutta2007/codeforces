#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int j = 2; j <= n; j++)
		if(a[j] != a[1])
			ans = max(ans, j - 1);
	for(int j = 1; j <= n - 1; j++)
		if(a[j] != a[n])
			ans = max(ans, n - j);
	cout << ans;
	return 0;
}