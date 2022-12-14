#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>
#define MP make_pair
#define F first
#define S second
#define PB push_back
using namespace std;

const int maxn = 1e3 + 100;
set <pair <long long, long long> > s;
long long dp[maxn][maxn], dis[maxn];
int t[maxn], c[maxn];
vector <pair <int, int> > v[maxn];
vector <pair <int, int> > g[maxn];
int n;

void dijkstra1 (int u){
	for (int i = 1; i < n; i++){
		for (int j = 0; j < v[u].size(); j++){
			int w = v[u][j].F;
			if (dis[u] + v[u][j].S < dis[w] || dis[w] == -1){
				s.erase (MP(dis[w], w));
				dis[w] = dis[u] + v[u][j].S;
				s.insert (MP(dis[w], w));
			}
		}
		set <pair <long long, long long> >::iterator it = s.lower_bound(MP(0, 0));
		if (it == s.end())
			return;
		u = (*it).S;
		s.erase(it);
	}
}

void dijkstra (int u, int k){
//	cout << " >> " << k << " << " << endl;
	for (int i = 1; i < n; i++){
//		cout << u << " - > ";
		for (int j = 0; j < g[u].size(); j++){
			int w = g[u][j].F;
			if (dp[k][u] + g[u][j].S < dp[k][w]){
				s.erase (MP(dp[k][w], w));
				dp[k][w] = dp[k][u] + g[u][j].S;
				s.insert (MP(dp[k][w], w));
			}
//			cout << w << " " << dp[k][w] << endl;
		}
		set <pair <long long, long long> >::iterator it = s.begin();
		u = (*it).S;
		s.erase(s.begin());
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int m, home, dest;
	cin >> n >> m >> home >> dest;
	for (int i = 0; i < m; i++){
		int u, w, x;
		cin >> u >> w >> x;
		g[u].PB(MP(w, x));
		g[w].PB(MP(u, x));
	}
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> c[i];
	for (int i = 1; i <= n; i++){
		memset (dp[i], 63, sizeof dp[i]);
		s.clear();
		for (long long j = 1; j <= n; j++)
			if (j != i)
				s.insert (MP(dp[i][j], j));
		dp[i][i] = 0;
		dijkstra (i, i);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (j == i)
				continue;
			if (dp[i][j] <= t[i]){
				v[i].PB(MP(j, c[i]));
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (i != home)
			s.insert(MP(dis[i], i));
	memset (dis, -1, sizeof dis);
	dis[home] = 0;
	s.clear();
	for (long long i = 1; i <= n; i++)
		if (i != home)
			s.insert (MP(dis[i], i));
	dijkstra1 (home);
	cout << dis[dest] << endl;
	return 0;
}