#include <bits/stdc++.h>

using namespace std;

int N, M;
string s;
int cnt[25][25];
int dp[1<<20];
int dist[1<<20];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> s;
	for(int i = 1; i<N; i++){
		cnt[s[i]-'a'][s[i-1]-'a']++;
		cnt[s[i-1]-'a'][s[i]-'a']++;
	}
	for(int m = 1; m<1<<M; m++){
		for(int k = 0; k<M; k++){
			if((m>>k)&1){
				dist[m] = dist[m^(1<<k)];
				for(int j = 0; j<M; j++){
					if(k != j){
						dist[m] += (((m>>j)&1) ? -cnt[k][j] : cnt[k][j]);
					}
				}
				break;
			}
		}
		dp[m] = INT_MAX;
		for(int k = 0; k<M; k++){
			if((m>>k)&1){
				dp[m] = min(dp[m^(1<<k)]+dist[m^(1<<k)], dp[m]);
			}
		}
	}
	cout << dp[(1<<M)-1] << endl;
}