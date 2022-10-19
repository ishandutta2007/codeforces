#include<bits/stdc++.h>
#define ll long long
#define N 300015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
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
const int mod = 998244353;
int n, m, k, f[N], fa[N], nxt[N], pre[N], siz[N], cnt[N];
bool ok[N];
VI a[N], vec;
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void uni(int x, int y) {
	if(~nxt[x] && nxt[x] != y) ok[x] = ok[y] = 0;
	if(~pre[y] && pre[y] != x) ok[x] = ok[y] = 0;
	if(nxt[x] != y && find(x) == find(y)) ok[x] = ok[y] = 0;
	nxt[x] = y;
	pre[y] = x;
	fa[find(x)] = find(y);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d%d", &n, &m, &k);
 	rep(i, 1, n) {
 		int len;
 		scanf("%d", &len);
 		a[i].resize(len + 1);
 		rep(j, 1, len) scanf("%d", &a[i][j]);
 	}
 	rep(i, 1, k) fa[i] = i, ok[i] = 1, nxt[i] = pre[i] = -1;
 	rep(i, 1, n) {
 		rep(j, 1, SZ(a[i]) - 2) uni(a[i][j], a[i][j + 1]);
 	}
 	rep(i, 1, k) {
 		if(!ok[i]) ok[find(i)] = 0;
 		siz[find(i)]++;
 	}
 	rep(i, 1, k) {
 		if(find(i) == i && ok[i]) {
 			cnt[siz[i]]++;
 		}
 	}
 	rep(i, 1, k) if(cnt[i]) vec.pb(i);
 	f[0] = 1;
 	rep(i, 1, m) for(auto x : vec) if(i >= x) (f[i] += (ll) f[i - x] * cnt[x] % mod) %= mod;
 	printf("%d\n", f[m]);
	return 0;
}