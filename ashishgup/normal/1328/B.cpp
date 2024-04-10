#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	for(int i = 1; i <= 1e5; i++)
		a[i] = a[i - 1] + i;
	while(t--)
	{
		cin >> n >> k;
		auto it = lower_bound(a + 1, a + n + 1, k) - a;
		string ans(n, 'a');
		ans[n - 1 - it] = 'b';
		k -= a[it - 1];
		k--;
		ans[n - 1 - k] = 'b';
		cout << ans << endl;
	}
	return 0;
}