
// Problem : A2. Binary Table (Hard Version)
// Contest : Codeforces - Codeforces Round #684 (Div. 1)
// URL : https://codeforces.com/contest/1439/problem/A2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
bool tbl[105][105];
vector<vector<pair<int, int>>> ans;

bool pos(int dep){
	if(!tbl[N-1][M-1] && !tbl[N][M-1] && !tbl[N-1][M] && !tbl[N][M]){
		return 1;
	}
	if(dep == 4){
		return 0;
	}
	for(int i = N-1; i<=N; i++){
		for(int j = M-1; j<=M; j++){
			for(int a = N-1; a<=N; a++){
				for(int b = M-1; b<=M; b++){
					if(a == i && b == j){
						continue;
					}
					tbl[a][b] ^= 1;
				}
			}
			bool done = pos(dep+1);
			vector<pair<int, int>> tmp;
			for(int a = N-1; a<=N; a++){
				for(int b = M-1; b<=M; b++){
					if(a == i && b == j){
						continue;
					}
					tbl[a][b] ^= 1;
					if(done){
						tmp.emplace_back(a, b);
					}
				}
			}
			if(done){
				ans.push_back(tmp);
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				char c;
				cin >> c;
				tbl[i][j] = (c == '1');
			}
		}
		ans.clear();
		for(int i = 1; i<=N-2; i++){
			for(int j = 1; j<=M; j++){
				if(tbl[i][j]){
					vector<pair<int, int>> tmp;
					tmp.push_back(make_pair(i, j));
					tbl[i][j] ^= 1;
					tmp.push_back(make_pair(i+1, j));
					tbl[i+1][j] ^= 1;
					if(j == M){
						tmp.push_back(make_pair(i+1, j-1));
						tbl[i+1][j-1] ^= 1;
					}
					else{
						tmp.push_back(make_pair(i+1, j+1));
						tbl[i+1][j+1] ^= 1;
					}
					ans.push_back(tmp);
				}
			}
		}
		for(int j = 1; j<=M-2; j++){
			if(!tbl[N-1][j] && !tbl[N][j]){
				continue;
			}
			vector<pair<int, int>> tmp;
			if(tbl[N-1][j]){
				tmp.emplace_back(N-1, j);
				tbl[N-1][j] ^= 1;
			}
			if(tbl[N][j]){
				tmp.emplace_back(N, j);
				tbl[N][j] ^= 1;
			}
			if(tmp.size() < 3){
				tmp.emplace_back(N-1, j+1);
				tbl[N-1][j+1] ^= 1;
			}
			if(tmp.size() < 3){
				tmp.emplace_back(N, j+1);
				tbl[N][j+1] ^= 1;
			}
			ans.push_back(tmp);
		}
		pos(0);
		cout << ans.size() << "\n";
		for(auto v : ans){
			for(auto p : v){
				cout << p.first << " " << p.second << " ";
			}
			cout << "\n";
		}
	}
}