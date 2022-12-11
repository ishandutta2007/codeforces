
// Problem : B. Arrays Sum
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[105];
int tot[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
			tot[i] = 0;
		}
		if(K== 1){
			set<int> st;
			for(int i = 1; i<=N; i++){
				st.insert(arr[i]);
			}
			if(st.size() == 1){
				cout << 1 << "\n";
			}
			else{
				cout << -1 << "\n";
			}
			continue;
		}
		int ans = -1;
		for(int t = 1; t<=N; t++){
			int crnt = -1;
			int cnt = 0;
			for(int i = 1; i<=N; i++){
				if(crnt != arr[i] - tot[i] && cnt < K){
					crnt = arr[i] - tot[i];
					cnt++;
				}
				tot[i] += crnt;
			}
			if(arr[N] == tot[N]){
				ans = t;
				break;
			}
		}
		cout << ans << "\n";
	}
}