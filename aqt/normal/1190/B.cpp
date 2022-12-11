
// Problem : B. Tokitsukaze, CSL and Stone Game
// Contest : Codeforces - Codeforces Round #573 (Div. 1)
// URL : https://codeforces.com/contest/1190/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i= 0; i<N; i++){
		cin >> arr[i];
	}
	sort(arr, arr+N);
	long long sum = 0;
	for(int i = 1; i<N; i++){
		if(arr[i] == arr[i-1]){
			if(arr[i-1] && !sum){
				sum++;
				arr[i-1]--;
			}
			else{
				cout << "cslnb\n";
				return 0;
			}
		}
	}
	for(int i = 1; i<N; i++){
		if(arr[i] == arr[i-1]){
			cout << "cslnb\n";
			return 0;
		}
	}
	for(int i = 0; i<N; i++){
		sum += arr[i] - i; 
	}
	cout << (sum%2^1 ? "cslnb" : "sjfnb");
}