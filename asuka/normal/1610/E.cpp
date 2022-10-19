#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int T, n, a[N], b[N], nxt[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		for(int l = 1, r; l <= n; l = r + 1) {
			r = l;
			while(r + 1 <= n && a[r + 1] == a[l]) r++;
			rep(i, l, r) nxt[i] = r;
		}
		int ans = 0;
		rep(i, 1, n) {
			int cnt = nxt[i] - i + 1, cur = nxt[i] + 1;
			while(cur <= n) {
				cnt++;
				int pos = lower_bound(a + cur + 1, a + n + 1, 2 * a[cur] - a[i]) - a;
				cur = pos;
			}
			ans = max(ans, cnt);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}