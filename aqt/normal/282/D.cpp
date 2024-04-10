
// Problem : D. Yet Another Number Game
// Contest : Codeforces - Codeforces Round #173 (Div. 2)
// URL : https://codeforces.com/contest/282/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M = 300;
bool dp[305][305][305];
bool dif[305][305];
bool o2[305][305];
bool dp2[305][305];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i<=M; i++){
		for(int j = i; j<=M; j++){
			for(int k = j; k<=M; k++){
				//cout << i << " " << j << " " << k << endl;
				if(!o2[i][j] && !o2[j][k] && !o2[i][k] && !dif[j-i][k-i]){
					o2[i][j] = 1;
					o2[j][k] = 1;
					o2[i][k] = 1;
					dif[j-i][k-i] = 1;
					dp[i][j][k] = 0;
				}
				else{
					dp[i][j][k] = 1;
				}
				//cout << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
			} 
		}
	}
	for(int i = 0; i<=M; i++){
		for(int j = i; j<=M; j++){
			for(int k = 0; k<=i; k++){
				if(!dp2[k][j] && k != i){
					dp2[i][j] = 1;
					break;
				}
				if(!dp2[i-k][j-k] && k){
					dp2[i][j] = 1;
					break;
				}
			}
			for(int k = 0; k<j; k++){
				if(!dp2[min(i, k)][max(i, k)]){
					dp2[i][j] =1;
					break;
				}
			}
			//cout << i << " " << j << " " << dp2[i][j] << "\n";
		}
	}
	vector<int> v;
	cin >> N;
	if(N == 1){
		int n;
		cin >> n;
		cout << (n ? "BitLGM" : "BitAryo");
		return 0;
	}
	while(N--){
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	if(v.size() == 2){
		cout << (dp2[v[0]][v[1]] ? "BitLGM" : "BitAryo");
	}
	else{
		cout << (dp[v[0]][v[1]][v[2]] ? "BitLGM" : "BitAryo");
	}
}