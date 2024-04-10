#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
int T, n, m, k;
int row[N], col[N], x[N], y[N];
map<int, bool> R, C;
map<int, VI> A, B;
VI X, Y;
void solve() {
	X.clear();
	Y.clear();
	R.clear();
	C.clear();
	A.clear();
	B.clear();
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n) scanf("%d", &row[i]), R[row[i]] = 1;
	rep(i, 1, m) scanf("%d", &col[i]), C[col[i]] = 1;
	rep(i, 1, k) scanf("%d%d", &x[i], &y[i]);
	rep(i, 1, k) X.pb(x[i]), Y.pb(y[i]), A[x[i]].pb(y[i]), B[y[i]].pb(x[i]);
	for(auto u : A) sort(all(A[u.fi]));
	for(auto u : B) sort(all(B[u.fi]));
	sort(all(X));
	sort(all(Y));
	ll ans = 0;
	rep(i, 1, k) {
		if(R.count(x[i]) == 0) {
			int L, R;
			int pos = upper_bound(row + 1, row + n + 1, x[i]) - row;
			if(pos == n + 1) R = inf;
			else R = row[pos];
			if(pos == 1) L = -inf;
			else L = row[pos - 1];
			int cur = ((lower_bound(all(X), R) - 1) - (upper_bound(all(X), L) - 1)) - ((lower_bound(all(B[y[i]]), R) - 1) - (upper_bound(all(B[y[i]]), L) - 1));
			ans += cur;
			// printf("ROW %d %d\n", i, cur);
			// printf("(%d %d)\n", L, R);
		}
		if(C.count(y[i]) == 0) {
			int L, R;
			int pos = upper_bound(col + 1, col + m + 1, y[i]) - col;
			if(pos == m + 1) R = inf;
			else R = col[pos];
			if(pos == 1) L = -inf;
			else L = col[pos - 1];
			int cur = ((lower_bound(all(Y), R) - 1) - (upper_bound(all(Y), L) - 1)) - ((lower_bound(all(A[x[i]]), R) - 1) - (upper_bound(all(A[x[i]]), L) - 1));
			ans += cur;
			// printf("COL %d %d\n", i, cur);
			// printf("(%d %d)\n", L, R);
		}
	}
	printf("%lld\n", ans / 2);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}