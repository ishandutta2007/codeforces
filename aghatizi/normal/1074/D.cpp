#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 4e5 + 20;

int sz[maxn] , par[maxn] , shit[maxn] , id;

map<int , int> mp;

int get_id(int v)
{
	if(!mp.count(v))
		mp[v] = id++;

	return mp[v];
}

pair<int , int> get(int v)
{
	int res = 0;
	while(par[v] != v)
		res ^= shit[v] , v = par[v];

	return make_pair(v , res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < maxn; i++)
		par[i] = i;

	fill(sz , sz + maxn , 1);

	int q;
	cin >> q;

	int last = 0;
	while(q--)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int l , r , x;
			cin >> l >> r >> x;
			l ^= last , r ^= last , x ^= last;

			if(l > r)
				swap(l , r);

			l--;

			l = get_id(l);
			r = get_id(r);

			auto tmpl = get(l) , tmpr = get(r);

			if(tmpl.first != tmpr.first)
			{
				if(sz[tmpl.first] > sz[tmpr.first])
					swap(tmpl , tmpr);

				sz[tmpr.first] += sz[tmpl.first];
				par[tmpl.first] = tmpr.first;
				shit[tmpl.first] = (x ^ tmpr.second ^ tmpl.second);
			}
		}
		else
		{
			int l , r;
			cin >> l >> r;
			l ^= last , r ^= last;

			if(l > r)
				swap(l , r);
			l--;

			l = get_id(l);
			r = get_id(r);

			auto tmpl = get(l) , tmpr = get(r);

			if(tmpl.first != tmpr.first)
			{
				cout << -1 << endl;
				last = 1;
			}
			else
			{
				last = tmpl.second ^ tmpr.second;
				cout << last << endl;
			}
		}
	}
}