
// Problem : B. Scenes From a Memory
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
		bool found = 0;
		for(int i = 0; i < N; i++){
			if(s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7'){
				
			}
			else{
				cout << 1 << "\n";
				cout << s[i] << "\n";
				found = 1;
				break;
			}
		}
		if(found){
			continue;
		}
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				int n = (s[i] - '0') * 10 + s[j] - '0';
				bool isprime = 1;
				for(int k = 2; k < n; k++){
					if(n%k == 0){
						isprime = 0;
					}
				}
				if(!found && !isprime){
					cout << 2 << "\n";
					cout << s[i] << s[j] << "\n";
					found = 1;
				}
			}
		}
	}
}