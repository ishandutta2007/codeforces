
// Problem : B. Codeforces Subsequences
// Contest : Codeforces - Codeforces Global Round 8
// URL : https://codeforces.com/contest/1368/problem/B
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long K;
//long long dp[1005][1005];
int cnt[100];
string cf = "codeforces";

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> K;
	fill(cnt, cnt+10, 1);
	long long tot = 1;
	while(tot < K){
		int k = min_element(cnt, cnt+10) - cnt;
		cnt[k]++;
		tot = 1;
		for(int i = 0; i<10; i++){
			tot *= cnt[i];
		}
	}
	for(int i =0 ; i<10; i++){
		while(cnt[i]--){
			cout << cf[i];
		}
	}
}