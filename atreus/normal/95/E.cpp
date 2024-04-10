#include <iostream>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

const int maxn = 2e5 + 500;
bool mark[maxn];
int degree = 0;
int dp[maxn];
vector <int> deg, luckynum;
vector <int> con[maxn];
vector <pair <int, int> > v;
vector <pair <int, int> > u;

void makelucky(){
	for (int i = 1; i <= 77777; i++){
		bool cur = true;
		int qp = i;
		while (qp > 0){
			int p = qp % 10;
			if (p != 7 and p != 4)
				cur = false;
			qp /= 10;
		}
		if (cur)
			luckynum.push_back(i);
	}
	return;
}

void dfs(int x){
	mark[x] = true;
	degree ++;
	for (int i = 0; i < con[x].size(); i++)
		if (!mark[con[x][i]])
			dfs(con[x][i]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		if (v1 == v2)
            continue;
		con[v1].push_back(v2);
		con[v2].push_back(v1);
	}
	for (int i = 1; i <= n; i++){
		if (!mark[i]){
			dfs(i);
			deg.push_back(degree);
			degree = 0;
		}
	}
	sort (deg.begin(), deg.end());
	int qp = 1;
	for (int i = 1; i < deg.size(); i++){
		if (deg[i] != deg[i - 1]){
			v.push_back(make_pair(deg[i - 1], qp));
			qp = 1;
		}
		else
			qp ++;
	}
	v.push_back(make_pair(deg[deg.size() - 1], qp));
	for (int i = 0; i < v.size(); i++){
		int t = 1, copy = v[i].second;
		while (v[i].second >= t){
			u.push_back(make_pair(t * v[i].first, t));
			v[i].second -= t;
			t *= 2;
		}
		if (v[i].second)
			u.push_back(make_pair(v[i].first * v[i].second, v[i].second));
	}
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	for (int i = 0; i < u.size(); i++){

		for (int j = 77777; j >= 0; j--){
			if (dp[j] != -1){
				if (dp[j + u[i].first] == -1)
					dp[j + u[i].first] = maxn;
				dp[j + u[i].first] = min (dp[j + u[i].first], dp[j] + u[i].second);
			}
		}
	}
	makelucky();
	int ans = 100000001;
	for (int i = 0; i < luckynum.size(); i++)
        if (dp[luckynum[i]] != -1){
            ans = min(ans, dp[luckynum[i]]);
		}
    ans --;
	if (ans == 100000000)
		ans = -1;
	cout << ans << endl;
}