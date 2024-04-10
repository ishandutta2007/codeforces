#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N], store[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		map<int, int> comp;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			comp[a[i]];
			store[i] = 0;
		}
		int ctr = 0;
		for(auto &it:comp)
			it.second = ++ctr;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			a[i] = comp[a[i]];
			store[a[i]] = store[a[i] - 1] + 1;
			ans = max(ans, store[a[i]]);
		}
		cout << n - ans << endl;
	}
	return 0;
}