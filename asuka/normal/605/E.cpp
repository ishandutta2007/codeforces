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
using db = double;
const db eps = 1e-8;
int n;
bool vis[N];
db p[N][N], A[N], B[N], ans[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) {
		rep(j, 1, n) {
			int x;
			scanf("%d", &x);
			p[i][j] = (db) x / 100;
		}
	}
	rep(i, 1, n - 1) A[i] = B[i] = 1.0;
	rep(_, 1, n) {
		int pos = -1;
		rep(i, 1, n) if(fabs(1.0 - A[i]) >= eps) {
			ans[i] = B[i] / (1.0 - A[i]);
		}
		rep(i, 1, n) {
			if(vis[i] || fabs(1.0 - A[i]) < eps) continue;
			if(pos == -1 || ans[i] < ans[pos]) pos = i;
		}
		if(pos == -1) break;
		vis[pos] = 1;
		// printf("(%d %lf)\n", pos, ans[pos]);
		rep(i, 1, n) {
			if(vis[i]) continue;
			B[i] += A[i] * p[i][pos] * (ans[pos] + 1.0) - A[i] + A[i] * (1 - p[i][pos]);
			A[i] *= (1 - p[i][pos]);
		}
	}
	printf("%lf\n", ans[1]);
	return 0;
}