
// Problem : E. Make It Increasing
// Contest : Codeforces - Educational Codeforces Round 97 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1437/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[500005];
int brr[500005];
const int oo = INT_MAX/2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	arr[0] = -oo;
	arr[N+1] = oo;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		arr[i] -= i;
	}
	for(int i = 1; i<=K; i++){
		cin >> brr[i];
	}
	brr[K+1] = N+1;
	int ans = N - K;
	for(int i = 1; i<=K+1; i++){
		if(arr[brr[i-1]] > arr[brr[i]]){
			cout << -1;
			return 0;
		}
		vector<int> lis;
		for(int l = brr[i-1] + 1; l < brr[i]; l++){
			if(arr[l] < arr[brr[i-1]] || arr[l] > arr[brr[i]]){
				continue;
			}
			auto ptr = upper_bound(lis.begin(), lis.end(), arr[l]);
			if(ptr == lis.end()){
				lis.emplace_back(arr[l]);
				ans--;
			}
			else{
				*ptr = arr[l];
			}
		}
	}
	cout << ans;
}