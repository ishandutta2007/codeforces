
// Problem : B. Infinite Prefixes
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int pre[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, X;
		cin >> N >> X;
		string s;
		cin >> s;		
		for(int i = 0; i<N; i++){
			if(s[i] == '1'){
				pre[i+1] = -1;
			}
			else{
				pre[i+1] = 1;
			}
			pre[i+1] += pre[i];
		}
		int M = pre[N];
		if(M == 0){
			int cnt = 0;
			for(int i = 0; i<=N; i++){
				cnt += pre[i] == X;
			}			
			if(cnt){
				cout << -1 << "\n";
			}
			else{
				cout << 0 << "\n";
			}
			
		}
		else{
		int cnt = 0;
		if(M > 0){
			for(int i = 1; i<=N; i++){
				if((pre[i]%M+M)%M == (X%M+M)%M){
					cnt += pre[i] <= X;
				}
			}
		}
		else{
			M*= -1;
			for(int i = 1; i<=N; i++){
				if((pre[i]%M+M)%M == (X%M+M)%M){
					cnt += pre[i] >= X;
				}
			}
		}
		cout << cnt+(X==0) << "\n";
		}
	}
}