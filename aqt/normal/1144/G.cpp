
// Problem : G. Two Merged Sequences
// Contest : Codeforces - Codeforces Round #550 (Div. 3)
// URL : https://codeforces.com/contest/1144/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
bool ans[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	int dec = INT_MAX/2, inc = INT_MIN/2;
	for(int i = 1; i <= N; i++){
		if(arr[i] < arr[i+1]){
			if(inc < arr[i]){
				inc = arr[i];
			}
			else if(dec > arr[i]){
				dec = arr[i];
				ans[i] = 1;
			}
			else{
				cout << "NO\n";
				return 0;
			}
		}
		else{
			if(dec > arr[i]){
				dec = arr[i];
				ans[i] = 1;
			}
			else if(inc < arr[i]){
				inc = arr[i];
			}
			else{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for(int i = 1; i<=N; i++){
		cout << ans[i] << " ";
	}
}