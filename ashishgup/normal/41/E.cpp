#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	vector<pair<int, int> > v;
	for(int i = 1; i <= n / 2; i++)
		for(int j = n / 2 + 1; j <= n; j++)
			v.push_back({i, j});
	cout << v.size() << endl;
	for(auto &it:v)
		cout << it.first << " " << it.second << endl;
	return 0;
}