#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>
#include <cmath>
#include <unordered_set>
#include <map>
#include <queue>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 1e5 + 100;
int wei[maxn], dp[maxn], par[maxn], h[maxn];
bool mark[maxn];
map <pair <int, int>, int> qp;
set <pair <int, int> > s;
map <pair <int, int>, bool> inpath;
pair <int, int> edg[maxn];
queue <int> qu;
vector <pair <int, int> > ans;
vector <pair <int, int> > v[maxn];

void bfs (int n){
	mark[n] = 1;
	qu.push(n);
	while (!qu.empty()){
		int u = qu.front();
		mark[u] = 1;
		for (int i = 0; i < v[u].size(); i++){
			int w = v[u][i].F;
			if (!mark[w]){
				qu.push(w);
				mark[w] = 1;
				dp[w] = min (dp[w], dp[u] + v[u][i].S);
				par[w] = u;
				h[w] = h[u] + 1;
			}
			else if (mark[w] and h[w] > h[u]){
				if (dp[u] + v[u][i].S > dp[w]){
					par[w] = u;
					dp[w] = dp[u] + v[u][i].S;
				}
			}
		}
		qu.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, w, p;
		cin >> u >> w >> p;
		v[u].PB(MP(w, p));
		v[w].PB(MP(u, p));
		edg[i] = MP(u, w);
		wei[i] = p;
		qp[MP(w, u)] = p;
		qp[MP(u, w)] = p;
	}
	memset (dp, 63, sizeof dp);
	dp[1] = 0;
	bfs (1);
	int u = n;
	while (u != 1){
		if (qp[MP(u, par[u])] == 0)
			ans.push_back(MP(u, par[u]));
		s.insert(MP(u, par[u]));
		s.insert(MP(par[u], u));
		u = par[u];
	}
	ans.push_back(MP(-1, -1));
	for (int i = 0; i < m; i++){
		if (s.find(edg[i]) == s.end() and wei[i] == 1)
			ans.push_back(edg[i]);
	}
	cout << ans.size() - 1 << endl;
	int op = 1;
	for (int i = 0; i < ans.size(); i++){
		if (ans[i].F == -1){
			op ^= 1;
			continue;
		}
		cout << ans[i].F << " " << ans[i].S << " " << op << endl;
	}
}