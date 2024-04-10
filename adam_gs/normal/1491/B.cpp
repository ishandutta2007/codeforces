#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
void solve() {
	int n, u, v;
	cin >> n >> u >> v;
	int T[n];
	rep(i, n) cin >> T[i];
	int ma=0;
	rep(i, n-1) {
		int p=abs(T[i]-T[i+1]);
		ma=max(ma, p);
	}
	if(ma==0) {
		cout << v+min(u, v) << '\n';
	} else if(ma==1) {
		cout << min(u, v) << '\n';
	} else {
		cout << 0 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	//t=1;
	while(t--) solve();
}