//Forgot to register

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n;
pair<int, int> a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	int ans = 0, x = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += (a[i].first * x + 1);
		x++;
	}	
	cout << ans << endl;
	for(int i = 1; i <= n; i++)
		cout << a[i].second << " ";
	return 0;
}