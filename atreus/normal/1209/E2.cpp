#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxm = 2000 + 10;
const int maxn = 12;

int a[15][maxm];
int maxincol[maxm];
int dp[15][4100], mxm[15][4100];
pair<int, int> p[maxm];
bool mark[maxm];

void vitex(){
	memset(dp, 0, sizeof dp);
	memset(mxm, 0, sizeof mxm);
}

void solve(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	if (m > n){ // find important columns
		for (int i = 0; i < m; i++)
			maxincol[i] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				maxincol[j] = max(maxincol[j], a[i][j]);
		for (int i = 0; i < m; i++)
			p[i] = {maxincol[i], i};
		sort(p, p + m);
		for (int i = 0; i < m; i++)
			mark[i] = 0;
		for (int i = m - 1; i >= m - n; i--)
			mark[p[i].second] = 1;
		int ptr = 0;
		for (int i = 0; i < m; i++){
			if (mark[i] == 1){
				for (int j = 0; j < n; j++)
					a[j][ptr] = a[j][i];
				ptr ++;
			}
		}
		m = n;
	}
	for (int i = 0; i < m; i++){
		for (int mask = 0; mask < (1 << n); mask++){
			for (int rot = 0; rot < n; rot++){
				int tmp = a[n - 1][i];
				for (int j = n - 1; j > 0; j--)
					a[j][i] = a[j - 1][i];
				a[0][i] = tmp;
				int sum = 0;
				for (int j = 0; j < n; j++)
					if (mask & (1 << j))
						sum += a[j][i];
				mxm[i][mask] = max(mxm[i][mask], sum);
			}
		}
	}
	for (int i = 0; i < m; i++){
		for (int mask = 0; mask < (1 << n); mask++){
			for (int sub = mask; sub >= 0; sub = (sub - 1) & mask){
				dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask ^ sub] + mxm[i][sub]);
				if (sub == 0)
					break;
			}
		}
	}
	cout << dp[m][(1 << n) - 1] << '\n';
	vitex();
}

int main(){
	ios_base::sync_with_stdio (false);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}