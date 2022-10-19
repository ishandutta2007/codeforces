#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=1e9+7;
void solve() {
	int n;
	cin >> n;
	int mi=INF, ma=-INF, c1=INF, c2=INF, dl=0, c3=INF;
	rep(i, n) {
		int l, r, c;
		cin >> l >> r >> c;
		if(r-l+1>dl) {
			dl=r-l+1;
			c3=INF;
		}
		if(r-l+1==dl) c3=min(c3, c);
		if(l<mi) {
			mi=l;
			c1=INF;
		}
		if(l==mi) c1=min(c1, c);
		if(r>ma) {
			ma=r;
			c2=INF;
		}
		if(r==ma) c2=min(c2, c);
		if(dl==ma-mi+1) cout << min(c1+c2, c3) << '\n';
		else cout << c1+c2 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}