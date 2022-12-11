#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[105];
const long long MOD = 998244353;
int bstdist[105];
vector<int> lst[105];
long long dp[105][105];
vector<vector<int>> vec;

long long mult(long long a, long long b) {
	return a * b % MOD;
}

long long add(long long a, long long b) {
	return (a + b) % MOD;
}

int dist(int a, int b) {
	return abs(arr[a].first - arr[b].first) + abs(arr[a].second - arr[b].second);
}

int main() {
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
		bstdist[i] = 1e9;
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i != j){ 
				bstdist[i] = min(bstdist[i], dist(i, j));
			}
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(bstdist[i] >= dist(i, j)) {
				lst[i].push_back(j);
			}
		}
		vec.push_back(lst[i]);
		/*
		for(int n : lst[i]) {
			cout << n << " ";
		}
		cout << "\n";
		*/
	}
	sort(vec.begin(), vec.end());
	dp[0][N] = 1;
	for(int i = 0; i < N; i++) {
		for(int j = 1; j <= N; j++) {
			dp[i+1][j-1] = add(dp[i+1][j-1], mult(j, dp[i][j]));
			int k = i;
			while(k < N) {
				if(vec[i] == vec[k]){
					k++;
				}
				else {
					break;
				}
			}
			if(k == i+1 || k - i != vec[i].size()) {
				continue;
			}
			if(i == 0 || vec[i] != vec[i-1]) {
				dp[k][j-1] = add(dp[k][j-1], mult(j, dp[i][j]));
			}
		}
	}
	long long ans = 0;
	for(int j = 0; j <= N; j++) {
		ans = add(ans, dp[N][j]);
	}
	cout << ans;
}