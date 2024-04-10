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
int t, n, m;
void fuck(vector<VI> &x, int v) {
	x.resize(n + 2);
	rep(i, 0, n + 1) x[i].resize(m + 2, v);
}
bool col[1000015];
void solve() {
	scanf("%d%d", &n, &m);
	vector<VI> a, pMin, pMax, sMin, sMax;
	fuck(a, 0);
	fuck(pMin, inf);
	fuck(sMin, inf);
	fuck(pMax, 0);
	fuck(sMax, 0);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
	rep(i, 1, n) {
		rep(j, 1, m) pMin[i][j] = min(a[i][j], pMin[i][j - 1]);
		rep(j, 1, m) pMax[i][j] = max(a[i][j], pMax[i][j - 1]);
		per(j, 1, m) sMin[i][j] = min(a[i][j], sMin[i][j + 1]);
		per(j, 1, m) sMax[i][j] = max(a[i][j], sMax[i][j + 1]);
	}
	// printf("%d %d\n", sMin[1][3], sMin[1][4]);
	rep(k, 1, m - 1) {
		VI ord, prel, sufl, prer, sufr;
		prel.resize(n, 0);
		sufl.resize(n, inf);
		prer.resize(n, inf);
		sufr.resize(n, 0);
		rep(i, 1, n) ord.pb(i);
		sort(all(ord), [&](int u, int v){
			return pMin[u][k] < pMin[v][k];
		});
		rep(i, 0, n - 1) {
			int u = ord[i];
			if(i > 0) prel[i] = prel[i - 1], prer[i] = prer[i - 1];
			prel[i] = max(prel[i], pMax[u][k]);
			prer[i] = min(prer[i], sMin[u][k + 1]);
		}
		per(i, 0, n - 1) {
			int u = ord[i];
			if(i < n - 1) sufl[i] = sufl[i + 1], sufr[i] = sufr[i + 1];
			sufl[i] = min(sufl[i], pMin[u][k]);
			sufr[i] = max(sufr[i], sMax[u][k + 1]);
		}
		// rep(i, 0, n - 1) printf("%d ", ord[i]);
		// printf("\n");
		// rep(i, 0, n - 1) printf("%d ", prel[i]);
		// printf("\n");
		// rep(i, 0, n - 1) printf("%d ", sufl[i]);
		// printf("\n");
		// rep(i, 0, n - 1) printf("%d ", prer[i]);
		// printf("\n");
		// rep(i, 0, n - 1) printf("%d ", sufr[i]);
		// printf("\n");
		rep(i, 0, n - 2) {
			if(prel[i] < sufl[i + 1] && prer[i] > sufr[i + 1]) {
				puts("YES");
				rep(_, 1, n) col[_] = 0;
				rep(_, 0, i) col[ord[_]] = 1; // blue
				rep(_, 1, n) printf("%c", col[_] ? 'B' : 'R');
				printf(" ");
				printf("%d\n", k);
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}
/*
1
5 5
1 5 8 8 7
5 2 1 4 3
1 6 9 7 5
9 3 3 3 2
1 7 9 9 8
*/