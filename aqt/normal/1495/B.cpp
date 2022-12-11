
// Problem : B. Let's Go Hiking
// Contest : Codeforces - Codeforces Round #706 (Div. 1)
// URL : https://codeforces.com/contest/1495/problem/B
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
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	int idx = 1;
	int mx = 0;
	int cnt = 0;
	for(int i = 1; i<=N; i++){
		if(arr[i+1] - arr[i] < 0 && arr[i] - arr[i-1] > 0){
			int len = 1;
			for(int j = i+1; j<=N; j++){
				if(arr[j] < arr[j-1]){
					len++;
				}
				else{
					break;
				}
			}
			if(len > mx){
				mx = len;
				idx = i;
				cnt = 1;
			}
			else if(len == mx){
				cnt++;
			}
			len = 1;
			for(int j = i-1; j; j--){
				if(arr[j] < arr[j+1]){
					len++;
				}
				else{
					break;
				}
			}
			if(len > mx){
				mx = len;
				cnt = 1;
			}
			else if(len == mx){
				idx = i;
				cnt++;
			}
		}
	}
	int lft = 1, rht = 1;
	for(int j = idx+1; j<=N; j++){
		if(arr[j] < arr[j-1]){
			rht++;
		}
		else{
			break;
		}
	}
	for(int j = idx-1; j; j--){
		if(arr[j] < arr[j+1]){
			lft++;
		}
		else{
			break;
		}
	}
	if(cnt == 2){
		if(lft == mx && rht == mx){
			cout << mx%2;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0 << "\n";
	}
}