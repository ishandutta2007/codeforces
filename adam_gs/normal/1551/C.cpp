#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
void solve() {
	int n;
	cin >> n;
	string T[n];
	rep(i, n) cin >> T[i];
	int ile[n][5];
	rep(i, n) {
		rep(j, 5) ile[i][j]=0;
		for(auto j : T[i]) {
			++ile[i][j-'a'];
		}
	}
	int ans=0;
	rep(lider, 5) {
		int suma[n];
		rep(i, n) {
			suma[i]=0;
			for(auto j : T[i]) {
				if(j-'a'==lider) ++suma[i];
				else --suma[i];
			}
		}
		sort(suma, suma+n);
		reverse(suma, suma+n);
		int aktsum=0, akt=0;
		rep(i, n) {
			if(aktsum+suma[i]<=0) break;
			aktsum+=suma[i];
			++akt;
		}
		ans=max(ans, akt);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}