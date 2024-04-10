#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 505;

int n, m;
int a[N][N];
map<int, int> s;
int idx[N];
vector<pair<int, int> > v[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		s.clear();
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];	
			s[a[i][j]] = j;
		}
		for(auto &it:s)
			v[i].push_back(it);
		shuffle(v[i].begin(), v[i].end(), rng);
	}
	while((double)clock() / CLOCKS_PER_SEC < 0.8)
	{
		int curxor = 0;
		for(int i = 1; i <= n - 1; i++)
		{
			idx[i] = getRand(0, v[i].size() - 1);
			curxor ^= v[i][idx[i]].first;
		}
		for(auto &it:v[n])
		{
			if((curxor ^ it.first) > 0)
			{
				cout << "TAK" << endl;
				for(int i = 1; i <= n - 1; i++)
					cout << v[i][idx[i]].second << " ";
				cout << it.second;
				exit(0);
			}
		}
	}
	cout << "NIE";
	return 0;
}