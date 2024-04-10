#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
const int B = 316;
int n, m, q;
int sec[N][B + 10], cnt[N];
ll sum[N], tag[N], a[N];
VI vec[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) scanf("%lld", &a[i]);
	VI big;
	rep(i, 1, m) {
		vec[i].clear();
		int k, x;
		scanf("%d", &k);
		rep(_, 1, k) {
			scanf("%d", &x);
			vec[i].pb(x);
		}
		if(SZ(vec[i]) > B) {
			big.pb(i);
		}
		for(auto x : vec[i]) sum[i] += a[x];
	}
	rep(i, 1, n) a[i] = 0;
	rep(_, 0, SZ(big) - 1) {
		int u = big[_];
		rep(i, 1, n) cnt[i] = 0;
		for(auto x : vec[u]) cnt[x]++;
		rep(i, 1, m) {
			for(auto x : vec[i]) sec[i][_] += cnt[x];
		}
	}
	while(q--) {
		char hyhyh[3];
		int k, x;
		scanf("%s", hyhyh);
		if(hyhyh[0] == '?') {
			scanf("%d", &k);
			ll res = sum[k];
			if(SZ(vec[k]) <= B) {
				for(auto u : vec[k]) res += a[u];
			}
			rep(i, 0, SZ(big) - 1) {
				res += sec[k][i] * tag[big[i]];
			}
			printf("%lld\n", res);
		} else {
			scanf("%d%d", &k, &x);
			if(SZ(vec[k]) <= B) {
				for(auto u : vec[k]) a[u] += x;
				rep(i, 0, SZ(big) - 1) {
					sum[big[i]] += sec[k][i] * x;
				}
			} else tag[k] += x;
		}
	}
	return 0;
}