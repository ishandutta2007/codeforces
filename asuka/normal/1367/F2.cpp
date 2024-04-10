#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int t, n, a[N], dp[N][3]; // begin, mid, end
VI vec, num[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		vec.clear();
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) vec.pb(a[i]);
		sort(all(vec));
		vec.erase(unique(all(vec)), vec.end());
		rep(i, 1, n) a[i] = lower_bound(all(vec), a[i]) - vec.begin() + 1;
		rep(i, 1, n) rep(p, 0, 2) dp[i][p] = 0;
		rep(i, 1, n) num[i].clear();
		rep(i, 1, n) num[a[i]].pb(i);
		// rep(i, 1, n) printf("%d ", a[i]);
		// printf("\n");
		rep(i, 1, n) {
			// printf("IIII %d\n", i);
			int pos;
			pos = lower_bound(all(num[a[i]]), i) - num[a[i]].begin() - 1;
			pos = pos >= 0 ? num[a[i]][pos] : 0;
			// printf("%d\n", pos);
			dp[i][0] = dp[pos][0] + 1;
			if(i == num[a[i]].back()) {
				if(a[i] > 1) {
					pos = num[a[i] - 1].back();
				} else pos = 0;
				// printf("! %d\n", pos);
				if(pos < num[a[i]][0]) dp[i][1] = dp[pos][1] + SZ(num[a[i]]);
				if(a[i] > 1) {
					pos = lower_bound(all(num[a[i] - 1]), num[a[i]][0]) - num[a[i] - 1].begin() - 1;
					pos = pos >= 0 ? num[a[i] - 1][pos] : 0;
				} else pos = 0;
				// printf("! %d\n", pos);
				dp[i][1] = max(dp[i][1], dp[pos][0] + SZ(num[a[i]]));
			}
			pos = lower_bound(all(num[a[i]]), i) - num[a[i]].begin() - 1;
			pos = pos >= 0 ? num[a[i]][pos] : 0;
			// printf("%d\n", pos);
			dp[i][2] = dp[pos][2] + 1;
			if(a[i] > 1) {
				pos = lower_bound(all(num[a[i] - 1]), i) - num[a[i] - 1].begin() - 1;
				pos = pos >= 0 ? num[a[i] - 1][pos] : 0;
			} else pos = 0;
			// printf("%d\n", pos);
			dp[i][2] = max(dp[i][2], max(dp[pos][0], dp[pos][1]) + 1);
			// printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
		}
		int ans = 0;
		rep(i, 1, n) rep(p, 0, 2) ans = max(ans, dp[i][p]);
		printf("%d\n", n - ans);
	}
	return 0;
}
/*
1
4
0 1 0 1
*/