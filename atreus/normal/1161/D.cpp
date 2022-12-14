#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2000 + 10;
const int mod = 998244353;

string s;
int n, mark, cmp, dp[maxn];
vector<pair<int, int> > g[maxn];
bool visited[maxn];

bool dfs(int v){
	if ((v >= n and v <= mark) or v == 0)
		cmp = 0;
//	cout << "visited : " << v << endl;
	visited[v] = 1;
	bool ret = 1;
	for (auto it : g[v]){
		int u = it.first, w = it.second;
		if (!visited[u]){
			dp[u] = dp[v] ^ w;
			ret &= dfs(u);
		}
		else
			ret &= (dp[u] == (dp[v] ^ w));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	for (int i = 0; i < (n + 1) / 2; i++){
		g[i].push_back({n - i - 1, 0});
		g[n - i - 1].push_back({i, 0});
	}
	for (int i = 0; i < n; i++){
		if (s[i] == '0'){
			g[i].push_back({n + i, 0});
			g[n + i].push_back({i, 0});
		}
		else if (s[i] == '1'){
			g[i].push_back({n + i, 1});
			g[n + i].push_back({i, 1});
		}
	}
	ll sum = 0;
	for (int i = 0; i < n - 1; i++){
		int len = n - i - 1;
		for (int j = i + 1; j <= i + (len + 1) / 2; j++){
//			cout << i << " -> " << j << " " << n - (j - i) << endl;
			g[n + j].push_back({n + (n - (j - i)), 0});
			g[n + (n - (j - i))].push_back({n + j, 0});
		}
		memset(visited, 0, sizeof visited);
		ll answer = 1;
		mark = n + i + 1;
		for (int j = 0; j < 2 * n; j++){
			if (!visited[j]){
				cmp = 1;
				dp[j] = 1;
				int k = dfs(j);
//				cout << "Now : " << j << " -> " << k << endl;
				answer = 1ll * answer * (cmp + 1) * k % mod;
				if (j == 0 and visited[n + i + 1] == 1 and dp[n + i + 1] == 0)
					answer = 0;
			}
		}
		for (int j = i + 1; j <= i + (len + 1) / 2; j++){
			g[n + j].pop_back();
			g[n + (n - (j - i))].pop_back();
		}
		g[n + i].push_back({n + i + 1, 0});
		g[n + i + 1].push_back({n + i, 0});
//		cout << i << " -> " << answer << endl;
		sum = (sum + answer) % mod;
	}
	cout << sum << endl;
}