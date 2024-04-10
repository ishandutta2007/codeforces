
// Problem : E. Maze 2D
// Contest : Codeforces - Coder-Strike 2014 - Round 2
// URL : https://codeforces.com/contest/413/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int ans[200005];
char mp[2][200005];
int lft[200005];
int rht[200005];
int dist[2][2][200005];
queue<pair<int, int>> qu;

void bfs(int l, int r, int t, int n){
	if(mp[t][n] == 'X'){
		return;
	}
	//cout << t << " " << n << "\n";
	qu.push(make_pair(t, n));
	dist[t][t][n] = 0;
	while(qu.size()){
		auto p = qu.front();
		//cout << p.first << " " << p.second << endl;
		qu.pop();
		if(mp[p.first^1][p.second] == '.' && dist[t][p.first^1][p.second] > dist[t][p.first][p.second] + 1){
			dist[t][p.first^1][p.second] = dist[t][p.first][p.second] + 1;
			qu.push(make_pair(p.first^1, p.second));
		}
		if(p.second - 1 >= l && mp[p.first][p.second-1] == '.' && dist[t][p.first][p.second-1] > dist[t][p.first][p.second] + 1){
			dist[t][p.first][p.second-1] = dist[t][p.first][p.second] + 1;
			qu.push(make_pair(p.first, p.second-1));
		}
		if(p.second + 1 <= r && mp[p.first][p.second+1] == '.' && dist[t][p.first][p.second+1] > dist[t][p.first][p.second] + 1){
			dist[t][p.first][p.second+1] = dist[t][p.first][p.second] + 1;
			qu.push(make_pair(p.first, p.second+1));
		}
	}
}

void solve(int l, int r, vector<int> v){
	if(v.empty()){
		return;
	}
	int mid = l+r>>1;
	//cout << l << " " << r << " " << v.size() << endl;
	for(int i = l; i<=r; i++){
		dist[0][0][i] = dist[0][1][i] = INT_MAX/3;
		dist[1][0][i] = dist[1][1][i] = INT_MAX/3;
	}
	bfs(l, r, 0, mid);
	bfs(l, r, 1, mid);
	vector<int> ll, rr;
	for(int n : v){
		if((rht[n] > N ? rht[n] - N : rht[n]) < mid){
			ll.push_back(n);
		}
		else if((lft[n] > N ? lft[n] - N : lft[n]) > mid){
			rr.push_back(n);
		}
		else{
			int typ = lft[n] > N;
			int pos = typ ? lft[n]-N : lft[n];
			int opt0 = dist[0][typ][pos];
			int opt1 = dist[1][typ][pos];
			typ = rht[n] > N;
			pos = typ ? rht[n] - N : rht[n];
			opt0 += dist[0][typ][pos];
			opt1 += dist[1][typ][pos];
			//cout << " " << n << " " << opt0 << " " << opt1 << "\n";
			ans[n] = min(opt0, opt1);
			if(ans[n] > 3*N){
				ans[n] = -1;
			}
		}
	}
	solve(l, mid-1, ll);
	solve(mid+1, r, rr);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int k = 0; k<2; k++){
		for(int i = 1; i<=N; i++){
			cin >> mp[k][i];
		}
	}
	for(int q = 1; q<=Q; q++){
		cin >> lft[q] >> rht[q];
		if((lft[q] > N ? lft[q] - N : lft[q]) > (rht[q] > N ? rht[q] - N : rht[q])){
			swap(lft[q], rht[q]);
		}
	}
	vector<int> init(Q);
	iota(init.begin(), init.end(), 1);
	solve(1, N, init);
	for(int q = 1; q<=Q; q++){
		cout << ans[q] << "\n";
	}
}