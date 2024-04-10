#include <bits/stdc++.h>

using namespace std;

int T;
int N, K;
int dist[1005];
int dp[2000000];
int brr[1005];
int crr[1005];

int main() {
	cin >> T;
	fill(dist+1, dist+1+1000, INT_MAX/2);
	dist[1] = 0;
	queue<int> qu;
	qu.push(1);
	while(qu.size()) {
		int n = qu.front();
		qu.pop();
		for(int x = 1; x <= n; x++) {
			if(n + n/x <= 1000 && dist[n+n/x] > dist[n] + 1) {
				dist[n+n/x] = dist[n] + 1;
				qu.push(n+n/x);
			}
		}
	}
	int lim = *(max_element(dist+1, dist+1+1000));
	while(T--) {
		cin >> N >> K;
		K = min(lim * N, K);
		for(int i = 1; i <= N; i++) {
			cin >> brr[i];
		}
		for(int i = 1; i <= N; i++) {
			cin >> crr[i];
		}
		fill(dp, dp+1+K, 0);
		for(int i = 1; i <= N; i++) {
			for(int k = K; k >= 0; k--) {
				if(k >= dist[brr[i]]) {
					dp[k] = max(dp[k], dp[k - dist[brr[i]]] + crr[i]);
				}
			}
		}
		cout << dp[K] << "\n";
	}
}