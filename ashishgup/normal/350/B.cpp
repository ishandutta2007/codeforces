#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int type[N], a[N], deg[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> type[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		deg[a[i]]++;
	}
	vector<int> best;
	for(int i = 1; i <= n; i++)
	{
		if(type[i] == 1)
		{
			vector<int> v;
			int cur = i;
			v.push_back(cur);
			cur = a[cur];
			while(cur > 0 && deg[cur] == 1)
			{
				v.push_back(cur);
				cur = a[cur];
			}
			if(v.size() > best.size())
				best = v;
		}
	}
	reverse(best.begin(), best.end());
	cout << best.size() << endl;
	for(auto &it:best)
		cout << it << " ";
	return 0;
}