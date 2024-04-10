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
	int T[n], pref[n], suf[n];
	rep(i, n) cin >> T[i];
	pref[0]=T[0];
	suf[n-1]=T[n-1];
	for(int i=1; i<n; ++i) pref[i]=pref[i-1]^T[i];
	for(int i=n-2; i>=0; --i) suf[i]=suf[i+1]^T[i];
	bool ans=false;
	rep(i, n-1) if(pref[i]==suf[i+1]) ans=true;
	rep(i, n-1) {
		for(int j=i+1; j<n-1; ++j) {
			if(pref[i]==suf[j+1] && suf[j+1]==(pref[j]^pref[i])) {
				ans=true;
			}
		}
	}
	cout << (ans?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}