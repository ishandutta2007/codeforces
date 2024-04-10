#include<bits/stdc++.h>
#define ll long long
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
const int N = 66, M = 266;
int T, n, m, w[N][N], id[N][N], row, ans[M];
bool flag;
int a[4444][M];
void Gauss() {
	flag = 1;
	int cur = 0;
 	rep(i, 1, m) {
		int p = 0;
		rep(j, cur + 1, row) if(a[j][i] > a[p][i]) p = j;
		if(!p) continue;
		swap(a[p], a[++cur]);
		rep(j, 1, row) {
			if(cur == j) continue;
			char coef = a[j][i] * a[cur][i] % 3;
			rep(k, 1, m + 1) (a[j][k] += 3 - (a[cur][k] * coef % 3)) %= 3;
		}
	}
	rep(i, 1, row) {
		VI vec;
		rep(j, 1, m) if(a[i][j] != 0) vec.pb(j);
		if(SZ(vec) == 0) {
			if(a[i][m + 1] != 0) flag = 0;
		} else {
			ans[vec[0]] = a[i][vec[0]] * a[i][m + 1] % 3;
		}
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof a);
		memset(id, 0, sizeof id);
		memset(w, 0, sizeof id);
		memset(ans, 0, sizeof ans);
		row = 0;
		rep(i, 1, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			if(x > y) swap(x, y);
			scanf("%d", &w[x][y]);
			if(~w[x][y]) {
				row++;
				a[row][i] = 1;
				a[row][m + 1] = w[x][y];
			}
			id[x][y] = i;
		}
		rep(i, 1, n) rep(j, i + 1, n) rep(k, j + 1, n) if(w[i][j] && w[j][k] && w[i][k]) {
			row++;
			a[row][id[i][j]] = a[row][id[j][k]] = a[row][id[i][k]] = 1;
		}
		rep(i, 2, row) swap(a[i], a[rand() % (i - 1) + 1]);
		Gauss();
		if(!flag) puts("-1");
		else {
			rep(i, 1, m) ans[i] %= 3;
			rep(i, 1, m) printf("%d ", ans[i] == 0 ? 3 : ans[i]);
			printf("\n");
		}
	}
	return 0;
}
/*
1
5 10
1 2 2
1 3 -1
1 4 -1
1 5 -1
2 3 1
2 4 -1
2 5 -1
3 4 -1
3 5 -1
4 5 -1
*/