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
int n, k, nxt[N][21], ext[N][21], dp[(1 << 19) + 10];
char s[N];
bool check(int len) {
	rep(i, 1, n + 1) rep(j, 0, k - 1) nxt[i][j] = n + 2;
	per(i, 1, n) rep(j, 0, k - 1){
		if(ext[i][j] >= len) nxt[i][j] = i + len;
		else nxt[i][j] = nxt[i + 1][j];
	}
	// printf("LEN %d\n", len);
	// rep(i, 1, n) rep(j, 0, k - 1){
	// 	printf("%d %c %d\n", i, 'a' + j, nxt[i][j]);
	// }
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 1;
	int all = (1 << k) - 1;
	rep(s, 1, all) {
		rep(i, 0, k - 1) if((1 << i) & s) {
			if(dp[s ^ (1 << i)] > n) continue;
			dp[s] = min(dp[s], nxt[dp[s ^ (1 << i)]][i]);
		}
	}
	if(dp[all] <= n + 1) return 1;
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	per(i, 1, n) rep(j, 0, k - 1) {
		if(s[i] == j + 'a' || s[i] == '?') ext[i][j] = ext[i + 1][j] + 1;
	}
	int l = 0, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}