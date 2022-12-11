
// Problem : F. Crisp String
// Contest : Educational Codeforces Round 60 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1117/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> pos[20];
bool mat[20][20];
int pre[20][100005];
int str[100005];
bool bad[1<<20];
bool state[1<<20];
bool vis[1<<20];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		char c;
		cin >> c;
		str[i] = c-'a';
		pos[c-'a'].emplace_back(i);
		pre[c-'a'][i]++;
		for(int k = 0; k<K; k++){
			pre[k][i] += pre[k][i-1];
		}
	}
	for(int i = 0; i<K; i++){
		for(int j = 0; j<K; j++){
			cin >> mat[i][j];
		}
	}
	fill(state, state+(1<<K), 1);
	for(int i = 0; i<K; i++){
		for(int j = i; j<K; j++){
			if(mat[i][j]){
				continue;
			}
			fill(bad, bad+(1<<K), 0);
			vector<int> p;
			for(int n : pos[i]){
				p.emplace_back(n);
			}
			for(int n : pos[j]){
				p.emplace_back(n);
			}
			sort(p.begin(), p.end());
			p.erase(unique(p.begin(), p.end()), p.end());
			for(int k = 1; k<p.size(); k++){
				bool b1 = (str[p[k]] == i && str[p[k-1]] == j);
				bool b2 = (str[p[k]] == j && str[p[k-1]] == i);
				if(b1 || b2){
					int m = 0;
					for(int t = 0; t<K; t++){
						if(pre[t][p[k]-1] - pre[t][p[k-1]]){
							m |= (1<<t);
						}
					}
					//cout << m << "\n";
					bad[m] = 1;
				}
			}
			for(int m = 1; m<1<<K; m++){
				for(int k = 0; k<K; k++){
					if(m>>k&1){
						bad[m] |= bad[m^(1<<k)];
					}
				}
				//cout << i << " " << j << " " << (((1<<K)-1)^m|(1<<i)|(1<<j)) << "\n";
				state[((1<<K)-1)^m|(1<<i)|(1<<j)] &= !bad[m];
			}
		}
	}
	vis[(1<<K)-1] = 1;
	int ans = N;
	for(int m = (1<<K)-1; m>=0; m--){
		if(state[m]){
			//cout << m << "\n";
			int s = 0;
			for(int k = 0; k<K; k++){
				if(!(m>>k&1)){
					vis[m] |= vis[m^(1<<k)];
				}
				else{
					s += pos[k].size();
				}
			}
			if(vis[m]){
				ans = min(ans, s);
			}
		}
	}
	cout << ans << "\n";
}