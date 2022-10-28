#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
pair<int, int> a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		int flag = 0;
		for(int i = 1; i <= n; i++)
		{
			int j = i;
			vector<int> v = {i};
			while(j + 1 <= n && a[j + 1].first == a[i].first)
			{
				j++;
				v.push_back(j);
			}
			if(j - i + 1 == 1)
			{
				flag = 1;
				cout << -1 << endl;
				break;
			}
			int idx = 0;
			for(int k = i; k <= j; k++)
			{
				idx = (idx + 1) % v.size();
				a[k].second = v[idx];
			}
			i = j;
		}
		if(flag)
			continue;
		for(int i = 1; i <= n; i++)
			cout << a[i].second << " ";
		cout << endl;
	}
	return 0;
}