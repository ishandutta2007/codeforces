
// Problem : A. Balanced Bitstring
// Contest : Codeforces - Codeforces Round #668 (Div. 1)
// URL : https://codeforces.com/contest/1404/problem/A
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
		int N, K;
		cin >> N >> K;
		vector<int> typ(K, -1);
		string s;
		cin >> s;
		bool good = 1;
		for(int i = 0; i<N; i++){
			if(s[i] == '0'){
				if(typ[i%K] == 1){
					good = 0;
				}
				typ[i%K] = 0;
			}
			else if(s[i] == '1'){
				if(typ[i%K] == 0){
					good = 0;
				}
				typ[i%K] = 1;
			}
		}
		int free = 0, cnt = 0;
		for(int i = 0; i<K; i++){
			if(typ[i] == -1){
				free++;
			}
			else{
				cnt += 2*typ[i] - 1;
			}
		}
		good &= (abs(cnt) <= free);
		if(good){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}