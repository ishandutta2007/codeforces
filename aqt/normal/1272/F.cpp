
// Problem : F. Two Bracket Sequences
// Contest : Codeforces - Codeforces Round #605 (Div. 3)
// URL : https://codeforces.com/contest/1272/problem/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

short dist[1005][205][205];
pair<short, pair<short, short>> par[1005][205][205];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	cin >> s >> t;
	int N = s.size(), M = t.size();
	for(int k = 0; k<=1000; k++){
		for(int n = 0; n<=N; n++){
			for(int m = 0; m<=M; m++){
				dist[k][n][m] = SHRT_MAX/2;
			}
		}
	}
	dist[0][0][0] = 0;
	queue<pair<short, pair<short, short>>> qu;
	qu.push(make_pair(0, make_pair(0, 0)));
	while(qu.size()){
		auto p = qu.front();
		//cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
		qu.pop();
		if(p.first == 0 && p.second.first == N && p.second.second == M){
			vector<char> ans;
			int k = p.first, crnti = p.second.first, crntj = p.second.second;
			//cout << dist[k][crnti][crntj] << "\n";
			while(k || crnti != 0 || crntj != 0){
				//cout << k << " " << crnti << " " << crntj << endl;
				//cout << par[k][crnti][crntj] << "\n";
				if(par[k][crnti][crntj].first < k){
					int nwi = par[k][crnti][crntj].second.first;
					int nwj = par[k][crnti][crntj].second.second;
					crnti = nwi;
					crntj = nwj;
					k--;
					ans.push_back('(');
				}
				else{
					int nwi = par[k][crnti][crntj].second.first;
					int nwj = par[k][crnti][crntj].second.second;
					crnti = nwi;
					crntj = nwj;					
					k++;
					ans.push_back(')');
				}
			}
			reverse(ans.begin(), ans.end());
			for(char c : ans){
				cout << c;
			}
			return 0;
		}
		int d = dist[p.first][p.second.first][p.second.second];
		int nxti = p.second.first;
		if(nxti < N){
			nxti += (s[nxti] == '(');
		}
		int nxtj = p.second.second;
		if(nxtj < M){
			nxtj += (t[nxtj] == '(');
		}
		if(dist[p.first+1][nxti][nxtj] > d + 1){
			dist[p.first+1][nxti][nxtj] = d + 1;
			par[p.first+1][nxti][nxtj] = p;
			qu.push(make_pair(p.first+1, make_pair(nxti, nxtj)));
		}
		if(p.first){
			nxti = p.second.first;
			nxtj = p.second.second;
			if(nxti < N){
				nxti += (s[nxti] == ')');
			}
			if(nxtj < M){
				nxtj += (t[nxtj] == ')');
			}
			if(dist[p.first-1][nxti][nxtj] > d+1){
				dist[p.first-1][nxti][nxtj] = d+1;
				par[p.first-1][nxti][nxtj] = p;
				qu.push(make_pair(p.first-1, make_pair(nxti, nxtj)));
			}
		}
	}
}