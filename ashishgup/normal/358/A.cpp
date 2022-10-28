#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;

int n;
int x[N];
map<int, int> last;

bool intersect(int a, int b, int c, int d)
{
	vector<pair<int, int> > v;
	v.push_back({a, 1});
	v.push_back({b, 1});
	v.push_back({c, 2});
	v.push_back({d, 2});
	map<int, int> m;
	m[a]++;
	m[b]++;
	m[c]++;
	m[d]++;
	if(m.size() < 4)
		return 0;
	sort(v.begin(), v.end());
	if(v[0].second == v[2].second)
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int i = 1; i <= n - 1; i++)
	{
		for(int j = 1; j <= n - 1; j++)
		{
			if(i == j)
				continue;
			if(intersect(x[i], x[i + 1], x[j], x[j + 1]))
			{
				cout << "yes";
				return 0;
			} 
		}
	}
	cout << "no";
	return 0;
}