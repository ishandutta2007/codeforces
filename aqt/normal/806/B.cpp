#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
// Problem : B. Dynamic Problem Scoring
// Contest : Codeforces - Codeforces Round #412 (rated, Div. 1, based on VK Cup 2017 Round 3)
// URL : https://codeforces.com/contest/806/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2][5];
int cnt[5];
long long t;

inline bool rec(int n){
	if(n == 5){
		long long tot = 0;
		for(int i = 0; i<5; i++){
			long long c = 0;
			for(int k = 0; k<=5; k++){
				if((1<<k)*cnt[i] <= t){
					c += 2;
				}
				else{
					break;
				}
			}
			if(arr[0][i]+1){
				tot += 250*c-c*arr[0][i];
			}
			if(arr[1][i]+1){
				tot -= 250*c-c*arr[1][i];
			}
		}
		return tot > 0;
	}
	if(arr[0][n] == -1){
		return rec(n+1);
	}
	bool done0 = 0;
	for(int k = 0; k<=5; k++){
		if((t>>k)>=cnt[n]){
			if((t>>k)-cnt[n] <= t-N){
				int lst = cnt[n];
				cnt[n] = (t>>k);
				//rec(n+1,t);
				if(rec(n+1)){
					cnt[n] = lst;
					return 1;
				}
				cnt[n] = lst;	
			}
			else if((t>>(k+1))+1 >= cnt[n] && (t>>(k+1))+1-cnt[n] <= t-N){
				int lst = cnt[n];
				cnt[n] = (t>>(k+1))+1;
				if(rec(n+1)){
					cnt[n] = lst;
					return 1;
				}
				cnt[n] = lst;
			}
			else if(!done0){
				if(rec(n+1)){
					return 1;
				}
				done0 = 1;				
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<5; j++){
			int n;
			cin >> n;
			if(i <= 1){
				arr[i][j] = n;
			}
			if(1+n){
				cnt[j]++;
			}
		}
	}
	int ans = -1;
	for(int a = 4000; a>=0; a--){
		t = a+N;
		if(rec(0)){
			ans = a;
		}
	}
	cout << ans;
}