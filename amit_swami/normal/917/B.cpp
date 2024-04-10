#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;
int dp[MAXN][MAXN][26];
vector <pair<int,int>> v[MAXN];

int dfs(int i, int j, int k){
	if(dp[i][j][k]) return dp[i][j][k];
	for(auto to : v[i])
		if(to.second >= k && dfs(j, to.first, to.second) == 2)
				return dp[i][j][k] = 1;
	return dp[i][j][k] = 2;
}

int main(){
   
    int a, b, n, m;
    char c;
	cin >> n >> m;
    for(int i=0; i < m; i++){
		cin >> a >> b >> c;
		v[--a].push_back({--b, c - 'a'});
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << (dfs(i,j,0)==1 ? 'A' : 'B');
		cout << '\n';
	}
}