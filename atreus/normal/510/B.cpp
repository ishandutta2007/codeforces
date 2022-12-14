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

const int maxn = 3e3 + 500;
bool mark[maxn];
string s[100];
int id[100][100];
vector <int> v[maxn];
bool cycle;

void dfs (int x, int dad){
	mark[x] = 1;
	for (int i = 0; i < v[x].size(); i++){
		if (!mark[v[x][i]])
			dfs(v[x][i], x);
		else if (v[x][i] != dad)
			cycle = 1;
	}
}

int main (){
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		string a;
		cin >> a;
		s[i] = "0" + a;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			id[i][j] = cnt ++;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (i != n and s[i][j] == s[i + 1][j])
				v[id[i][j]].push_back(id[i + 1][j]);
			if (i != 1 and s[i][j] == s[i - 1][j])
				v[id[i][j]].push_back(id[i - 1][j]);
			if (j != m and s[i][j] == s[i][j + 1])
				v[id[i][j]].push_back(id[i][j + 1]);
			if (j != 1 and s[i][j] == s[i][j - 1])
				v[id[i][j]].push_back(id[i][j - 1]);
		}
	}
	for (int i = 1; i <= n * m; i++)
		if (!mark[i])
			dfs (i, 0);
	if (cycle)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}