#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
using ull = unsigned ll;
int n, f[N];
const int mod[] = {19260817, 1000000007, 1000000009};
int hs[N][3], pd[N][3];
int geths(int l, int r, int p) {return (hs[r][p] - (ll) pd[r - l + 1][p] * hs[l - 1][p] % mod[p] + mod[p]) % mod[p];}
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	scanf("%s", s + 1);
	rep(p, 0, 2) {
		pd[0][p] = 1;
		rep(i, 1, n) pd[i][p] = (ll) pd[i - 1][p] * 233 % mod[p];
		rep(i, 1, n) hs[i][p] = ((ll) hs[i - 1][p] * 233 + s[i]) % mod[p];
	}
 	rep(i, 1, n) {
 		if(i % 2 == 0) continue;
 		int l = 0, r = i / 2, ans = -1;
 		while(l <= r) {
 			int mid = (l + r) >> 1;
 			bool flag = 1;
 			rep(p, 0, 2) flag &= geths(1 + mid, i - mid, p) == geths(n - i + 1 + mid, n - mid, p);
 			if(flag) ans = mid, r = mid - 1;
 			else l = mid + 1;
 		}
 		if(~ans) {
 			int x = 1 + ans, y = i - ans;
 			if(x + y != n + 1) f[x] = max(f[x], y - x + 1);
 		}
 	}
 	int pre = 0;
 	rep(k, 1, (n + 1) / 2) {
 		pre -= 2;
 		int u = max(pre, f[k]);
 		printf("%d ", u == 0 ? -1 : u);
 		pre = max(pre, f[k]);
 	}
	return 0;
}