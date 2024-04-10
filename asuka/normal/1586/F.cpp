#include<bits/stdc++.h>
#define ll long long
#define N 1005
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
int n, k, col[N][N], ans;
void solve(VI vec, int lvl) {
	int m = SZ(vec);
	ans = max(ans, lvl);
	if(m <= k) {
		for(auto x : vec) for(auto y : vec) col[x][y] = lvl;
		return;
	}
	vector<VI> nxt;
	int nm = (m + k - 1) / k;
	nxt.resize(k);
	reverse(all(vec));
	rep(i, 0, k - 1) {
		rep(_, 1, nm) {
			if(SZ(vec) > 0) {
				nxt[i].pb(vec.back());
				vec.pop_back();
			}
		}
	}
	rep(i, 0, k - 1) solve(nxt[i], lvl + 1);
	rep(i, 0, k - 1) rep(j, 0, k - 1) {
		if(i == j) continue;
		for(auto x : nxt[i]) for(auto y : nxt[j]) col[x][y] = lvl;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	VI vec;
	rep(i, 1, n) vec.pb(i);
	solve(vec, 1);
	printf("%d\n", ans);
	rep(i, 1, n) rep(j, i + 1, n) printf("%d ", col[i][j]);
	return 0;
}