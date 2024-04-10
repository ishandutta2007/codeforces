#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 1e3 + 100;
int dp[maxn * maxn][5], id[maxn][maxn];
vector <pair <int, int> > v[maxn * maxn];
bool visited[maxn * maxn];
string s[maxn];

void bfs (int u, int st){
	deque <int> deq;
	dp[u][st] = 0;
	visited[u] = 1;
	deq.push_back(u);
	while (!deq.empty()){
		u = deq.front();
		deq.pop_front();
		for (auto w : v[u]){
			if (!visited[w.F]){
				if (w.S == 0){
					visited[w.F] = 1;
					dp[w.F][st] = dp[u][st];
					deq.push_front(w.F);
				}
				else {
					dp[w.F][st] = dp[u][st] + 1;
					visited[w.F] = 1;
					deq.push_back(w.F);
				}
			} 
		}
	}
}

int cnt = 0;

void make_id(int x, int y){
	id[x][y] = cnt;
	cnt ++;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < m; j++){
			make_id(i, j);
			if (j > 0 and s[i][j] != '#' and s[i][j - 1] != '#'){
				int k = id[i][j];
				int l = id[i][j - 1];
				int w = (s[i][j - 1] == '.');
				v[k].PB(MP(l, w));
				w = (s[i][j] == '.');
				v[l].PB(MP(k, w));
			}
			if (i > 0 and s[i][j] != '#' and s[i - 1][j] != '#'){
				int k = id[i][j];
				int l = id[i - 1][j];
				int w = (s[i - 1][j] == '.');
				v[k].PB(MP(l, w));
				w = (s[i][j] == '.');
				v[l].PB(MP(k, w));
			}
		}
	}
	bool  one = false, two = false, three = false;
	memset (dp, -1, sizeof dp);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (s[i][j] == '1' and !one){
				memset (visited, 0, sizeof visited);
				one = 1;
				bfs (id[i][j], 1);
			}
			if (s[i][j] == '2' and !two){
				memset (visited, 0, sizeof visited);
				two = 1;
				bfs (id[i][j], 2);
			}
			if (s[i][j] == '3' and !three){
				memset (visited, 0, sizeof visited);
				three = 1;
				bfs (id[i][j], 3);
			}
		}
	}
	ll k = inf;
	for (int l = 0; l < n; l++){
		for (int j = 0; j < m; j++){
			int i = id[l][j];
			if (dp[i][1] == -1 || dp[i][2] == -1 || dp[i][3] == -1)
				continue;
			k = min(k, 1ll * dp[i][1] + dp[i][2] + dp[i][3] - 2 * (s[l][j] == '.'));
		}
	}
	if (k == inf)
		k = -1;
	cout << k << endl;
}