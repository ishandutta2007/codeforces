#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, dp[(1 << 20) + 15][2], st[25];
string s[25];
VI pre[25], Min[25], num[400015];
int query(int l, int r, int v) {
	v = -v;
	assert(v >= 0);
	return upper_bound(all(num[v]), r) - lower_bound(all(num[v]), l);
}
void upd(int &x, int y) {
	if(y > x) x = y;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> s[i];
	rep(i, 1, n) {
		if(i == 1) st[i] = 1;
		else st[i] = st[i - 1] + SZ(s[i - 1]);
		pre[i].resize(s[i].length());
		Min[i].resize(s[i].length());
		rep(j, 0, SZ(s[i]) - 1) {
			pre[i][j] = ((j > 0) ? pre[i][j - 1] : 0) + (s[i][j] == '(' ? 1 : -1);
			Min[i][j] = min(j > 0 ? Min[i][j - 1] : inf, pre[i][j]);
		}
		rep(j, 0, SZ(s[i]) - 1) {
			if(pre[i][j] <= 0) num[-pre[i][j]].pb(st[i] + j);
		}
		// rep(j, 0, SZ(s[i]) - 1) printf("%d ", pre[i][j]);
		// printf("\n");
	}
	rep(p, 0, 1) rep(mask, 0, (1 << n) - 1) dp[mask][p] = -inf;
	dp[0][1] = 0;
	rep(mask, 0, (1 << n) - 1) {
		int sum = 0;
		rep(i, 1, n) {
			if(!(mask >> (i - 1) & 1)) continue;
			sum += pre[i][SZ(s[i]) - 1];
		}
		// if(mask == 1) {
		// 	printf("QWET %d\n", sum);
		// }
		if(sum < 0) continue;
		rep(i, 1, n) {
			if(mask >> (i - 1) & 1) continue;
			int l = 0, r = SZ(s[i]) - 1, ans = -1;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(sum + Min[i][mid] >= 0) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			// if(mask == 1 && i == 2) {
			// 	printf("%d\n", ans);
			// }
			if(ans == -1) continue;
			upd(dp[mask | (1 << (i - 1))][sum + Min[i][SZ(s[i]) - 1] >= 0], dp[mask][1] + query(st[i], st[i] + ans, -sum));
			// if(mask == 0 && i == 1) {
			// 	printf("!!! %d\n", dp[1]);
			// }
			// if(mask == 1 && i == 2) {
			// 	printf("??? %d\n", dp[3]);=
			// }
		}
	}
	int ans = 0;
	rep(p, 0, 1) rep(mask, 0, (1 << n) - 1) upd(ans, dp[mask][p]);
	cout << ans << endl;
	return 0;
}