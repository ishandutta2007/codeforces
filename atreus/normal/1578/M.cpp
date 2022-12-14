#include <bits/stdc++.h>
using namespace std;

#define ios				ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define all(x)			x.begin(), x.end()
#define pb				push_back
#define mp				make_pair

typedef long long ll;
const int maxn = 1e3 + 10;
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;

vector<pair<int, int>> G[maxn][maxn];
vector<int> S;
bool visited[maxn][maxn];
int cnt;

void yal(int x, int y, int i, int j){
	G[x][y].pb({i, j});
	G[i][j].pb({x, y});
}

void dfs(int x, int y){
	visited[x][y] = true;
	cnt ++;
	for(auto u : G[x][y]){
		if(!visited[u.first][u.second]){
			dfs(u.first, u.second);
		}
	}
}

int main(){
	ios;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			int a;
			cin >> a;
			if(!(a >> 3 & 1) and i){
				yal(i, j, i - 1, j);
			}
			if(!(a >> 2 & 1) and j < m - 1){
				yal(i, j, i, j + 1);
			}
			if(!(a >> 1 & 1) and i < n - 1){
				yal(i, j, i + 1, j);
			}
			if(!(a >> 0 & 1) and j){
				yal(i, j, i, j - 1);
			}
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(!visited[i][j]){
				cnt = 0;
				dfs(i, j);
				S.pb(cnt);
			}
		}
	}
	sort(all(S), greater<int>());
	for(int i : S)
		cout << i << ' ';
	cout << '\n';
}