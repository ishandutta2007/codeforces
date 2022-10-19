#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
int qpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int n, m, q;
pii col[N], row[N], R, C, ext; // 101010... / 010101
map<pii, int> M;
void updR(int x, int v) {
	if(row[x].fi == 0 && row[x].se == 0) R.fi += v; // 2 choices
	else if(row[x].fi == 0 || row[x].se == 0) R.se += v; // 1 choices;

}
void updC(int y, int v) {
	if(col[y].fi == 0 && col[y].se == 0) C.fi += v; // 2;
	else if(col[y].fi == 0 || col[y].se == 0) C.se += v;
}
void modify(int x, int y, int c) {
	int o = M.count(mp(x, y)) > 0 ? M[mp(x, y)] : -1;
	updR(x, -1);
	// printf("Rx %d %d\n", R.fi, R.se);
	if(~o) {
		if((y & 1) == (o & 1)) row[x].fi--;
		else row[x].se--;
	}
	if(~c) {
		if((y & 1) == (c & 1)) row[x].fi++;
		else row[x].se++;
	}
	// printf("row %d %d\n", row[x].fi, row[x].se);
	updR(x, 1);
	// printf("RRx %d %d\n", R.fi, R.se);
	updC(y, -1);
	if(~o) {
		if((x & 1) == (o & 1)) col[y].fi--;
		else col[y].se--;
	}
	if(~c) {
		if((x & 1) == (c & 1)) col[y].fi++;
		else col[y].se++;
	}
	updC(y, 1);
	M[mp(x, y)] = c;
	if(~o) {
		if(((x + y) & 1) == o) ext.fi--;
		else ext.se--;
	}
	if(~c) {
		if(((x + y) & 1) == c) ext.fi++;
		else ext.se++;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d%d", &n, &m, &q);
 	R.fi = n;
 	C.fi = m;
 	while(q--) {
 		int x, y, c;
 		scanf("%d%d%d", &x, &y, &c);
 		modify(x, y, c);
 		// printf("RC %d %d %d %d\n", R.fi, R.se, C.fi, C.se);
 		// printf("ext %d %d\n", ext.fi, ext.se);
 		int ans = qpow(2, R.fi) * (R.fi + R.se == n) + qpow(2, C.fi) * (C.fi + C.se == m);
 		if(ext.fi == 0 && ext.se == 0) ans -= 2;
 		else if(ext.fi == 0 || ext.se == 0) ans -= 1;
 		printf("%d\n", ans % mod);
 	}
	return 0;
}