
// Problem : B. Princesses and Princes
// Contest : Educational Codeforces Round 84 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1327/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100005];
bool tkn[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		queue<int> qu;
		fill(tkn+1, tkn+1+N, 0);
		for(int i = 1; i<=N; i++){
			int K;
			cin >> K;
			graph[i].clear();
			bool good = 0;
			while(K--){
				int n;
				cin >> n;
				if(!tkn[n] && !good){
					tkn[n] = 1;
					good = 1;
				}
			}
			if(!good){
				qu.push(i);
			}
		}
		if(qu.size()){
			cout << "IMPROVE\n";
		}
		else{
			cout << "OPTIMAL\n";
		}
		for(int n =1 ; n<=N; n++){
			if(!tkn[n]){
				cout << qu.front() << " " << n << "\n";
				break;
			}
		}
	}	
}