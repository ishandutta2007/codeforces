#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int l, r;
int ans[N];
int store1[N], store2[N];
vector<pair<int, int> > lft, rght;

int query1(int i, int j, int k)
{
	cout << 1 << " " << i << " " << j << " " << k << endl;
	int x;
	cin >> x;
	return x;
}

int query2(int i, int j, int k)
{
	cout << 2 << " " << i << " " << j << " " << k << endl;
	int x;
	cin >> x;
	return x;
}

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	for(int i = 3; i <= n; i++)
	{
		int side = query2(1, 2, i);
		int area = query1(1, 2, i);
		if(side == 1)
		{
			l++;
			lft.push_back({area, i});
		}
		else
		{
			r++;
			rght.push_back({area, i});
		}
	}
	sort(lft.rbegin(), lft.rend());
	ans[1] = 1;
	int idx = 1;
	if(lft.size())
	{
		int j = lft[0].second;
		vector<pair<int, int> > L, R;
		for(int k = 1; k < lft.size(); k++)
		{
			int side = query2(1, j, lft[k].second);
			if(side == 1)
				L.push_back({lft[k].first, lft[k].second});
			else
				R.push_back({lft[k].first, lft[k].second});
		}
		sort(L.begin(), L.end());
		sort(R.rbegin(), R.rend());
		for(auto it:L)
			ans[++idx] = it.second;
		ans[++idx] = j;
		for(auto it:R)
			ans[++idx] = it.second;
	}
	ans[++idx] = 2;
	sort(rght.rbegin(), rght.rend());
	if(rght.size())
	{
		int j = rght[0].second;
		vector<pair<int, int> > L, R;
		for(int k = 1; k < rght.size(); k++)
		{
			int side = query2(1, j, rght[k].second);
			if(side == 1)
				L.push_back({rght[k].first, rght[k].second});
			else
				R.push_back({rght[k].first, rght[k].second});
		}
		sort(L.begin(), L.end());
		sort(R.rbegin(), R.rend());
		for(auto it:L)
			ans[++idx] = it.second;
		ans[++idx] = j;
		for(auto it:R)
			ans[++idx] = it.second;
	}
	cout << 0 << " ";
	cout << ans[1] << " ";
	for(int i = n; i >= 2; i--)
		cout << ans[i] << " "; 
	return 0;
}