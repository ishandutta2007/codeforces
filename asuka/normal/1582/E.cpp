#include<bits/stdc++.h>
#define ll long long
#define N 100115
#define B 505
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
int n, b, a[N], dp[N];
ll sum[N], suf[N][B];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		b = 0;
		while(b * (b + 1) <= n * 2) b++;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
		rep(i, 1, n + 1) rep(j, 0, b) suf[i][j] = 0;
		per(i, 1, n) {
			dp[i] = 1;
			per(j, 2, b) {
				if(i + j - 1 > n) continue;
				if(suf[i + j][j - 1] > (sum[i + j - 1] - sum[i - 1])) {
					dp[i] = j;
					break;
				}
			}
			rep(j, 1, b) suf[i][j] = suf[i + 1][j];
			rep(j, 1, dp[i]) suf[i][j] = max(suf[i][j], sum[i + j - 1] - sum[i - 1]);
		}
		int ans = *max_element(dp + 1, dp + n + 1);
		printf("%d\n", ans);
	}
	return 0;
}