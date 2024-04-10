#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 500 + 5;

int g[maxn][maxn];
int r[maxn], c[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> g[i][j];
	vector<pair<int,int>> opt;
	for (int i = 0; i <= g[1][1]; i++){
		r[1] = i;
		for (int j = 1; j <= m; j++)
			c[j] = g[1][j] - r[1];
		for (int j = 1; j <= n; j++)
			r[j] = g[j][1] - c[1];
		bool found = true;
		for (int j = 1; j <= m; j++)
			if (c[j] < 0)
				found = false;
		for (int j = 1; j <= n; j++)
			if (r[j] < 0)
				found = false;
		for (int j = 1; found and j <= n; j++)
			for (int k = 1; found and k <= m; k++)
				if (g[j][k] != r[j] + c[k])
					found = false;
		if (found){
			int sum = 0;
			for (int i = 1; i <= n; i++)
				sum += r[i];
			for (int i = 1; i <= m; i++)
				sum += c[i];
			opt.push_back({sum, r[1]});
		}
	}
	if (opt.empty()){
		cout << -1 << endl;
		return 0;
	}
	sort(opt.begin(), opt.end());
	r[1] = opt[0].second;
	for (int j = 1; j <= m; j++)
		c[j] = g[1][j] - r[1];
	for (int j = 1; j <= n; j++)
		r[j] = g[j][1] - c[1];
	cout << opt[0].first << '\n';
	for (int i = 1; i <= n; i++)
		while (r[i] --)
			cout << "row " << i << '\n';
	for (int i = 1; i <= m; i++)
		while (c[i] --)
			cout << "col " << i << '\n';
}