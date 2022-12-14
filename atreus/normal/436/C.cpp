#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#define S second
#define F first
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 100;
int n, m, k, w, dp[maxn], par[maxn];
vector <pair <int, int> > v[maxn], ans;
set <pair <int, int> > s;
string a[maxn][maxn];
bool visited[maxn];

int prim_alg(){
	memset (dp, 63, sizeof dp);
	dp[0] = 0;
	ll ret = 0;
	for (int i = 0; i <= k; i++)
		s.insert (MP (dp[i], i));
	while (!s.empty()){
		int u = (*s.begin()).S;
		visited[u] = 1;
		if (u != 0)
			ans.PB (MP (u, par[u]));
		s.erase (s.begin());
		ret += dp[u];
		for (auto w : v[u]){
			int ver = w.F;
			if (dp[ver] >  w.S && !visited[ver]){
				s.erase (MP (dp[ver], ver));
				dp[ver] = w.S;
				par[ver] = u;
				s.insert (MP (dp[ver], ver));
			}
		}
	}
	return ret;
}

int dis (int idx, int ind){
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += (a[idx][i][j] != a[ind][i][j]);
	return cnt * w;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> w;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= k; i++){
		for (int j = i + 1; j <= k; j++){
			int w = dis (i, j);
			v[i].PB (MP (j, w));
			v[j].PB (MP (i, w));
		}
	}
	for (int i = 1; i <= k; i++){
		v[0].PB (MP (i, n * m));
		v[i].PB (MP (0, n * m));
	}

	cout << prim_alg() << endl;
	for (auto w : ans)
		cout << w.F << " " << w.S << endl;
}