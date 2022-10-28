#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;

int n;
int a[N], ans[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		map<int, vector<int> > m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			for(int j = 2; j * j <= a[i]; j++)
			{
				if(a[i] % j == 0)
				{
					m[j].push_back(i);
					break;
				}
			}
		}
		int sz = m.size();
		cout << sz << endl;
		int cur = 0;
		for(auto &it:m)
		{
			++cur;
			for(auto &j:it.second)
				ans[j] = cur;
		}
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}	
	return 0;
}