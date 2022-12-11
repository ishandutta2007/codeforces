
// Problem : C. Omkar and Baseball
// Contest : Codeforces - Codeforces Round #655 (Div. 2)
// URL : https://codeforces.com/contest/1372/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int cnt = 0;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			cnt += (arr[i] == i);
		}
		int pre = 0;
		for(int i = 1; i<=N; i++){
			pre += (arr[i] == i);
			if(arr[i] != i){
				break;
			}
		}
		int suf = 0;
		for(int i = N; i; i--){
			suf += (arr[i] == i);
			if(arr[i] != i){
				break;
			}
		}
		if(cnt == N){
			cout << 0 << "\n";
		}
		else if(pre+suf == cnt){
			cout << 1 << "\n";
		}
		else if(cnt){
			cout << 2 << "\n";
		}
		else{
			assert(0);
		}
		/*
		int cntinorder = 0;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			cntinorder += (n == i);
		}
		if(cntinorder == N){
			cout << 0 << "\n";
		}
		else if(cntinorder){
			cout << 2 << "\n";
		}
		else{
			cout << 1 << "\n";
		}
		*/
	}
}