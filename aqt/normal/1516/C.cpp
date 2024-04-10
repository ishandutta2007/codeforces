
// Problem : C. Baby Ehab Partitions Again
// Contest : Codeforces - Codeforces Round #717 (Div. 2)
// URL : https://codeforces.com/contest/1516/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[2005];
bool dp[4000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int g = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		g = __gcd(arr[i], g);
	}
	int T = 0;
	for(int i= 1; i<=N; i++){
		arr[i] /= g;
		T += arr[i];
	}
	dp[0] = 1;
	for(int i = 1; i<=N; i++){
		for(int j = 2000*i; j>=arr[i]; j--){
			dp[j] |= dp[j-arr[i]];
		}
	}
	if(T%2 == 0 && dp[T/2]){
		for(int i = 1; i<=N; i++){
			if(arr[i]%2){
				cout << 1 << "\n";
				cout << i << "\n";
				return 0;
			}
		}
	}
	else{
		cout << 0 << "\n";
	}
}