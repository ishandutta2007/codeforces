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
const int mod = 1e9 + 7;
int T, n, m;
VI que[N], del[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) que[i].clear(), del[i].clear();
		rep(i, 1, m) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			que[l].pb(x);
			del[r].pb(x);
		}
		int ans = 0, pd = 1;
		rep(_, 1, n - 1) pd = pd * 2 % mod;
		rep(c, 0, 29) {
			int cnt[2] = {0, 0}, ocnt[2] = {0, 0};
			rep(i, 1, n) {
				for(auto x : que[i]) cnt[x >> c & 1]++;
				if(cnt[0] == 0) ocnt[1]++;
				else ocnt[0]++;
				for(auto x : del[i]) cnt[x >> c & 1]--;
			}
			if(ocnt[1] > 0) (ans += (ll) (1 << c) * pd % mod) %= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}