#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;

const int maxn = 80 + 10;
const int inf = 1e9 + 7;
int n, k;
int sz, up[6];
int dis[maxn][maxn];
int answer = inf;
int tmpdis[7][7], dp[7][6];
bool mark[maxn];
vector<pair<int,int> > d[maxn][maxn];

void solve(){
	if (sz >= n)
		return;
	for (int i = 0; i < sz; i++)
		mark[up[i]] = 1;
	
	for (int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++){
			tmpdis[i][j] = inf;
			for (auto it : d[up[i]][up[j]]){
				if (!mark[it.second]){
					tmpdis[i][j] = it.first;
					break;
				}
			}
		}
	}
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for (int x = 1; x <= k / 2; x++)
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				dp[x][i] = min(dp[x][i], dp[x-1][j] + tmpdis[j][i]);
	answer = min(answer, dp[k/2][0]);
	for (int i = 0; i < sz; i++)
		mark[up[i]] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dis[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			for (int x = 1; x <= n; x++)
				if (x != i and x != j)
					d[i][j].push_back({dis[i][x] + dis[x][j], x});
			sort(d[i][j].begin(), d[i][j].end());
		}
	for (int i = 1; i <= 1; i++){
		up[sz ++] = i;
		solve();
		if (k == 2)
			break;
		for (int j = i + 1; j <= n; j++){
			up[sz ++] = j;
			solve();
			if (k > 4){
				for (int x1 = j + 1; x1 <= n; x1++){
					up[sz ++] = x1;
					solve();
					if (k > 6){
						for (int x2 = x1 + 1; x2 <= n; x2++){
							up[sz ++] = x2;
							solve();
							if (k > 8){
								for (int x3 = x2 + 1; x3 <= n; x3++){
									up[sz ++] = x3;
									solve();
									sz --;
								}
							}
							sz --;
						}
					}
					sz --;
				}
			}
			sz --;
		}
	}
	cout << answer << '\n';
}