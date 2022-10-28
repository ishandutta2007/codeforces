#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 8005;

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
		multiset<int> s;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s.insert(a[i]);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			int cur = a[i];
			for(int j = i + 1; j <= n; j++)
			{
				cur += a[j];
				while(s.find(cur) != s.end())
				{
					ans++;
					s.erase(s.find(cur));
				}
			}
		}
		cout << ans << endl;
	}	
	return 0;
}