#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

int n;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int prev = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] <= prev)
		{
			ans += (prev + 1 - a[i]);
			prev = prev + 1;
		}	
		else
			prev = a[i];
	}
	cout << ans;
	return 0;
}