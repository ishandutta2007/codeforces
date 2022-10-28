#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int s, n;
int ans = 0;
vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	cin >> s >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	for(auto &it:v)
	{
		if(s > it.first)
			s += it.second;
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}