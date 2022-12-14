#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <fstream>

#define F first
#define S second
#define PB push_back
using namespace std;

const int maxn = 3e5 + 500;
pair <int, int> coor[maxn];
bool mark[maxn];
string s[600];
int id[600][600];
vector <int> v[maxn];
int k;

void dfs (int x, int dad){
//	cout << x << " " << dad << endl;
	mark[x] = 1;
	bool cur = 0;
	vector <int> bax;
	for (int i = 0; i < v[x].size(); i++){
		if (!mark[v[x][i]]){
			cur = 1;
			bax.push_back(v[x][i]);
			dfs(v[x][i], x);
		}
	}
	if (!cur and k > 0){
		k --;
		int a = coor[x].F;
		int b = coor[x].S;
		s[a][b] = 'X';
		return;
	}
	cur = 0;
//	cout << x << " " << coor[x].F << " " << coor[x].S << " -> ";
	for (int i = 0; i < bax.size(); i++)
		if (s[coor[bax[i]].F][coor[bax[i]].S] != 'X')
			cur = 1;
	if (!cur and k > 0){
		k --;
		int a = coor[x].F;
		int b = coor[x].S;
		s[a][b] = 'X';
	}
	return;
}

int main (){
	int cnt = 1, n, m;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		string a;
		cin >> a;
		s[i] = "0" + a;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] == '.'){
				id[i][j] = cnt;
				coor[cnt] = make_pair(i, j);
				cnt ++;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] != '.')
				continue;
			int l = id[i][j];
			if (i != n && s[i + 1][j] == '.'){
				int y = id[i + 1][j];
				v[l].push_back(y);
			}
			if (i != 1 && s[i - 1][j] == '.'){
				int y = id[i - 1][j];
				v[l].push_back(y);
			}
			if (j != m && s[i][j + 1] == '.'){
				int y = id[i][j + 1];
				v[l].push_back(y);
			}
			if (j != 1 && s[i][j - 1] == '.'){
				int y = id[i][j - 1];
				v[l].push_back(y);
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] == '.' and !mark[id[i][j]])
				dfs (id[i][j], 0);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < s[i].size(); j++)
			cout << s[i][j];
		cout << endl;
	}
}