
// Problem : B. Chess Cheater
// Contest : Codeforces - Codeforces Global Round 11
// URL : https://codeforces.com/contest/1427/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
//bitset<100005> dp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		string s;
		cin >> s;
		int cnt = -1e6, tot = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;		
		for(int i = 0; i<N; i++){
			if(s[i] == 'L'){
				cnt++;
				tot++;
			}
			else{
				if(cnt > 0){
					pq.push(make_pair(cnt, i-cnt));
				}
				cnt = 0;
			}
		}
		if(tot == N){
			cout << max(0, 2*K-1) << "\n";
			continue;
		}
		while(pq.size() && K){
			auto p = pq.top();
			pq.pop();
			if(K >= p.first){
				K -= p.first;
				for(int n = p.second; n<p.second+p.first; n++){
					s[n] = 'W';
				}
			}
			else{
				break;
			}
		}
		for(int i = N-1; i>=0 && K; i--){
			if(s[i] == 'W'){
				for(int j = i+1; j<N && K; j++){
					if(s[j] == 'W'){
						break;
					}
					else{
						s[j] = 'W';
						K--;
					}
				}
			}
		}
		for(int i = 0; i<N && K; i++){
			if(s[i] == 'W'){
				for(int j = i-1; j>=0 && K; j--){
					if(s[j] == 'W'){
						break;
					}
					else{
						s[j] = 'W';
						K--;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i<N; i++){
			if(s[i] == 'W'){
				if(!i || s[i-1] == 'L'){
					ans++;
				}
				else{
					ans += 2;
				}
			}
		}
		cout << ans << "\n";
		/*
		int tot = 0;
		for(char c : s){
			tot += c == 'L';
		}
		if(tot <= K){
			cout << 2*N-1 << "\n";
			continue;
		}
		else if(tot == N){
			cout << 2*K-1 << "\n";
			continue;
		}
		dp[0] = 1;
		int cnt = -10000000;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for(int i = 0; i<N; i++){
			if(s[i] == 'W'){
				if(cnt > 0){
					//dp[i] |= (dp[i]<<cnt);
					pq.push(make_pair(cnt, i));
				}
				cnt = 0;
			}
			else{
				cnt++;
			}
		}
		for(int i = 0; i<=N;i ++){
			dp[i] = 0;
		}
		while(pq.size() && K){
			auto n = pq.top();
			pq.pop();
			if(K >= n.first){
				K -= n.first;
				for(int i = n.second; i<n.second+n.first; i++){
					s[i] = 'W';
				}
			}
			else{
				break;
			}
		}
		for(int i = 0; i<N; i++){
			if(s[i] == 'W'){
				
			}
		}
		*/
	}
}