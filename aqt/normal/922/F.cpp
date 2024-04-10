
// Problem : F. Divisibility
// Contest : Codeforces - Codeforces Round #461 (Div. 2)
// URL : https://codeforces.com/problemset/problem/922/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int cnt[300005];
bool tkn[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int tot = 0;
	vector<int> ans;
	for(int i = 1; i<=N; i++){
		if(cnt[i] + tot <= K){
			tot += cnt[i];
			for(int j = i; j<=N; j+=i){
				cnt[j]++;
			}
			ans.push_back(i);
		}
	}
	if(tot != K){
		ans.clear();
		fill(cnt, cnt+1+N, 0);
		tot = 0;
		for(int i = 1; i<=N; i++){
			for(int j = 2*i; j<=N; j+=i){
				tot++;
				cnt[j]++;
			}			
			tkn[i] = 1;
		}
		if(tot < K){
			cout << "No\n";
			return 0;
		}
		for(int i = N; i; i--){
			int d = cnt[i];
			for(int j = 2*i; j<=N; j+=i){
				d += tkn[j];
			}
			if(tot - d >= K){
				tot -= d;
				tkn[i] = 0;
			}
		}
		for(int i= 1; i<=N; i++){
			if(tkn[i]) {
				ans.push_back(i);	
			}
		}
		if(tot != K){
			ans.clear();
			assert(N <= 20);
			for(int m = 2; m<(1<<(N+1)); m+=2){
				tot = 0;
				for(int i = 1; i<=N; i++){
					if(m>>i&1){
						for(int j = 2*i; j<=N; j+=i){
							if(m>>j&1){
								tot++;
							}
						}
					}
				}
				if(tot == K){
					for(int i = 1; i<=N; i++){
						if(m>>i&1){
							ans.push_back(i);
						}
					}
					break;
				}
			}
		}
	}
	assert(tot == K);
	cout << "Yes\n";
	cout << ans.size() << "\n";
	for(int n : ans){
		cout << n << " ";
	}
}