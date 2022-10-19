#include<bits/stdc++.h>
#define ll long long
#define N 105
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
int n;
char s[N];
ll k, ans, dp[N][N], cnt[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%lld", &n, &k);
	scanf("%s", s + 1);
	dp[0][0] = 1;
	rep(i, 1, n) {
		rep(j, 1, n) {
			per(k, 0, i - 1) {
				dp[i][j] += dp[k][j - 1];
				if(k != 0 && s[k] == s[i]) break;
			}
		}
	}
	rep(i, 0, n) rep(j, 0, n) cnt[j] += dp[i][j];
	// rep(j, 0, n) printf("%lld\n", cnt[j]);
	per(i, 0, n) {
		if(k > cnt[i]) {
			k -= cnt[i];
			ans += (n - i) * cnt[i];
		} else {
			ans += (n - i) * k;
			k = 0;
			break;
		}
	}
	printf("%lld\n", k > 0 ? -1 : ans);
	return 0;
}