
// Problem : E. Sum of Digits
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1373/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long N, K;
		cin >> N >> K;
		if(K*(K+1)/2 == N){
			cout << 0 << "\n";
			continue;
		}
		string ans = "99999999999999999999999999999999999999";
		for(int len = 0; len <= 20; len++){
			for(int m = 0; m<10; m++){
				//cout << len << " " << m << "\n";
				int tot = 0;
				for(int l = m; l <= m+K; l++){
					tot += l%10;
					tot += l>=10;
					if(l < 10){
						tot += len*9;
					}
				}
				string pre = "";
				if(tot > N || (N-tot)%(K+1)){
					continue;
				}
				bool start = (m+K>=10);
				long long T = (N-tot)/(K+1);
				while(T){
					for(int d = 9-start; d; d--){
						if(T-d >= 0){
							pre = to_string(d) + pre;
							T -= d;
							break;
						}
					}
					start = 0;
				}
				for(int l = 0; l<len; l++){
					pre.push_back('9');
				}
				pre += to_string(m);
				if(ans.size() > pre.size()){
					ans = pre;
				}
				else if(ans.size() == pre.size()){
					for(int i = 0; i<pre.size(); i++){
						if(ans[i] < pre[i]){
							break;
						}
						else if(ans[i] > pre[i]){
							ans = pre;
							break;
						}
					}
				}
			}
		}
		if(ans == "99999999999999999999999999999999999999"){
			cout << -1 << "\n";
		}
		else{
			cout << ans << "\n";
		}
	}
}