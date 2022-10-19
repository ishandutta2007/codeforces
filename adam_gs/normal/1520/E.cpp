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
const ll INF=1e18+7;
void solve() {
	int n;
	string x;
	cin >> n >> x;
	vector<int>V, kiedy;
	rep(i, n) if(x[i]=='*') V.pb(i);
	ll akt=0, dodaj=0, odejmij=0;
	for(int i=0; i<V.size(); ++i) {
		akt+=V[i]-i;
		kiedy.pb(V[i]-i);
		++odejmij;
	}
	ll ans=akt;
	sort(all(kiedy));
	int l=0;
	for(int i=1; i<n; ++i) {
		while(l<kiedy.size() && kiedy[l]<i) {
			--odejmij;
			++dodaj;
			++l;
		}
		akt+=dodaj;
		akt-=odejmij;
		ans=min(ans, akt);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	cin >> t;
	while(t--) solve();
}