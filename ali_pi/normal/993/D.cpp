#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;
static const ll INF = 1000000000000000000ll;
static ll dp[2][64][8192];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pii> tasks(n);
	for(int i = 0; i < n; ++i){ cin >> tasks[i].first; }
	for(int i = 0; i < n; ++i){ cin >> tasks[i].second; }
	sort(tasks.begin(), tasks.end(), greater<pii>());
	int maxproc = 0;
	for(int i = 0; i < n; ++i){ maxproc += tasks[i].second; }

	for(int i = 0; i < 64; ++i){
		for(int j = 0; j < 8192; ++j){
			dp[0][i][j] = dp[1][i][j] = INF;
		}
	}
	dp[0][0][0] = 0;

	int cur = 0;
	for(int i = 0; i < n; ){
		const int next = 1 - cur;
		int k = 0;
		for(int j = i; j < n && tasks[i].first == tasks[j].first; ++j){ ++k; }
		for(int j = 0; j <= k; ++j){
			ll  a_sum = 0;
			int b_sum = 0;
			for(int p = 0; p < j; ++p){
				a_sum += tasks[i + p].first;
				b_sum += tasks[i + p].second;
			}
			for(int t = 0; t <= n; ++t){
				if(t >= k - j){
					const int nt = t - (k - j) + j;
					for(int p = 0; p <= maxproc; ++p){
						dp[next][nt][p + b_sum] = min(dp[next][nt][p + b_sum], dp[cur][t][p] + a_sum);
					}
				}
			}
		}
		i += k;
		for(int t = 0; t <= n; ++t){
			for(int p = 0; p <= maxproc; ++p){ dp[cur][t][p] = INF; }
		}
		cur = next;
	}
	ll answer = INF;
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= maxproc; ++j){
			if(dp[cur][i][j] >= INF){ continue; }
			const auto k = (1000 * dp[cur][i][j] + j - 1) / j;
			answer = min(answer, k);
		}
	}
	cout << answer << endl;
}