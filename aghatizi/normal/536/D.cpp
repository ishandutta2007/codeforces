#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int maxm = 1e5 + 20;
const ll inf = 1e15;

vector<int> adj[maxn];

int from[maxm] , to[maxm] , w[maxm] , a[maxn];

bool isx[maxn][maxn] , isy[maxn][maxn] , IS[maxn][maxn];

ll x[maxn] , y[maxn] , sumx[maxn][maxn] , sumy[maxn][maxn];
ll dp[maxn][maxn][2] , pd[maxn][maxn][2];

void dij(ll* d , int s)
{
	set<pair<ll , int> > st;

	for(int i = 0; i < maxn; i++)
		d[i] = inf;

	d[s] = 0;
	st.insert({0 , s});

	while(!st.empty())
	{
		int v = st.begin() -> second;
		ll W = st.begin() -> first;

		st.erase(st.begin());

		if(W != d[v])
			continue;

		for(auto e : adj[v])
		{
			int u = from[e] ^ to[e] ^ v;

			if(W + w[e] < d[u])
			{
				d[u] = W + w[e];
				st.insert({d[u] , u});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	int s , t;
	cin >> s >> t;
	s-- , t--;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		from[i] = a , to[i] = b;
	}

	dij(x , s);
	dij(y , t);

	vector<ll> cmpx , cmpy;

	for(int i = 0; i < n; i++)
	{
		cmpx.pb(x[i]);
		cmpy.pb(y[i]);
	}

	sort(cmpx.begin() , cmpx.end());
	sort(cmpy.begin() , cmpy.end());

	cmpx.resize(unique(cmpx.begin() , cmpx.end()) - cmpx.begin());
	cmpy.resize(unique(cmpy.begin() , cmpy.end()) - cmpy.begin());

	int A = cmpx.size() , B = cmpy.size();

	for(int i = 0; i < n; i++)
	{
		x[i] = lower_bound(cmpx.begin() , cmpx.end() , x[i]) - cmpx.begin();
		y[i] = lower_bound(cmpy.begin() , cmpy.end() , y[i]) - cmpy.begin();

		isx[x[i]][y[i]] = isy[x[i]][y[i]] = 1;
		IS[x[i]][y[i]] = 1;

		sumx[x[i]][y[i]] += a[i];
		sumy[x[i]][y[i]] += a[i];
	}

	for(int i = 0; i < A; i++)
		for(int j = B - 1; j >= 0; j--)
		{
			sumx[i][j] += sumx[i][j + 1];
			isx[i][j] |= isx[i][j + 1];
		}

	for(int j = 0; j < B; j++)
		for(int i = A - 1; i >= 0; i--)
		{
			sumy[i][j] += sumy[i + 1][j];
			isy[i][j] |= isy[i + 1][j];
		}

	for(int i = A - 1; i >= 0; i--)
		for(int j = B - 1; j >= 0; j--)
			IS[i][j] |= IS[i][j + 1] | IS[i + 1][j];

	for(int i = A - 1; i >= 0; i--)
		for(int j = B - 1; j >= 0; j--)
		{
			if(!IS[i][j])
				continue;

			if(isx[i][j])
				dp[i][j][0] = dp[i + 1][j][1] + sumx[i][j];
			else
				dp[i][j][0] = dp[i + 1][j][0];

			if(isy[i][j])
				pd[i][j][0] = pd[i][j + 1][1] - sumy[i][j];
			else
				pd[i][j][0] = pd[i][j + 1][0];

			dp[i][j][1] = max(dp[i][j][0] , pd[i][j][0]);
			pd[i][j][1] = min(pd[i][j][0] , dp[i][j][0]);
		}

	ll res = dp[0][0][0];

	if(res == 0)
		cout << "Flowers" << endl;
	else if(res < 0)
		cout << "Cry" << endl;
	else
		cout << "Break a heart" << endl;

}