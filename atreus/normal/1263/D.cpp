#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e5 + 5;
 
int adj[30][30];
bool mark[30], visited[30];
 
void dfs(int v){
	visited[v] = 1;
	for (int i = 0; i < 26; i++)
		if (adj[v][i] and !visited[i])
			dfs(i);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		int m = s.size();
		for (int j = 0; j < m; j++)
			mark[(int)(s[j] - 'a')] = 1;
		for (int j = 0; j < m - 1; j++){
			int v = (int)(s[j] - 'a'), u = (int)(s[j + 1] - 'a');
			adj[v][u] = adj[u][v] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
		if (mark[i] and !visited[i])
			dfs(i), ans ++;
	cout << ans << endl;
}