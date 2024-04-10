#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k;
int a[N], ans[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		set<int> s;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s.insert(a[i]);
		}
		if(s.size() > k)
		{
			cout << -1 << endl;
			continue;
		}
		cout << k * n << endl;
		for(int i = 1; i <= n; i++)
		{
			for(auto &it:s)
				cout << it << " ";
			int cur = s.size();
			while(cur < k)
			{
				cur++;
				cout << *s.rbegin() << " ";
			}
		}
		cout << endl;
	}	
	return 0;
}