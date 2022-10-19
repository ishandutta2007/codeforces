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
int n, c[N], tot, cnt[N];
vector<pii> vec;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		vec.pb(mp(u, v));
	}
	rep(i ,1, n) scanf("%d", &c[i]);
	for(auto x : vec) {
		int u = x.fi, v = x.se;
		if(c[u] != c[v]) {
			tot++;
			cnt[u]++;
			cnt[v]++;
		}
	}
	int ans = -1;
	rep(i, 1, n) {
		if(cnt[i] == tot) {
			ans = i;
			break;
		}
	}
	if(ans == -1) printf("NO\n");
	else {
		printf("YES\n");
		printf("%d\n", ans);
	}
	return 0;
}