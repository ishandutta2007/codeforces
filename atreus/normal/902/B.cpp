#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <fstream>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;
bool mark[maxn];
vector <int> v[maxn];
int c[maxn], col[maxn];
int cnt;

void dfs(int x, int fat){
	mark[x] = true;
	if (fat == -1){
		cnt ++;
		col[x] = c[x];
	}
	else
		col[x] = col[fat];
	if (col[x] != c[x]){
		cnt ++;
		col[x] = c[x];
	}
	for (int i = 0; i < v[x].size(); i++){
		if (!mark[v[x][i]])
			dfs (v[x][i], x);
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		int dad;
		cin >> dad;
		v[i].push_back(dad);
		v[dad].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dfs (1, -1);
	cout << cnt << endl;
}