#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
pair<int, int> a[N];
map<int, int> f;

void rem(int idx)
{
	int prev = -2e9;
	set<int> diff;
	for(int i = 1; i <= n; i++)
	{
		if(idx == i)
			continue;
		if(prev == -2e9)
			prev = a[i].first;
		else
		{
			int curdiff = a[i].first - prev;
			diff.insert(curdiff);
		}
		prev = a[i].first;
	}
	if(diff.size() == 1)
	{
		cout << a[idx].second << endl;
		exit(0);
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	if(n <= 3)
	{
		cout << 1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}	
	sort(a + 1, a + n + 1);
	if(n <= 100)
	{
		for(int i = 1; i <= n; i++)
			rem(i);
		cout << -1 << endl;
		exit(0);
	}
	for(int i = 2; i <= n; i++)
		f[a[i].first - a[i - 1].first]++;
	if(f.size() > 3)
	{
		cout << "-1" << endl;
		return 0;
	}
	if(f.size() == 1)
	{
		cout << a[1].second << endl;
		return 0;
	}
	int mx = 0;
	for(auto &it:f)
		mx = max(mx, it.second);
	if(mx < n - 3)
	{
		cout << "-1" << endl;
		exit(0);
	}
	int d = 0;
	for(auto &it:f)
		if(it.second == mx)
			d = it.first;
	for(int i = 2; i <= n; i++)
	{
		if(a[i].first - a[i - 1].first != d)
		{
			rem(i);
			rem(i - 1);
		}
	}
	cout << -1 << endl;
	return 0;
}