# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
vector <int> a[xn];
long long int t[xn];
pair <long long int,int> dp[xn];

int main(){
	long long int n, m, q, w, mx, dx;
	cin >> n >> m;
	for (int i=0; i<m; i++){
		cin >> q >> w;
		if (q < w) a[w].push_back(q);
		else a[q].push_back(w);
		t[q]++, t[w]++;
	}
	dp[1].first = 1, dp[1].second = 1;
	for (int i=2; i<=n; i++){
		mx = 0, dx = 0;
		for (int j=0; j<a[i].size(); j++)
			if (dp[a[i][j]].first > mx) mx = dp[a[i][j]].first, dx = a[i][j];
		if (dx == 0) dp[i].first = 1, dp[i].second = i;
		else dp[i].first = mx+1, dp[i].second = dp[dx].second;
	}
	mx = 0;
	for (int i=1; i<=n; i++) mx = max(mx,dp[i].first*t[i]);
	cout << mx;
	return 0;
}