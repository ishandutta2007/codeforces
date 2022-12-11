
// Problem : C. Superior Periodic Subarrays
// Contest : Codeforces - Codeforces Round #323 (Div. 1)
// URL : https://codeforces.com/contest/582/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
vector<int> v[200005];
int mx[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i<N; i++){
		cin >> arr[i];
	}
	for(int i= 1; i<N; i++){
		v[__gcd(i, N)].emplace_back(i);
	}
	long long ans = 0;
	for(int n = 1; n<N; n++){
		if(v[n].size()){
			fill(mx, mx+n, 0);
			for(int i = 0; i<N; i++){
				mx[i%n] = max(mx[i%n], arr[i]);
			}
			int cnt = 0;
			for(int i = N-1; i>=0 && arr[i] == mx[i%n]; i--){
				cnt++;
			}
			for(int i = 0; i<N; i++){
				if(arr[i] == mx[i%n]){
					cnt++;
					ans += upper_bound(v[n].begin(), v[n].end(), cnt) - v[n].begin();
				}
				else{
					cnt = 0;
				}
			}
		}
	}
	cout << ans << "\n";
}