
// Problem : C. Dominant Character
// Contest : Codeforces - Codeforces Round #754 (Div. 2)
// URL : https://codeforces.com/contest/1605/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		string s;
		cin >> s;
		int ans = INT_MAX;
		for(int i = 0; i < N; i++){
			int cntb = 0;
			int cntc = 0;
			for(int j = 0; j < 30 && j + i < N; j++){
				if(s[j+i] == 'a'){
					cntb++;
					cntc++;
				}
				else if(s[j+i] == 'b'){
					cntb--;
				}
				else{
					cntc--;
				}
				if(cntb >= 1 && cntc >= 1 && j >= 1){
					ans = min(ans, j + 1);
				}
			}
		}
		if(ans == INT_MAX){
			ans = -1;
		}
		cout << ans << "\n";
	}
}