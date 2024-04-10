#include <iostream>
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
const int inf = 1e9 + 7, maxn = 100;
bool visited[maxn][maxn][maxn];
int n, dp[maxn][maxn][maxn];
pair <int, pair <int, int> > par[maxn][maxn][maxn];
pair <int, int> ans [maxn][maxn][maxn];
vector <pair <int, int> > v;
string s[maxn];
queue <pair <int, pair <int, int> > > q;

void f(int a, int b, int c){
	dp[a][b][c] = 0;
	dp[a][c][b] = 0;
	dp[b][c][a] = 0;
	dp[b][a][c] = 0;
	dp[c][a][b] = 0;
	dp[c][b][a] = 0;
	q.push({a, {b, c}});
	q.push({a, {c, b}});
	q.push({b, {a, c}});
	q.push({b, {c, a}});
	q.push({c, {a, b}});
	q.push({c, {b, a}});
	visited[a][b][c] = 1;
	visited[a][c][b] = 1;
	visited[b][a][c] = 1;
	visited[b][c][a] = 1;
	visited[c][a][b] = 1;
	visited[c][b][a] = 1;
}

void bfs (int a, int b, int c){
	visited[a][b][c] = 1;
	memset (dp, 63, sizeof dp);
	f(a, b, c);
	while (!q.empty()){
		pair <int, pair <int, int> > v = q.front();
		q.pop();
		a = v.F;
		b = v.S.F;
		c = v.S.S;
		for (int i = 1; i <= n; i++){
			if (i == a || i == b || i == c)
				continue;
			if (s[a][i] == s[b][c]){
				if (!visited[i][b][c]){
					dp[i][b][c] = dp[a][b][c] + 1;
					visited[i][b][c] = 1;
					par[i][b][c] = {a, {b, c}};
					ans[i][b][c] = {a, i};
					q.push({i, {b, c}});
				}
				if (!visited[i][c][b]){
					dp[i][c][b] = dp[a][b][c] + 1;
					visited[i][c][b] = 1;
					par[i][c][b] = {a, {b, c}};
					ans[i][c][b] = {a, i};
					q.push({i, {c, b}});
				}
				if (!visited[b][i][c]){
					dp[b][i][c] = dp[a][b][c] + 1;
					visited[b][i][c] = 1;
					par[b][i][c] = {a, {b, c}};
					ans[b][i][c] = {a, i};
					q.push({b, {i, c}});
				}
				if (!visited[b][c][i]){
					dp[b][c][i] = dp[a][b][c] + 1;
					visited[b][c][i] = 1;
					par[b][c][i] = {a, {b, c}};
					ans[b][c][i] = {a, i};
					q.push({b, {c, i}});
				}
				if (!visited[c][i][b]){
					dp[c][i][b] = dp[a][b][c] + 1;
					visited[c][i][b] = 1;
					par[c][i][b] = {a, {b, c}};
					ans[c][i][b] = {a, i};
					q.push({c, {i, b}});
				}
				if (!visited[c][b][i]){
					dp[c][b][i] = dp[a][b][c] + 1;
					visited[c][b][i] = 1;
					par[c][b][i] = {a, {b, c}};
					ans[c][b][i] = {a, i};
					q.push({c, {b, i}});
				}
			}
		}
	}
}

int main(){ 
	ios_base::sync_with_stdio(false);
	int a1, a2, a3;
	cin >> n >> a1 >> a2 >> a3;
	for (int i = 1; i <= n; i++){
		string k;
		cin >> k;
		s[i] = '+' + k;
	}
	bfs (a1, a2, a3);
	if (dp[1][2][3] >= inf)
		dp[1][2][3] = -1;
	cout << dp[1][2][3] << endl;
	a1 = 1;
	a2 = 2;
	a3 = 3;
	while (par[a1][a2][a3].F){
		v.PB({ans[a1][a2][a3].F, ans[a1][a2][a3].S});
		int a = par[a1][a2][a3].F;
		int b = par[a1][a2][a3].S.F;
		int c = par[a1][a2][a3].S.S;
		a1 = a;
		a2 = b;
		a3 = c;
	}
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i].F << " " << v[i].S << endl;
}