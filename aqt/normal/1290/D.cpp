
// Problem : F. Coffee Varieties (easy version)
// Contest : Codeforces - Codeforces Round #616 (Div. 2)
// URL : https://codeforces.com/contest/1291/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, B;
int arr[2000];

char query(int n){
	cout << "? " << (n + 1) << endl;
	char c;
	cin >> c;
	if(c == 'Y'){
		arr[n] = 0;
	}
	return c;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	fill(arr, arr+N, 1);
	if(K == 1){
		for(int i = 0 ; i < N; i++){
			for(int j = i+1; j < N; j++){
				query(i);	
				query(j);
				cout << "R" << endl;
			}
		}
	}
	else{
		B = 2 * N / K;
		for(int t = 1; t < B; t++){
			for(int s = 0; s < t; s++){
				if(s + t >= B){
					break;
				}
				for(int i = s; i < B; i += t){
					for(int k = i * K / 2; k < (i + 1) * K / 2; k++){
						query(k);
					}
				}
				cout << "R" << endl;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < N; i++){
		cnt += arr[i];
	}
	cout << "! " << cnt << endl;
}