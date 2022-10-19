#include<bits/stdc++.h>
#define ll long long
#define N 5005
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
int T, n, k, V, a[N], typ[N];
bool dp[N][N], from[N][N];
vector<tuple<int, int, int>> ans;
void gettyp(int x, int y) {
	if(x == 0 && y == 0) return;
	if(from[x][y]) {
		typ[x] = 1;
		y = (y - (a[x] % k) + k) % k;
	}
	gettyp(x - 1, y);
}
void solve() {
	ans.clear();
	scanf("%d%d%d", &n, &k, &V);
	int sum = 0;
	rep(i, 1, n) scanf("%d", &a[i]), sum += a[i];
	if(sum < V) {
		puts("NO");
		return;
	}
	rep(i, 0, n) rep(j, 0, k - 1) dp[i][j] = from[i][j] = 0;
	dp[0][0] = 1;
	rep(i, 1, n) {
		rep(j, 0, k - 1) {
			if(dp[i - 1][j]) {
				dp[i][(j + a[i]) % k] = 1;
				from[i][(j + a[i]) % k] = 1;
				dp[i][j] = 1;
				from[i][j] = 0;
			}
		}
	}
	if(!dp[n][V % k]) {
		puts("NO");
		return;
	}
	puts("YES");
	rep(i, 1, n) typ[i] = 0;
	gettyp(n, V % k);
	int l0 = -1, l1 = -1;
	rep(i, 1, n) {
		if(typ[i] == 0) {
			if(l0 == -1) l0 = i;
			else ans.pb(make_tuple(1000000000, i, l0));
		} else {
			if(l1 == -1) l1 = i;
			else ans.pb(make_tuple(1000000000, i, l1));
		}
	}
	if(l0 == -1) l0 = l1 == 1 ? 2 : (l1 - 1);
	if(l1 == -1) l1 = l0 == 1 ? 2 : (l0 - 1);
	sum = 0;
	rep(i, 1, n) if(typ[i] == 1) sum += a[i];
	int dif = V - sum;
	if(dif > 0) ans.pb(make_tuple(dif / k, l0, l1));
	if(dif < 0) ans.pb(make_tuple(-dif/ k, l1, l0));
	for(auto u : ans) printf("%d %d %d\n", get<0>(u), get<1>(u), get<2>(u));
}
int main(){
	// freopen("data6.in","r",stdin);
	// freopen("data6.out","w",stdout);
	// scanf("%d", &T);
	T = 1;
	while(T--) solve();
	return 0;
}
/*
3
5 5 9
3 3 2 1 4
5 10 11
1 114 514 19198 10
5 6 7
1 2 3 4 5
*/