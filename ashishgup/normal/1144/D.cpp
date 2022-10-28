#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, l, rr, mx = -1;
int a[N];
vector<int> p, q, r;
map<int, vector<pair<int, int> > > m;
map<int, int> sum;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1, j = 1; i <= n; i = j)
	{
		for(; j <= n && a[i] == a[j]; j++);
		int cur = j - i;
		sum[a[i]] += cur;
		m[a[i]].push_back({i, j-1});
	}
	int mx = -1, best = -1;
	for(auto &it:sum)
	{
		if(it.second > mx)
		{
			mx = it.second;
			best = it.first;
		}
	}
	int l = m[best].back().first;
	int rr = m[best].back().second;
	for(int i = rr; i <= n - 1; i++)
	{
		int diff = abs(a[i] - a[i + 1]);
		if(diff == 0)
			continue;
		if(a[i + 1] < a[i])
		{
			p.push_back(1);
			q.push_back(i + 1);
			r.push_back(i);
		}
		else
		{
			p.push_back(2);
			q.push_back(i + 1);
			r.push_back(i);
		}
		a[i + 1] = a[i];
	}
	for(int i = l; i >= 2; i--)
	{
		int diff = abs(a[i] - a[i - 1]);
		if(diff == 0)
			continue;
		if(a[i - 1] < a[i])
		{
			p.push_back(1);
			q.push_back(i - 1);
			r.push_back(i);
		}
		else
		{
			p.push_back(2);
			q.push_back(i - 1);
			r.push_back(i);
		}
		a[i - 1] = a[i];
	}
	cout << p.size() << endl;
	for(int i = 0; i < p.size(); i++)
		cout << p[i] << " " << q[i] << " " << r[i] << endl;
	return 0;
}