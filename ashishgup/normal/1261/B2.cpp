#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

ordered_set os1;

int n, m;
int a[N], ans[N];
vector<pair<int, int> > v;
vector<pair<int, int> > quer[N];
map<int, int> cnt;

void work()
{
	for(int i = 0; i < n; i++)
	{
		os1.insert(v[i].second);
		for(auto &it:quer[i + 1])
		{
			int x = it.first;
			int idx = it.second;
			ans[idx] = a[*os1.find_by_order(x - 1)];
		}
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v.push_back({-a[i], i});
	}
	sort(v.begin(), v.end());
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		int k, pos;
		cin >> k >> pos;
		quer[k].push_back({pos, i});
	}
	work();
	for(int i = 1; i <= m; i++)
		cout << ans[i] << endl;
	return 0;
}