
// Problem : D. Infinite Path
// Contest : Educational Codeforces Round 84 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1327/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int nxt[200005];
int clr[200005];
bool tkn[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		int ans = N+1;
		fill(tkn+1, tkn+1+N, 0);
		for(int i = 1; i<=N; i++){
			cin >> nxt[i];
		}
		for(int i =1 ; i<=N; i++){
			cin >> clr[i];
		}
		for(int i = 1; i<=N; i++){
			if(!tkn[i]){
				int crnt = i;
				int len = 0;
				vector<int> v;
				do{
					v.emplace_back(crnt);
					tkn[crnt] = 1;
					len++;
					crnt = nxt[crnt];
					//cout << crnt << endl;
				}
				while(crnt != i);
				/*
				for(int n : v){
					cout << n << " ";
				}
				cout << "\n";
				*/
				for(int k = 1; k<=len; k++){
					if(len%k == 0){
						bool exist = 0;
						for(int j = 0; j<k; j++){
							bool good = 1;
							for(int n = j; n<len; n+=k){
								if(clr[v[j]] != clr[v[n]]){
									good = 0;
								}
							}
							if(good){
								exist = 1;
							}
						}
						if(exist){
							ans = min(ans, k);
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
}