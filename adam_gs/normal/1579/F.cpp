#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=1e6+7;
int T[LIM], odw[LIM];
void solve() {
	int n, d;
	cin >> n >> d;
	rep(i, n) cin >> T[i];
	rep(i, n) odw[i]=0;
	int ans=0;
	rep(i, n) if(!odw[i]) {
		vector<int>V;
		int akt=i, sum=0;
		while(!odw[akt]) {
			odw[akt]=1;
			V.pb(T[akt]);
			sum+=T[akt];
			akt=(akt-d+n)%n;
		}
		if(sum==V.size()) {
			cout << -1 << '\n';
			return;
		}
		int pref=0;
		akt=0;
		rep(i, V.size()) {
			if(V[i]) {
				++akt;
				if(akt==i+1) ++pref;
			} else {
				ans=max(ans, akt);
				akt=0;
			}
		}
		ans=max(ans, akt+pref);
	}
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}