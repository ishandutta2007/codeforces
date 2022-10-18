#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 500, logn = 61;

bitset<maxn> ok[logn][2][maxn]; // level, type, vertex
const int inf = 1e18;

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int v[m], u[m], t[m];
	for(int i = 0; i < m; i++)
	{
		cin >> v[i] >> u[i] >> t[i];
		v[i]--, u[i]--;
		ok[0][t[i]][v[i]][u[i]] = 1;
	}
	for(int z = 1; z < logn; z++)
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int t = 0; t < 2; t++)
					if(ok[z - 1][t][i][k])
						ok[z][t][i] |= ok[z - 1][!t][k];
	int ans = 0;
	vector<int> start = {0};
	bool mode = 0;
	for(int i = logn - 1; i >= 0; i--)
	{
		vector<int> nstart;
		for(auto u: start)
			for(int v = 0; v < n; v++)
				if(ok[i][mode][u][v])
					nstart.push_back(v);
		if(!nstart.empty())
		{
			sort(begin(nstart), end(nstart));
			nstart.erase(unique(begin(nstart), end(nstart)), end(nstart));
			ans += 1LL << i;
			mode = !mode;
			start = nstart;
		}
	}
	if(ans > inf)
		cout << -1 << endl;
	else
		cout << ans << endl;
		
		
}