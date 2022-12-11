
// Problem : C. Omkar and Waterslide
// Contest : Codeforces - Codeforces Global Round 10
// URL : https://codeforces.com/contest/1392/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		long long ans = 0, cnt = 0;
		int lst = 0;
		for(int i = 1; i<=N; i++){
			if(arr[i] > lst){
				lst = arr[i];
				cnt = 0;
			}
			else{
				long long crnt = lst - arr[i];
				if(crnt > cnt){
					ans += crnt - cnt;
					cnt = crnt;
				}
				else{
					cnt = crnt;
				}
			}
		}
		cout << ans << "\n";
	}
}