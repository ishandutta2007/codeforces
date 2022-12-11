
// Problem : D. Challenges in school 41
// Contest : Codeforces Round #632 (Div. 2)
// URL : https://codeforces.com/contest/1333/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize ("O3") 
#pragma GCC target ("sse4")

int N, K;
bool arr[3005];
vector<short> mn[3005];
short ans[3000005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		char c;
		cin >> c;
		if(c == 'R'){
			arr[i] = 1;
		}
	}
	int lst = 0, cnt = 0;
	for(int t = 1; t<=N; t++){
		for(int i = 1; i<N; i++){
			if(arr[i] && !arr[i+1]){
				lst = t;
				mn[t].emplace_back(i);
				cnt++;
			}	
		}
		for(int n : mn[t]){
			arr[n] = 0;
			arr[n+1] = 1;
		}
	}
	if(cnt < K || lst > K){
		cout << -1 << "\n";
		return 0;
	}
	int tempK = K;
	while(lst < K){
		if(mn[lst].size() == 1){
			if(K > 3000){
				ans[K] = mn[lst].back();
			}
			else{
				mn[K].emplace_back(mn[lst].back());
			}
			mn[lst].pop_back();
			K--;
			lst--;
			continue;
		}
		if(K > 3000){
			ans[K] = mn[lst].back();
		}
		else{
			mn[K].emplace_back(mn[lst].back());
		}
		mn[lst].pop_back();
		K--;
	}
	for(int k = 1; k<=tempK; k++){
		if(k <= 3000){
			cout << mn[k].size() << " ";
			for(int n : mn[k]){
				cout << n << " ";
			}
		}
		else{
			cout << 1 << " " << ans[k] << "\n";
		}
		cout << "\n";
	}
}