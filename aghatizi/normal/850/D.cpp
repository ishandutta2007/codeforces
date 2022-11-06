#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 65;

int d[maxn] , upd[maxn][maxn][maxn * maxn + 2];

bool is[maxn][maxn][maxn * maxn + 2] , adj[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> m;

	for(int i = 1; i <= m; i++)
		cin >> d[i];
	sort(d + 1 , d + m + 1);

	is[0][0][0] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j < maxn; j++)
			for(int k = j * (j - 1) / 2; k < maxn * maxn; k++)
			{
				if(k < d[i])
					continue;

				if(is[i][j - 1][k - d[i]])
				{
					is[i][j][k] = 1;
					upd[i][j][k] = i;
				}
				else if(is[i - 1][j - 1][k - d[i]])
				{
					is[i][j][k] = 1;
					upd[i][j][k] = i - 1;
				}
			}

	int n = 100;
	for(int i = m; i < maxn; i++)
		if(is[m][i][i * (i - 1) / 2])
		{
			n = i;
			break;
		}

	if(n > maxn)
		return cout << "=(" << endl , 0;

	vector<pair<int , int> > deg;

	int A = m , B = n , C = n * (n - 1) / 2;

	while(A > 0)
	{
		deg.pb({d[A] , (int)deg.size()});

		B--;
		C -= d[A];
		A = upd[A][B + 1][C + d[A]];
	}

	for(int _ = 0; _ < n; _++)
	{
		sort(deg.begin() , deg.end());

		int N = deg.size();
		for(int j = 0; j < N - 1; j++)
		{
			if(j < deg.back().first)
				adj[deg.back().second][deg[j].second] = 1;
			else
			{
				deg[j].first--;

				adj[deg[j].second][deg.back().second] = 1;
			}

		}

		deg.pop_back();
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j && (adj[i][j] ^ adj[j][i] ^ 1))
				cout << "SHIT" << endl;

	cout << n << endl;
	for(int i = 0; i < n; i++ , cout << endl)
		for(int j = 0; j < n; j++)
			cout << adj[i][j];

	cout << endl;
}