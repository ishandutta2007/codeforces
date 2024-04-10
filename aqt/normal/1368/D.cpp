
// Problem : D. AND, OR and square sum
// Contest : Codeforces - Codeforces Global Round 8
// URL : https://codeforces.com/contest/1368/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[30][200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		for(int b = 0; b<20; b++){
			if(n>>b&1){
				cnt[b][i]++;
			}
		}
	}
	for(int b = 0; b<20; b++){
		sort(cnt[b]+1, cnt[b]+N+1);
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		long long k = 0;
		for(int b = 0; b<20; b++){
			if(cnt[b][i]){
				k += (1<<b);
			}
		}
		ans += k*k;
	}
	cout << ans << "\n";
}