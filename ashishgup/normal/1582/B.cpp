#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		map<int, int> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		int ans = m[1];
		for(int j = 1; j <= m[0]; j++)
			ans *= 2;
		cout << ans << endl;
	}
	return 0;
}