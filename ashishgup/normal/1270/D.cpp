#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k;

pair<int, int> get(int k, int ex)
{
	cout << "? ";
	for(int i = 1; i <= k; i++)
	{
		if(i == ex)
			continue;
		cout << i << " ";
	}
	cout << endl;
	int idx, val;
	cin >> idx >> val;
	return {idx, val};
}

#define x first
#define y second

int32_t main()
{
	IOS;
	cin >> n >> k;
	vector<pair<int, int> > v;
	pair<int, int> base = get(k, 0);
	v.push_back(base);
	for(int i = 1; i <= k; i++)
		v.push_back(get(k + 1, i));
	int idx = base.first;
	if(v[idx].y > v[0].y)
	{
		int ans = 1;
		for(int i = 1; i <= k; i++)
		{
			if(i == idx)
				continue;
			if(v[i].y > v[0].y)
				ans++;
		}
		cout << "! " << ans << endl;
	}
	else
	{
		int ans = k;
		for(int i = 1; i <= k; i++)
		{
			if(i == idx)
				continue;
			if(v[i].y < v[0].y)
				ans--;
		}
		cout << "! " << ans << endl;
	}
	return 0;
}