
// Problem : B. Kind Anton
// Contest : Codeforces Round #632 (Div. 2)
// URL : https://codeforces.com/contest/1333/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[100005];
int brr[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		int fstp = N+1, fstn = N+1;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			if(arr[i] == 1){
				fstp = min(fstp, i);
			}
			else if(arr[i] == -1){
				fstn = min(fstn, i);
			}
		}
		bool b = 1;
		for(int i = 1; i<=N; i++){
			cin >> brr[i];
			if(brr[i] - arr[i] > 0 && fstp >= i){
				b = 0;
			}
			if(brr[i] - arr[i] < 0 && fstn >= i){
				b = 0;
			}
		}
		if(b){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}