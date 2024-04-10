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
const int N = 100015;
int q, n;
char s[N], t[N];
VI pos[26];
int D[N];
void add(int p, int v) {for(; p <= n; p += lowbit(p)) D[p] += v;}
int query(int p) {int res = p; for(; p; p -= lowbit(p)) res += D[p]; return res;}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		rep(i, 0, 25) pos[i].clear();
		rep(i, 1, n) D[i] = 0;
		per(i, 1, n) pos[s[i] - 'a'].pb(i);
		ll ans = infll, cur = 0;
		rep(i, 1, n) {
			int ch = t[i] - 'a';
			rep(c, 0, ch - 1) {
				if(SZ(pos[c]) > 0) {
					ans = min(ans, cur + query(pos[c].back()) - i);
				}
			}
			if(SZ(pos[ch]) == 0) break;
			int o = pos[ch].back(); pos[ch].pop_back();
			// printf("OOO %d\n", o);
			// move o -> i
			cur += query(o) - i;
			add(1, 1);
			add(o, -1);
		}
		printf("%lld\n", ans == infll ? -1 : ans);
	}
	return 0;
}