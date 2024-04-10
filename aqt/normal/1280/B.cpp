
// Problem : B. Beingawesomeism
// Contest : Codeforces - Codeforces Round #607 (Div. 1)
// URL : https://codeforces.com/contest/1280/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
char mp[65][65];
int solve(){
	int N, M;
	cin >> N >> M;
	bool allA = 1, allP = 1;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cin >> mp[i][j];
			allA &= (mp[i][j] == 'A');
			allP &= (mp[i][j] == 'P');
		}
	}
	if(allA){
		return 0;
	}
	if(allP){
		return -1;
	}
	int ans = 4;
	for(int i = 1; i<=N; i++){
		bool b = 1;
		for(int j = 1; j<=M; j++){
			if(mp[i][j] == 'P'){
				b = 0;
			}
		}
		if(b){
			ans = min(ans, (i != 1) + (i != N));
		}
	}
	for(int j = 1; j<=M; j++){
		bool b = 1;
		for(int i = 1; i<=N; i++){
			if(mp[i][j] == 'P'){
				b = 0;
			}
		}
		if(b){
			ans = min(ans, (j != 1) + (j != M));
		}
	}
	for(int i = 1; i<=N; i++){
		if(mp[i][1] == 'A' || mp[i][M] == 'A'){
			ans = min(ans, 3);
		}
	}
	for(int j = 1; j<=M; j++){
		if(mp[1][j] == 'A' || mp[N][j] == 'A'){
			ans = min(ans, 3);
		}
	}
	if(mp[1][1] == 'A'){
		ans = min(ans, 2);
	}
	if(mp[1][M] == 'A'){
		ans = min(ans, 2);
	}
	if(mp[N][1] == 'A'){
		ans = min(ans, 2);
	}
	if(mp[N][M] == 'A'){
		ans = min(ans, 2);
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int n = solve();
		cout << (n == -1 ? "MORTAL" : to_string(n)) << "\n";	
	}
}