# include <bits/stdc++.h>

using namespace std;

const int xn = 5e1+10;
bool mark[xn], f[xn];
vector <int> adj[xn], team[xn];
//vector < pair <int, int> > ans;

void DFS(int v, int t){
	mark[v] = true;
	team[t].push_back(v);
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u, t);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i=0; i<m; i++) cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);
	int t = 0;
	for (int i=1; i<=n; i++)
		if (!mark[i]) DFS(i, t), t++;
	x = 0, y = 0;
	for (int i=0; i<t; i++){
		//cout << team[i].size() << endl;
		if (team[i].size() > 3){
			cout << -1 << endl;
			return 0;
		}
		if (team[i].size() == 2) y++;
		else if (team[i].size() == 1) x++;
	}
	if (y > x){
		cout << -1 << endl;
		return 0;
	}
	for (int i=0; i<t; i++){
		if (team[i].size() == 3){
			
			for (int j=0; j<3; j++) cout << team[i][j] << ' ';
			cout << endl;
		}
		else if (team[i].size() == 2){
			for (int j=0; j<t; j++){
				if (team[j].size() == 1 and !f[j]){
					cout << team[i][0] << ' ' << team[i][1] << ' ' << team[j][0] << endl;
					f[j] = true;
					break;
				}
			}
		}
	}
	vector <int> tt1;
	int r = 0;
	for (int i=0; i<t; i++){
		if (team[i].size() == 1 and !f[i]){
			r++;
			tt1.push_back(team[i][0]);
			if (r == 3){
				for (int j=0; j<3; j++) cout << tt1[j] << ' ';
				cout << endl;
				tt1.resize(0);
				r = 0;
			}
		}
	}
	return 0;
}