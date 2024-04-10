#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, LG=30;
int F[LIM][LG], ok[LIM][LG];
int fnd(int x, int k) {
	if(F[x][k]==x) return x;
	return F[x][k]=fnd(F[x][k], k);
}
void uni(int a, int b, int k) {
	if(fnd(a, k)==fnd(b, k)) return;
	ok[fnd(a, k)][k]+=ok[fnd(b, k)][k];
	F[fnd(b, k)][k]=fnd(a, k);
}
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, LG) F[i][j]=i;
	while(m--) {
		int a, b, w;
		cin >> a >> b >> w; --a; --b;
		if(w%2==0) rep(i, LG-1) ok[fnd(a, i+1)][i+1]=ok[fnd(b, i+1)][i+1]=1;
		rep(i, LG) if(w&(1<<i)) uni(a, b, i);
	}
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b; --a; --b;
		int ans=2;
		rep(i, LG) if(fnd(a, i)==fnd(b, i)) ans=0;
		rep(i, LG-1) if(ok[fnd(a, i+1)][i+1]) ans=min(ans, 1);
		cout << ans << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}