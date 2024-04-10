#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 16;

int n, sum = 0, reqd;
int a[N], s[N], ts[N];
set<int> g[N];
map<int, int> store;
bool vis[1 << N], cache[1 << N];
int c[1 << N][N], p[1 << N][N];
vector<pair<int, int> > v;

bool work(int mask)
{
	if(vis[mask])
		return cache[mask];
	if(mask == ((1 << n) - 1))
		return 1;
	vis[mask] = 1;
	for(int i = 0; i < n; i++)
	{
		if(mask >> i & 1)
			continue;
		for(auto &it:g[i])
		{
			for(int i = 0; i < n; i++)
			{
				ts[i] = s[i];
				c[mask][i] = -1;
			}
			int nmask = 0;
			int idx = i;
			ts[idx] -= it;
			int start = i;
			bool flag = 1;
			c[mask][idx] = it;
			while(true)
			{
				if((nmask >> idx & 1))
				{
					if(idx != start)
						flag = 0;
					break;
				}
				nmask |= (1 << idx);
				int take = reqd - ts[idx];
				if(store.find(take) == store.end())
				{
					flag = 0;
					break;
				}
				ts[idx] += take;
				int nidx = store[take]; 
				if(nidx == idx && take != it)
				{
					flag = 0;
					break;
				}
				p[mask][nidx] = idx;
				if(!(mask >> nidx & 1))
				{
					ts[nidx] -= take;
					if(c[mask][nidx] != -1 && c[mask][nidx] != take)
					{
						flag = 0;
						break;
					}
					c[mask][nidx] = take;
				}
				else
				{
					flag = 0;
					break;
				}
				idx = nidx;
			}
			if(flag && work(mask | nmask))
			{
				v.push_back({mask, mask | nmask});
				return cache[mask] = 1;
			}
		}
		break;
	}
	return cache[mask] = 0;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		for(int j = 1; j <= a[i]; j++)
		{
			int x;
			cin >> x;
			g[i].insert(x);
			sum += x;
			s[i] += x;
			store[x] = i;
		}
	}
	if(sum % n)
	{
		cout << "No";
		return 0;
	}
	reqd = sum / n;
	int mask = 0;
	vector<pair<int, int> > cc, pp;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == reqd)
		{
			mask |= (1 << i);
			cc.push_back({i, *g[i].begin()});
			pp.push_back({i, i});
		}
	}
	int initial = mask;
	if(work(mask))
	{
		cout << "Yes" << endl;
		reverse(v.begin(), v.end());
		int sz = v.size();
		for(int i = 0; i < sz; i++)
		{
			int mask = v[i].first;
			int nw = v[i].second;
			if(i > 0)
				nw ^= v[i - 1].second;
			else
				nw ^= initial;
			for(int j = 0; j < n; j++)
			{
				if(nw >> j & 1)
				{
					cc.push_back({j, c[mask][j]});
					pp.push_back({j, p[mask][j]});
				}
			}
		}
		sort(cc.begin(), cc.end());
		sort(pp.begin(), pp.end());
		for(int i = 0; i < n; i++)
			cout << cc[i].second << " " << pp[i].second + 1 << endl;
	}
	else
		cout << "No";
	return 0;
}