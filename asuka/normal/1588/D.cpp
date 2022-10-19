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
int t, n, dp[55][1 << 10], pos[15][55][2], ord[55];
pii from[55][1 << 10];
string s[15], res;
int fuck(char ch) {
	if('a' <= ch && ch <= 'z') return ch - 'a';
	return ch - 'A' + 26;
}
char Fuck(int ch) {
	if(ch < 26) return ch + 'a';
	return ch - 26 + 'A';
}
void dfs1(int ch, int x, int mask, int pch, int pmask) {
	if(x > n) {
		if(dp[pch][pmask] + 1 > dp[ch][mask]) {
			dp[ch][mask] = dp[pch][pmask] + 1;
			from[ch][mask] = mp(pch, pmask);
		}
		return;
	}
	rep(p, 0, 1) {
		if(pos[x][pch][pmask >> (x - 1) & 1] >= pos[x][ch][p]) continue;
		// printf("%d %d %d %d %d %d %d\n", x, pch, pmask, pos[x][pch][pmask >> (x - 1) & 1], ch, p, pos[x][ch][p]);
		dfs1(ch, x + 1, mask | (p << (x - 1)), pch, pmask);
		break;
	}
}
void output(pii x) {
	if(x == mp(-1, -1)) return;
	output(from[x.fi][x.se]);
	res += Fuck(x.fi);
	// cout << "!" << x.fi << endl;
} 
void solve() {
	memset(dp, 0xc0, sizeof dp);
	memset(pos, -1, sizeof pos);
	cin >> n;
	rep(i, 1, n) {
		cin >> s[i];
		rep(j, 0, SZ(s[i]) - 1) {
			int ch = fuck(s[i][j]);
			if(pos[i][ch][0] == -1) pos[i][ch][0] = j;
			else pos[i][ch][1] = j;
		}
	}
	rep(i, 0, 51) rep(mask, 0, (1 << n) - 1) from[i][mask] = mp(-1, -1);
	int ans = 0;
	pii p = mp(-1, -1);
	rep(_, 0, SZ(s[1]) - 1) {
		int ch = fuck(s[1][_]);
		VI vec;
		rep(mask, 0, (1 << n) - 1) {
			bool flag = 1;
			rep(i, 1, n) {
				int u = mask >> (i - 1) & 1;
				if(pos[i][ch][u] == -1) flag = 0;
			}
			if(!flag) continue;
			vec.pb(mask);
			dp[ch][mask] = max(dp[ch][mask], 1);
			if(dp[ch][mask] > ans) {
				ans = dp[ch][mask];
				p = mp(ch, mask);
			}
			// printf("(%d %d) : %d\n", ch, mask, dp[ch][mask]);
		}
		for(auto mask : vec) rep(nch, 0, 51) {
			dfs1(nch, 1, 0, ch, mask);
		}
	}
	cout << ans << endl;
	res.clear();
	output(p);
	cout << res << endl;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) solve();
	return 0;
}