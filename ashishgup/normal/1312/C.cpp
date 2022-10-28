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
	while(t--)
	{
		cin >> n >> k;
		map<int, int> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			int x = a[i];
			int cur = 0;
			while(x > 0)
			{
				m[cur] += x % k;
				x /= k;
				cur++;
			}
		}
		int flag = 1;
		for(auto &it:m)
			if(it.second > 1)
				flag = 0;
		if(!flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}