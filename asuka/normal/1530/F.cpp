#include<bits/stdc++.h>
#define ll long long
#define N 29
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
const int mod = 31607;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int inv(int x){
	return qpow(x, mod - 2);
}
void inc(int &x, int y) {
	if(x + y >= mod) x = x + y - mod;
	else x = x + y;
}
int n, a[N][N], b[N][N], ans;
void solve(int row, VI one, int res) {
	if(row == n + 1) {
		rep(i, 0, n - 1) res = res * (mod + 1 - one[i]) % mod;
		inc(ans, res);
		return ;
	}
	int tmp = mod - res;
	rep(i, 1, n) tmp = tmp * b[row][i] % mod;
	solve(row + 1, one, tmp);
	rep(i, 1, n) one[i - 1] = one[i - 1] * b[row][i] % mod;
	solve(row + 1, one, res);
}
int main(){
	// freopen("test.txt","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	int fix = inv(10000);
	rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]), a[i][j] = a[i][j] * fix % mod;
	rep(d1, 0, 1) rep(d2, 0, 1) {
		int res = ((d1 + d2) % 2) == 0 ? 1 : -1;
		rep(i, 1, n) rep(j, 1, n) b[i][j] = a[i][j];
		rep(i, 1, n) rep(j, 1, n) {
			if((d1 && i - j == 0) || (d2 && i + j - 1 == n)) {
				res = res * b[i][j] % mod;
				b[i][j] = 1;
			}
		}
		VI all;
		rep(i, 1, n) all.pb(1);
		solve(1, all, res);
	}
	ans = (1 - ans + mod) % mod; 
	printf("%d\n", ans);
	return 0;
}