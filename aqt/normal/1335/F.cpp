
// Problem : F. Robots on a Grid
// Contest : Codeforces - Codeforces Round #634 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1335/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, C;
string good[1000005];
string typ[1000005];
vector<int> cyc[1000005];
vector<int> dis[1000005];
vector<bool> vis[1000005];
vector<bool> instk[1000005];
vector<int> who[1000005];
vector<bool> cnt[1000005];
vector<bool> tkn[1000005];
int cyclen[1000005];

inline void dfs(int n, int m){
	if(vis[n][m]){
		return;
	}
	int nn = n, nm = m;
	instk[n][m] = vis[n][m] = 1;
	if(typ[n][m] == 'R'){
		nm++;
	}
	if(typ[n][m] == 'L'){
		nm--;
	}
	if(typ[n][m] == 'U'){
		nn--;
	}
	if(typ[n][m] == 'D'){
		nn++;
	}
	if(instk[nn][nm]){
		who[n][m] = ++C;
		cyclen[C] = cyc[n][m] - cyc[nn][nm] + 1;
		dis[n][m] = 0;
		instk[n][m] = 0;
		return;
	}
	cyc[nn][nm] = cyc[n][m] + 1;
	dfs(nn, nm);
	dis[n][m] = (dis[nn][nm] + 1);
	who[n][m] = who[nn][nm];
	instk[n][m] = 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> N >> M;
		C = 0;
		for(int i = 0; i<N; i++){
			cin >> good[i];
			cyc[i].resize(M, 0);
			dis[i].resize(M, 0);
			instk[i].resize(M, 0);
			vis[i].resize(M, 0);
			who[i].resize(M, 0);
		}
		for(int i = 0; i<N; i++){
			cin >> typ[i];
		}
		for(int i = 0; i<N; i++){
			for(int j = 0; j<M; j++){
				dfs(i, j);
			}
		}
		//cout << "hi" << endl;
		int tot = 0;
		for(int c = 1; c<=C; c++){
			tkn[c].resize(cyclen[c], 0);
			tot += cyclen[c];
		}
		for(int i = 0; i<N; i++){
			for(int j = 0; j<M; j++){
				if(good[i][j] == '0'){
					//cout << dis[i][j] << "\n";
					tkn[who[i][j]][dis[i][j]%cyclen[who[i][j]]] = 1;
				}
			}
		}
		int blk = 0;
		for(int c = 1; c<=C; c++){
			for(int n : tkn[c]){
				blk += n;
			}
			tkn[c].clear();
		}
		for(int i = 0; i<N; i++){
			cyc[i].clear();
			dis[i].clear();
			instk[i].clear();
			vis[i].clear();
			who[i].clear();
		}
		cout << tot << " " << blk << endl;
	}	
}