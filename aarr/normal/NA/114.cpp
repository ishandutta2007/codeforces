#include <iostream>

#include <set>

using namespace std;

set< pair<int, int> > s;
pair<int, int> px;
pair<int, int> py;
int par[200005];
int get_par(int v)
{
	if(par[v] == v)
	{
		return v;
	}
	par[v] = get_par(par[v]);
	return par[v];
}
int main()
{
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n;
	cin >> q;
	for(int i = 1; i <= n + 1; i ++)
	{
		s.insert({i, i});
		par[i] = i;
	}
	for(int ii = 0; ii < q; ii ++)
	{
		int z, x, y;
		cin >> z;
		cin >> x;
		cin >> y;
		if(x > y)
		{
			swap(x, y);
		}
		if(z == 1)
		{
			set< pair<int, int> > :: iterator itx;
			itx = s.lower_bound({x + 1, 0});
			itx --;
			set< pair<int, int> > :: iterator ity;
			ity = s.lower_bound({y + 1, 0});
			ity --;
			x = (*itx).first;
			y = (*ity).first;
			x = get_par(x);
			y = get_par(y);
			if(x != y)
			{
				par[x] = y;
			}
		}
		if(z == 2)
		{
			set< pair<int, int> > :: iterator itx;
			itx = s.lower_bound({x + 1, 0});
			itx --;
			px = (*itx);
			x = (*itx).first;
			set< pair<int, int> > :: iterator ity;
			ity = s.lower_bound({y + 1, 0});
			ity --;
			py = (*ity);
			y = (*ity).first;
			px.second = py.second;
			s.erase(itx);
			s.insert(px);
			while(x != y)
			{
				par[get_par(y)] = get_par(x);
				s.erase(ity);
				ity = s.lower_bound({y + 1, 0});
				ity --;
				py = (*ity);
				y = (*ity).first;
			}
		}
		if(z == 3)
		{
			set< pair<int, int> > :: iterator itx;
			itx = s.lower_bound({x + 1, 0});
			itx --;
			set< pair<int, int> > :: iterator ity;
			ity = s.lower_bound({y + 1, 0});
			ity --;
			x = (*itx).first;
			y = (*ity).first;
			x = get_par(x);
			y = get_par(y);
			if(x != y)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "YES" << endl;
			}
		}
	}
	return 0;
}