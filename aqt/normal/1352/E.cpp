
// Problem : E. Special Elements
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/E
// Memory Limit : 64 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[8005];
int pre[8005];
bool cnt[8000*8000+5];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		partial_sum(arr, arr+1+N, pre);
		for(int i = 1; i<=N; i++){
			for(int j = i+1; j<=N; j++){
				cnt[pre[j]-pre[i-1]] = 1;
			}
		}
		int ans = 0;
		for(int i = 1; i<=N; i++){
			if(cnt[arr[i]]){
				ans++;
			}
		}
		cout << ans << "\n";
		fill(cnt+1, cnt+1+N*N, 0);
	}
}