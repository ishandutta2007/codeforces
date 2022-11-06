#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int sq = 300;

vector<int> a[maxn];

vector<pair<int , int> > adj[maxn];

int pos[maxn];

void solve()
{
	int n , q;
	cin >> n >> q;

	for(int i = 0; i < n; i++)
		adj[i].clear();

	for(int i = 0; i < q; i++)
	{
		int k;
		cin >> k;

		a[i].clear();

		while(k--)
		{
			int x;
			cin >> x;
			x--;

			a[i].pb(x);
		}
	}

	for(int i = 0; i < q; i++)
		if((int)a[i].size() >= sq)
		{
			memset(pos , -1 , sizeof pos);
			for(int j = 0; j < (int)a[i].size(); j++)
				pos[a[i][j]] = j;

			for(int j = 0; j < q; j++)
				if(j > i || (int)a[j].size() < sq)
				{
					int mx = -1;
					for(int ind = (int)a[j].size() - 1; ind >= 0; ind--)
					{
						int k = a[j][ind];
						if(pos[k] != -1 && mx > pos[k] && a[j][ind + 1] != a[i][pos[k] + 1])
						{
							cout << "Human" << endl;
							return;
						}

						mx = max(mx , pos[k]);
					}
				}
		}

	for(int i = 0; i < q; i++)
		if((int)a[i].size() < sq)
			for(int j = 0; j < (int)a[i].size(); j++)
				for(int k = j + 1; k < (int)a[i].size(); k++)
				{
					int x = a[i][j] , y = a[i][k];
					adj[x].pb({y , a[i][j + 1]});
				}

	memset(pos , -1 , sizeof pos);
	for(int i = 0; i < n; i++)
	{
		for(auto x : adj[i])
		{
			if(pos[x.first] != -1 && pos[x.first] != x.second)
			{
				cout << "Human" << endl;
				return;
			}
			pos[x.first] = x.second;
		}

		for(auto x : adj[i])
			pos[x.first] = -1;
	}

	cout << "Robot" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}