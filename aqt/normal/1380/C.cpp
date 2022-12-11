
// Problem : Create The Teams
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1380/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, X;
		cin >> N >> X;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		sort(arr+1, arr+1+N);
		long long cnt = 0, ans = 0;
		for(int i = N; i; i--){
			cnt++;
			if(arr[i]*cnt >= X){
				cnt = 0;
				ans++;
			}
		}
		cout << ans << "\n";
	}
}