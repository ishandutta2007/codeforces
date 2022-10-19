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
int pri[N], notp[N], tot;
void getPri() {
	rep(i, 2, 1000000) {
		if(!notp[i]) {pri[++tot] = i;}
		for(int j = 1; j <= tot && i * pri[j] <= 1000000; ++j) {
			notp[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}
int n, e, a[N], l[N];
void solve() {
	scanf("%d%d", &n, &e);
	rep(i, 1, n) scanf("%d", &a[i]);
	ll ans = 0;
	rep(j, 1, e) {
		for(int i = j; i <= n; i += e) {
			if(i - e <= 0) l[i] = i - e;
			else if(a[i - e] == 1) l[i] = l[i - e];
			else l[i] = i - e;
			if(a[i] == 1) {
				if(l[i] > 0) {
					if(!notp[a[l[i]]]) {
						ans += (l[i] - l[l[i]]) / e;
					}
				}
			} else if(!notp[a[i]]) {
				ans += (i - l[i] - e) / e;
			}
		}
	}
	printf("%lld\n", ans);

}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	getPri();
	int T;
	for(scanf("%d", &T); T; T--) solve();
	return 0;
}