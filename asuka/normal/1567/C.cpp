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
int T, n, m, a[11], dp[11][2][2];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		memset(dp, 0, sizeof dp);
		scanf("%d", &n);
		m = 0;
		while(n) a[++m] = n % 10, n /= 10;
		dp[0][0][0] = 1;
		rep(i, 1, m) {
			rep(p, 0, 1) rep(q, 0, 1) rep(x, 0, 9) rep(y, 0, 9) {
				int cur = x + y + q;
				if(cur % 10 == a[i]) dp[i][cur / 10][p] += dp[i - 1][p][q];
			}
		}
		printf("%d\n", dp[m][0][0] - 2);
	}
	return 0;
}