
// Problem : B. GameGame
// Contest : Codeforces - Codeforces Round #659 (Div. 1)
// URL : https://codeforces.com/contest/1383/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int cnt[40];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int b = 0; b<30; b++){
			cnt[b] = 0;
		}
		for(int n = 1; n<=N; n++){
			int x;
			cin >> x;
			for(int b = 0; b<30; b++){
				if(x>>b&1){
					cnt[b]++;
				}
			}
		}
		bool draw = 1;
		for(int b = 29; b>=0; b--){
			if(cnt[b]%2 == 1){
				if(cnt[b]%4 == 1){
					cout << "WIN\n";
					draw = 0;
					break;
				}
				else if((N-3)%2 == 1){
					cout << "WIN\n";
					draw = 0;
					break;
				}
				else{
					cout << "LOSE\n";
					draw = 0;
					break;
				}
			}
		}
		if(draw){
			cout << "DRAW\n";
		}
	}
}