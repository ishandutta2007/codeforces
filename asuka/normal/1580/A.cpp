#include<bits/stdc++.h>
#define ll long long
#define N 405
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
int n, m, a[N][N], val[N], Min[N], sum[2][N][N];
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) {
			scanf("%s", s + 1);
			rep(j, 1, m) a[i][j] = s[j] - '0';
		}
		rep(j, 1, m) {
			rep(i, 1, n) {
				rep(p, 0, 1) sum[p][j][i] = sum[p][j][i - 1] + (a[i][j] == p);
			}
		}
		int ans = inf;
		rep(x, 1, n) {
			rep(y, x + 4, n) {
				// printf("[%d %d]\n", x, y);
				rep(j, 0, m + 3) val[j] = 0, Min[j] = inf;
				#define calc(j) (sum[1][j][y - 1] - sum[1][j][x] + (!a[x][j]) + (!a[y][j]))
				rep(j, 1, m) val[j] = val[j - 1] + calc(j);
				// rep(j, 1, m) printf("%d ", calc(j));
				// printf("\n");
				// rep(j, 1, m) printf("%d ", val[j]);
				// printf("\n");
				per(j, 1, m) Min[j] = min(Min[j + 1], val[j - 1] + sum[0][j][y - 1] - sum[0][j][x]);
				rep(j, 1, m) {
					ans = min(ans, Min[j + 3] - val[j] + sum[0][j][y - 1] - sum[0][j][x]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}