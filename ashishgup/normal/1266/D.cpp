#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
int a[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		a[u] -= d;
		a[v] += d;
	}
	set<pair<int, int> > s;
	for(int i = 1; i <= n; i++)
		s.insert({a[i], i});
	vector<int> u, v, w;
	while(s.size())
	{
		auto x = *s.begin();
		auto y = *s.rbegin();
		if(x.first == 0)
			break;
		u.push_back(x.second);
		v.push_back(y.second);
		w.push_back(min(abs(x.first), abs(y.first)));
		int wt = w.back();
		s.erase(x);
		s.erase(y);
		x.first += wt;
		y.first -= wt;
		s.insert(x);
		s.insert(y);
	}
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
		cout << u[i] << " " << v[i] << " " << w[i] << endl;
	return 0;
}