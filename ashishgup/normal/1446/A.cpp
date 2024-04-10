#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, w;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> w;
		int mn = (w + 1) / 2;
		int mx = w;
		vector<int> less, mid;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i] < mn)
				less.push_back(i);
			else if(a[i] <= mx)
				mid.push_back(i);
		}
		if(mid.size())
		{
			cout << 1 << endl;
			cout << mid[0] << endl;
		}
		else if(less.size())
		{
			int sum = 0;
			vector<int> ans;
			for(auto &it:less)
			{
				sum += a[it];
				ans.push_back(it);
				if(sum >= mn && sum <= mx)
					break;
			}
			if(sum >= mn && sum <= mx)
			{
				cout << ans.size() << endl;
				for(auto &it:ans)
					cout << it << " ";
				cout << endl;
			}
			else
				cout << -1 << endl;
		}
		else
			cout << -1 << endl;
	}
	return 0;
}