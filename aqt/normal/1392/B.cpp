
// Problem : B. Omkar and Infinity Clock
// Contest : Codeforces - Codeforces Global Round 10
// URL : https://codeforces.com/contest/1392/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
long long K;
int arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> K;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		int mn = *min_element(arr+1, arr+1+N);
		int mx = *max_element(arr+1, arr+1+N);
		if(K%2 == 1){
			for(int i = 1; i<=N; i++){
				arr[i] = mx - arr[i];
			}
		}
		else{
			for(int i =1 ; i<=N; i++){
				arr[i] = arr[i] - mn;
			}
		}
		for(int i = 1; i<=N; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}