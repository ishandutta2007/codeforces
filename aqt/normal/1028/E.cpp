
// Problem : E. Restore Array
// Contest : Codeforces - AIM Tech Round 5 (rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1028/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[150000];
long long ans[150000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i<N; i++){
		cin >> arr[i];
	}
	int mx = *max_element(arr, arr+N);
	int mn = *min_element(arr, arr+N);
	if(mx == 0){
		for(int i = 0; i<N; i++){
			ans[i] = 1;
		}
	}
	else if(mn == mx){
		cout << "NO\n";
		return 0;
	}
	else{
		int s = 0;
		for(int i = 0; i<N; i++){
			if(arr[i] == mx && arr[i] != arr[(i+N-1)%N]){
				s = i;
			}
		}
		ans[s] = mx;
		for(int i = s-1; i>=0; i--){
			ans[i] = ans[i+1] + arr[i];
			if((i+1)%N == s){
				ans[i] = 2*arr[s]*arr[s] + arr[i];
			}
		}
		for(int i = N-1; i>s; i--){
			ans[i] = ans[(i+1)%N] + arr[i];
			if((i+1)%N == s){
				ans[i] = 2*arr[s]*arr[s] + arr[i];
			}
		}
		if(ans[s] == ans[(s+1)%N]){
			ans[(s+1)%N] *= 2;
		}
	}
	cout << "YES\n";
	for(int i = 0; i<N; i++){
		cout << ans[i] << " ";
	}
}