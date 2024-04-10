#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	int pref=0, ans=0, suf=0, l=n-1;
	rep(i, n) {
		pref+=T[i];
		while(l>i && suf+T[l]<=pref) {
			suf+=T[l];
			--l;
		}
		if(pref==suf) ans=max(ans, i+n-l);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}