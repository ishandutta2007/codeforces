
// Problem : F. Number of Components
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M, Q, T;
vector<pair<int, pair<int, int>>> rem[2000005];
int arr[305][305];
int ed[305][305];
int pre[2000005];
pair<int, int> par[305][305];
vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

pair<int, int> getrt(int x, int y){
	if(par[x][y] == make_pair(x, y)){
		return make_pair(x, y);
	}
	par[x][y] = getrt(par[x][y].first, par[x][y].second);
	return par[x][y];
}

bool merge(int x1, int y1, int x2, int y2){
	if(getrt(x1, y1) != getrt(x2, y2)){
		auto p = getrt(x1, y1);
		par[p.first][p.second] = getrt(x2, y2); 
		return 1;
	}
	return 0;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	pre[0] = 1;
	for(int i = 0; i<=N+1; i++){
		arr[i][M+1] = arr[i][0] = -1;
	}
	for(int j = 0; j<=M+1; j++){
		arr[N+1][j] = arr[0][j] = -1;
	}
	for(int q = 1; q<=Q; q++){
		int x, y, c;
		cin >> x >> y >> c;
		if(c != T){
			T = c;
			for(int i = 1; i<=N; i++){
				for(int j =1 ; j<=M; j++){
					par[i][j] = {i, j};
				}
			}
		}
		assert(arr[x][y] > -1);
		rem[arr[x][y]].push_back(make_pair(q, make_pair(x,y)));
		arr[x][y] = c;
		pre[q]++;
		for(auto m : moves){
			if(arr[x + m.first][y + m.second] == c){
				pre[q] -= merge(x, y, x+m.first, y+m.second);
			}
		}
	}		
	for(int i =1 ; i<=N; i++){
		for(int j = 1; j<=M; j++){
			ed[i][j] = arr[i][j];
		}
	}
	for(int t = 0; t<=T; t++){
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				par[i][j] = {i, j};
				arr[i][j] = ed[i][j];
			}
		}
		int lst = 0;
		for(int i = 1; i<=N; i++){
			for(int j =1 ; j<=M; j++){
				if(arr[i][j] == t){
					lst++;
					for(auto m : moves){
						if(arr[i+m.first][j+m.second] == t){
							lst -= merge(i, j, i+m.first, m.second+j);
						}
					}
				}
			}
		}
		reverse(rem[t].begin(), rem[t].end());
		for(auto n : rem[t]){
			int q = n.first, x = n.second.first, y = n.second.second;
			int crnt = lst+1;
			arr[x][y] = t;
			for(auto m : moves){
				if(arr[x+m.first][y+m.second] == t){
					crnt -= merge(x, y, x+m.first, y+m.second);
				}
			}
			assert(lst-crnt >= -1);
			//cout << lst-crnt << endl;
			pre[q] += lst-crnt;
			lst = crnt;
		}
	}
	for(int q = 1; q<=Q; q++){
		pre[q] += pre[q-1];
		cout << pre[q] << "\n";
	}
}