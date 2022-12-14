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

const int maxn = 1e5 + 100;
set <pair <long long, int> > s;
long long dp[maxn], par[maxn];
vector <pair <int, int> > v[maxn];
int n;

void print_path (int u){
	if (par[u] == 0)
		cout << u << " ";
	else {
		print_path(par[u]);
		cout << u << " ";
	}
}

void dijkstra (int u){
	for (int i = 1; i < n; i++){
		for (int j = 0; j < v[u].size(); j++){
			int w = v[u][j].F;
			if (dp[w] == -1 || dp[u] + v[u][j].S < dp[w]){
				s.erase (MP(dp[w], w));
				dp[w] = dp[u] + v[u][j].S;
				par[w] = u;
				s.insert (MP(dp[w], w));
			}
		}
		set<pair <long long, int> >::iterator it = s.lower_bound(MP(0, 0));
		if (it == s.end())
            return;
		u = (*it).S;
		s.erase(it);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, w, x;
		cin >> u >> w >> x;
		v[u].PB(MP(w, x));
		v[w].PB(MP(u, x));
	}
	memset (dp, -1, sizeof dp);
	for (int i = 2; i <= n; i++)
		s.insert(MP(dp[i], i));
	dp[1] = 0;
	dijkstra (1);
//	for (int i = 1; i <= n; i++)
//		cout << dp[i] << " ";
	if (dp[n] == -1)
		return cout << -1 << endl, 0;
	print_path(n);
	return 0;
}