#include<bits/stdc++.h>
#define ll long long
#define N 10015
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
int T, n, a[N], f[1015], g[1015];
// f[x]x
void upd(int &x, int y) {
	if(y < x) x = y;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int m = *max_element(a + 1, a + n + 1);
		rep(i, 0, m) f[i] = inf;
		f[0] = 0;
		rep(i, 1, n) {
			rep(j, 0, m) g[j] = inf;
			rep(j, 0, m) {
				if(f[j] > m * 2) continue;
				int pos = j, len = f[j];
				int npos = max(pos - a[i], 0), nlen = len + max(a[i] - pos, 0);
				upd(g[min(npos, nlen - npos)], nlen);
				pos = len - pos;
				npos = max(pos - a[i], 0), nlen = len + max(a[i] - pos, 0);
				upd(g[min(npos, nlen - npos)], nlen);
			}
			// rep(j, 0, m) printf("%d %d\n", j, g[j]);
			swap(f, g);
		}
		int ans = inf;
		rep(i, 0, m) ans = min(ans, f[i]);
		printf("%d\n", ans);
	}
	return 0;
}