#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e5 + 5;

int n, m, k, val = 0, ans = 0, parity = 0, num;
int l[N], r[N];
int a[3 * N];
bool active[3 * N];
map<int, int> comp;
vector<int> st[3 * N], ed[3 * N];
map<int, int> cache[3 * N];
vector<int> alive[3 * N];

int rec(int idx)
{	
	int curM = 0, csz = alive[idx].size();
	for(int i = 0; i < csz; i++)
	{
		if(active[alive[idx][i]])
			curM |= (1 << i);
	}
 	if(cache[idx].count(curM))
		return cache[idx][curM];
	int &value = cache[idx][curM];
	vector<int> store;
	for(auto &it:ed[idx])
	{
		if(active[it])
			store.push_back(it);
		parity -= active[it];
		active[it] = 0;
	}
	if(idx == num)
	{
		ans = max(ans, val);
		for(auto &it:store)
		{
			parity++;
			active[it] = 1;
		}
		return value = 0;
	}
	int sz = st[idx].size();
	for(int mask = 0; mask < (1 << sz); mask++)
	{
		for(int j = 0; j < sz; j++)
		{
			if(mask >> j & 1)
			{
				active[st[idx][j]] = 1;
				parity++;
			}
		}
		if(parity % 2)
			value = max(value, a[idx + 1] - a[idx] + rec(idx + 1));
		else
			value = max(value, rec(idx + 1));
		for(int j = 0; j < sz; j++)
		{
			if(mask >> j & 1)
			{
				active[st[idx][j]] = 0;
				parity--;
			}
		}
	}
	for(auto &it:store)
	{
		parity++;
		active[it] = 1;
	}
	return value;
}

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		comp[l[i]];
		comp[r[i]];
		comp[r[i] + 1];
	}	
	for(auto &it:comp)
	{
		it.second = ++num;
		a[num] = it.first;
	}
	for(int i = 1; i <= n; i++)
	{
		st[comp[l[i]]].push_back(i);
		ed[comp[r[i] + 1]].push_back(i);
	}
	set<int> active;
	for(int i = 1; i <= num; i++)
	{
		for(auto &it:ed[i])
			active.erase(it);
		for(auto &it:st[i])
			active.insert(it);
		for(auto &it:active)
			alive[i].push_back(it);
	}
	int ans = rec(1);
	cout << ans;
	return 0;
}