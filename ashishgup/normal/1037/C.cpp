#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, ans = 0;
string a, b;
vector<pair<int, char> > v;

int32_t main()
{
	IOS;
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
	{
		ans += (a[i] != b[i]);
		if(a[i] != b[i])
			v.push_back({i, a[i]});
	}
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i].first - v[i - 1].first == 1 && v[i].second != v[i-1].second)
		{
			ans--;
			i++;
		}
	}
	cout << ans;
	return 0;
}