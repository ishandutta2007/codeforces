#include<bits/stdc++.h>
#define ll long long
#define N 5015
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
int n, a[N], f[N][N][2];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	memset(f, 0x3f, sizeof f);
	f[0][0][0] = 0;
	rep(i, 1, n) rep(j, 0, (n + 1) / 2) {
		f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][1]);
		if(j) f[i][j][1] = min(
			(i > 1 ? f[i - 2][j - 1][0] : (j == 1 ? 0 : inf)) + max(a[i - 1] - a[i] + 1, 0), 
			(i > 1 ? f[i - 2][j - 1][1] + max(min(a[i - 2] - 1, a[i - 1]) - a[i] + 1, 0) : (j == 1 ? 0 : inf))) + max(a[i + 1] - a[i] + 1, 0);
		// printf("%d %d: %d %d\n", i, j, f[i][j][0], f[i][j][1]);
	}
	rep(i, 1, (n + 1) / 2) printf("%d ", min(f[n][i][0], f[n][i][1]));
	return 0;
}