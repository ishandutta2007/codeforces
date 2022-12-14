#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 
const int maxn = 1e6 + 10;

vector<pair<int,int> > come[maxn], getb[maxn];
int cost[maxn];
ll dp[maxn], pd[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int d, f, t, c;
		cin >> d >> f >> t >> c;
		if (t == 0)
			come[d].push_back({f, c});
		else
			getb[d].push_back({t, c});
	}
	int T = 1000000;
	int cnt = 0;
	ll sum = 0;
	memset(cost, -1, sizeof cost);
	for (int i = 1; i <= T; i++){
		for (auto it : come[i]){
			if (cost[it.first] == -1){
				cnt ++;
				sum += it.second;
				cost[it.first] = it.second;
			}
			else if (cost[it.first] > it.second){
				sum += it.second - cost[it.first];
				cost[it.first] = it.second;
			}
		}
		if (cnt == n)
			dp[i] = sum;
		else
			dp[i] = -1;
	}
	cnt = 0, sum = 0;
	memset(cost, -1, sizeof cost);
	for (int i = T; i >= 1; i--){
		for (auto it : getb[i]){
			if (cost[it.first] == -1){
				cnt ++;
				sum += it.second;
				cost[it.first] = it.second;
			}
			else if (cost[it.first] > it.second){
				sum += it.second - cost[it.first];
				cost[it.first] = it.second;
			}
		}
		if (cnt == n)
			pd[i] = sum;
		else
			pd[i] = -1;
	}
	ll answer = -1;
	for (int i = 1; i <= T; i++){
		int j = i + k + 1;
		if (j > T)
			continue;
		if (dp[i] != -1 and pd[j] != -1)
			if (answer == -1 or answer > dp[i] + pd[j])
				answer = dp[i] + pd[j];
	}
	cout << answer << endl;
}