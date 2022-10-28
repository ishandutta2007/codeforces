#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int n;
int a[N];
 
int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int ans = 0;
		map<int, int> m;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		while(m.size())
		{
			auto x = --m.end();
			if(x -> first % 2)
				m.erase(x);
			else
			{
				int val = x -> first;
				m.erase(x);
				m[val / 2];
				ans++;
			}
		}
		cout << ans << endl;
	}	
	return 0;
}