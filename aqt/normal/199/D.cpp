
// Problem : D. Jumping on Walls
// Contest : Codeforces - Codeforces Round #125 (Div. 2)
// URL : https://codeforces.com/contest/199/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
string mp[2];
int vis[2][100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> mp[0] >> mp[1];
	queue<pair<int, int>> qu;
	qu.push({0, 0});
	while(qu.size()){
		auto p = qu.front();
		qu.pop();
		//cout << p.first << " " << p.second << " " << vis[p.first][p.second] << "\n";
		if(vis[p.first][p.second] > p.second){
			continue;
		}
		if(p.second + K >= N){
			cout << "YES\n";
			return 0;
		}
		if(p.second && !vis[p.first][p.second-1] && mp[p.first][p.second-1] == '-'){
			qu.push({p.first, p.second-1});
			vis[p.first][p.second-1] = vis[p.first][p.second] + 1;
		}
		if(!vis[p.first][p.second+1] && mp[p.first][p.second+1] == '-'){
			qu.push({p.first, p.second+1});
			vis[p.first][p.second+1] = vis[p.first][p.second] + 1;
		}
		if(!vis[p.first^1][p.second+K] && mp[p.first^1][p.second+K] == '-'){
			qu.push({p.first^1, p.second+K});
			vis[p.first^1][p.second+K] = vis[p.first][p.second] + 1;
		}
	}
	cout << "NO\n";
}