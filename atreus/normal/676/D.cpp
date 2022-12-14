#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
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
const int inf = 1e9 + 7, maxm = 1e3 + 100, maxn = 4e6 + 500;
int dp[maxn], n, m;
bool visited[maxn];
vector <int> v[maxn];
string s[maxm];
set <char> lef, rig, dow, up;

int ID(int x, int y, int k){
	return 4 * (x * m + y) + k;
}

void make_moves(){
	lef.In('+');
	lef.In('-');
	lef.In('<');
	lef.In('R');
	lef.In('U');
	lef.In('D');
	up.In('+');
	up.In('|');
	up.In('^');
	up.In('R');
	up.In('L');
	up.In('D');
	dow.In('+');
	dow.In('|');
	dow.In('v');
	dow.In('R');
	dow.In('L');
	dow.In('U');
	rig.In('+');
	rig.In('-');
	rig.In('>');
	rig.In('U');
	rig.In('D');
	rig.In('L');
}

void struct_graph(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (j < m - 1){
				char a = s[i][j + 0];
				char b = s[i][j + 1];
				if (rig.find(a) != rig.end() and lef.find(b) != lef.end()){
					v[ID(i, j + 0, 0)].PB(ID(i, j + 1, 0));
					v[ID(i, j + 1, 0)].PB(ID(i, j + 0, 0));
				}
				if (up.find(a) != up.end() and dow.find(b) != dow.end()){
					v[ID(i, j + 0, 1)].PB(ID(i, j + 1, 1));
					v[ID(i, j + 1, 1)].PB(ID(i, j + 0, 1));
				}
				if (lef.find(a) != lef.end() and rig.find(b) != rig.end()){
					v[ID(i, j + 0, 2)].PB(ID(i, j + 1, 2));
					v[ID(i, j + 1, 2)].PB(ID(i, j + 0, 2));
				}
				if (dow.find(a) != dow.end() and up.find(b) != up.end()){
					v[ID(i, j + 0, 3)].PB(ID(i, j + 1, 3));
					v[ID(i, j + 1, 3)].PB(ID(i, j + 0, 3));
				}
			}
			if (i < n - 1){
				char a = s[i + 0][j];
				char b = s[i + 1][j];
				if (dow.find(a) != dow.end() and up.find(b) != up.end()){
					v[ID(i + 0, j, 0)].PB(ID(i + 1, j, 0));
					v[ID(i + 1, j, 0)].PB(ID(i + 0, j, 0));
				}
				if (rig.find(a) != rig.end() and lef.find(b) != lef.end()){
					v[ID(i + 0, j, 1)].PB(ID(i + 1, j, 1));
					v[ID(i + 1, j, 1)].PB(ID(i + 0, j, 1));
				}
				if (up.find(a) != up.end() and dow.find(b) != dow.end()){
					v[ID(i + 0, j, 2)].PB(ID(i + 1, j, 2));
					v[ID(i + 1, j, 2)].PB(ID(i + 0, j, 2));
				}
				if (lef.find(a) != lef.end() and rig.find(b) != rig.end()){
					v[ID(i + 0, j, 3)].PB(ID(i + 1, j, 3));
					v[ID(i + 1, j, 3)].PB(ID(i + 0, j, 3));
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k <= 3; k++){
				v[ID(i, j, k)].PB(ID(i, j, (k + 1) % 4));
			}
		}
	}
}

void bfs (int u){
	memset (dp, -1, sizeof dp);
	queue <int> q;
	q.push(u);
	visited[u] = 1;
	dp[u] = 0;
	while (!q.empty()){
		u = q.front();
		for (int i = 0; i < v[u].size(); i++){
			int w = v[u][i];
			if (dp[w] == -1)
				dp[w] = dp[u] + 1;
			dp[w] = min (dp[w], dp[u] + 1);
			if (!visited[w]){
				visited[w] = 1;
				q.push(w);
			}
		}
		q.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	make_moves();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	struct_graph();
	bfs (ID(x1 - 1, y1 - 1, 0));
	int k = inf;
	for (int i = 0; i <= 3; i++){
		int p = k;
		k = min(dp[ID(x2 - 1, y2 - 1, i)], k);
		if (k == -1)
			k = p;
	}
	if (k == inf)
		k = -1;
	cout << k << endl;
}