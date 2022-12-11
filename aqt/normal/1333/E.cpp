
// Problem : E. Road to 1600
// Contest : Codeforces Round #632 (Div. 2)
// URL : https://codeforces.com/contest/1333/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[505][505];

/*
Sol for 3 by 3
1 8 7
2 4 3
6 5 9
From: Eric Pei 
My ass is open for you anytime baby <3. 
*/

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	if(N <= 2){
		cout << -1 << "\n";
		return 0;
	}
	int cntr = 0;
	for(int i = 1; i<=N-3; i++){
		int k = N - i + 1;
		if(i%2 == 1){
			for(int x = 1; x<=k; x++){
				arr[x][k] = ++cntr;
			}
			for(int x = k-1; x>0; x--){
				arr[k][x] = ++cntr;
			}
		}
		else{
			for(int x = 1; x<=k; x++){
				arr[k][x] = ++cntr;
			}
			for(int x = k-1; x>0; x--){
				arr[x][k] = ++cntr;
			}
		}		
	}
	arr[1][3] = 1;
	arr[2][3] = 8;
	arr[3][3] = 7;
	arr[1][2] = 2;
	arr[2][2] = 4;
	arr[3][2] = 3;
	arr[1][1] = 6;
	arr[2][1] = 5;
	arr[3][1] = 9;
	for(int i = 1; i<=3; i++){
		for(int j = 1; j<=3; j++){
			arr[i][j] += cntr;
		}
	}
	if(N%2 == 0){
		swap(arr[1][3], arr[3][1]);
		swap(arr[2][3], arr[3][2]);
		swap(arr[1][2], arr[2][1]);
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}