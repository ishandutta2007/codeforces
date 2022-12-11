
// Problem : C. Mocha and Hiking
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int arr[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i <= N; i++){
			cin >> arr[i];
		}
		if(arr[1] == 1){
			cout << (N+1) << " ";
			for(int i = 1; i <= N; i++){
				cout << i << " ";
			}
		}
		else if(arr[N] == 0){
			for(int i = 1; i <= N; i++){
				cout << i << " ";
			}
			cout << (N+1);			
		}
		else{
			bool good = 0;
			for(int i = 1; i <= N; i++){
				cout << i << " ";
				if(!good && arr[i] == 0 && arr[i+1] == 1){
					cout << (N+1) << " ";
					good = 1;
				}
			}
		}
		cout << "\n";
	}
}