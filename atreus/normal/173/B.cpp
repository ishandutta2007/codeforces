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

const int maxn = 2e3 + 100;
vector <int> v[maxn];
bool mark[maxn];
int dp[maxn];
int cnt;
string s[maxn];
queue <int> qu;

void bfs (){
	while (!qu.empty()){
		int u = qu.front();
//		cout << u << " - >";
		for (int i = 0; i < v[u].size(); i++){
			int w = v[u][i];
//			cout << w << " ";
			if (!mark[w]){
				mark[w] = 1;
				dp[w] = dp[u] + 1;
				qu.push(w);
			}
		}
//		cout << endl;
		qu.pop();
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	memset (dp, -1, sizeof dp);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (s[i][j] == '#'){
				v[i].PB(j + n);
				v[j + n].PB(i);
			}
		}
	}
	qu.push(n - 1);
	mark[n - 1] = 1;
	dp[n - 1] = 0;
	bfs ();
	cout << dp[0] << endl;
}