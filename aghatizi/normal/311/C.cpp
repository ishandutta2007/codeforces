#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

ll a[maxn] , d[maxn];
int c[maxn];

set<pair<int , int> > ans;

bool is[maxn];

void reval(int ind , int x)
{
	ans.erase({c[ind] , -ind});
	c[ind] -= x;
	if(is[ind])
		ans.insert({c[ind] , -ind});
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ans.insert({0 , 1});

	ll h;
	int n , m , k;
	cin >> h >> n >> m >> k;

	memset(d , 63 , sizeof d);
	d[0] = 0;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
		a[i]--;

		if(a[i] % k == 0)
			ans.insert({c[i] , -i}) , is[i] = 1;
	}

	while(m--)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			ll x;
			cin >> x;

			set<pair<ll , int> > st;
			for(int i = 0; i < k; i++)
				st.insert({d[i] , i});

			while(!st.empty())
			{
				int v = st.begin() -> second;
				ll W = st.begin() -> first;
				st.erase(st.begin());

				if(W != d[v])
					continue;

				int u = (v + x) % k;
				if(d[u] > d[v] + x)
				{
					d[u] = d[v] + x;
					st.insert({d[u] , u});
				}
			}

			for(int i = 0; i < n; i++)
				if(!is[i] && d[a[i] % k] <= a[i])
				{
					is[i] = 1;
					ans.insert({c[i] , -i});
				}
		}
		if(type == 2)
		{
			int ind , x;
			cin >> ind >> x;
			ind--;
			reval(ind , x);

		}
		if(type == 3)
		{
			auto tmp = *ans.rbegin();
			cout << tmp.first << endl;
			if(tmp.first)
				reval(-tmp.second , 2e9);
		}
	}
}