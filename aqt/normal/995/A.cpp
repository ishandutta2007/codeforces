
// Problem : A. Tesla
// Contest : Codeforces - Codeforces Round #492 (Div. 1) [Thanks, uDebug!]
// URL : https://codeforces.com/problemset/problem/995/A
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int res[2][55];
int mp[2][55];
int x[2][55], y[2][55];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> res[0][i];
	}
	for(int i = 1; i<=N; i++){
		cin >> mp[0][i];
		if(i+1 <= N){
			x[0][i] = 0;
			y[0][i] = i+1;
		}
		else{
			x[0][i] = 1;
			y[0][i] = N;
		}
	}
	for(int i = 1; i<=N; i++){
		cin >> mp[1][i];
		if(i-1 > 0){
			x[1][i] = 1;
			y[1][i] = i-1;
		}
		else{
			x[1][i] = 0;
			y[1][i] = 1;
		}
	}
	for(int i = 1; i<=N; i++){
		cin >> res[1][i];
	}
	int done = 0;
	vector<pair<int, pair<int, int>>> out;
	while(done < K){
		bool change = 0;
		for(int k = 0; k<2; k++){
			for(int n = 1; n<=N; n++){
				if(mp[k][n]){
					if(res[k][n] == mp[k][n]){
						if(!k){
							out.push_back(make_pair(mp[k][n], make_pair(1, n)));
						}
						else{
							out.push_back(make_pair(mp[k][n], make_pair(4, n)));
						}
						mp[k][n] = 0;
						done++;
						change = 1;
					}
					else if(!mp[x[k][n]][y[k][n]]){
						out.push_back(make_pair(mp[k][n], make_pair(x[k][n]+2, y[k][n])));
						mp[x[k][n]][y[k][n]] = mp[k][n];
						mp[k][n] = 0;
						change = 1;
					}
				}
			}
		}
		if(!change){
			break;
		}
	}
	if(done < K){
		cout << -1 << "\n";
		return 0;
	}
	cout << out.size() << "\n";
	for(auto p : out){
		cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
	}
}