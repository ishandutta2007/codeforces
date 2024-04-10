#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

int dp[1000][1000], st[1000][1000][10][10], Log[1001];

int max(int i1, int j1, int i2, int j2) {
	int ii = Log[i2 - i1 + 1];
	int jj = Log[j2 - j1 + 1];
	return max( max(st[i1][j1][ii][jj],
				st[i1][j2-(1<<jj)+1][ii][jj]),
				max(st[i2-(1<<ii)+1][j1][ii][jj],
				st[i2-(1<<ii)+1][j2-(1<<jj)+1][ii][jj]));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			int d;
			cin >> d;
			dp[i][j] = 0;
			if(d == 1)
				dp[i][j] = 1 + (i&&j?min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]):0);
		}
	for(int i = 0, lim = max(n,m); i <= lim; i++)
		Log[i] = (i > 1 ? Log[i/2] + 1 : 0);
	for(int ii = 0; (1<<ii) <= n; ii++)
		for(int jj = 0; (1<<jj) <= m; jj++)
			for(int i = 0; i + (1 << ii) <= n; i++)
				for(int j = 0; j + (1 << jj) <= m; j++) {
					st[i][j][ii][jj] = dp[i][j];
					if(ii > 0) {
						st[i][j][ii][jj] = max(st[i][j][ii][jj], st[i][j][ii-1][jj]);
						st[i][j][ii][jj] = max(st[i][j][ii][jj], st[i+(1<<(ii-1))][j][ii-1][jj]);
					}
					if(jj > 0) {
						st[i][j][ii][jj] = max(st[i][j][ii][jj], st[i][j][ii][jj-1]);
						st[i][j][ii][jj] = max(st[i][j][ii][jj], st[i][j+(1<<(jj-1))][ii][jj-1]);
					}
				}
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		--i1; --j1; --i2; --j2;
		int bl = 0, br = min(i2-i1+1, j2-j1+1);
		while(bl < br) {
			int bm = (bl + br) >> 1;
			if(bl == bm)
				bm++;
			if(max(i1 + bm - 1, j1 + bm - 1, i2, j2) >= bm)
				bl = bm;
			else
				br = bm - 1;
		}
		cout << bl << '\n';
	}
}