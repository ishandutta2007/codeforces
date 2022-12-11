
// Problem : A. XXXXX
// Contest : Codeforces - Codeforces Round #649 (Div. 2)
// URL : https://codeforces.com/contest/1364/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long pre[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		pair<int, int> mx = {0, -1};
		int ans = -1;
		for(int i =1 ; i<=N; i++){
			int n;
			cin >> n;
			pre[i] = n + pre[i-1];
			pre[i] %= K;
			if(pre[mx.first] != pre[i]){
				ans = max(ans, i - mx.first);
				if(mx.second == -1){
					mx.second = i;
				}
			}
			else{
				if(mx.second != -1){
					ans = max(ans, i - mx.second);
				}
			}
		}
		cout << ans << "\n";
	}
}