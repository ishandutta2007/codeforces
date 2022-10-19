#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=67, INF=1e9+7;
vector<int>V[4*LIM*LIM];
ll ile[LIM], odl[LIM], n;
ll cykl(int x) {
	rep(i, n) odl[i]=INF;
	odl[x]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty()) {
		int p=q.front(); q.pop();
		for(auto i : V[p]) {
			if(odl[i]==INF) {
				odl[i]=odl[p]+1;
				q.push(i);
			} else if(odl[p]<=odl[i]) {
				return odl[p]+odl[i]+1;
			}
		}
	}
	return INF;
}
void solve() {
	cin >> n;
	vector<ll>T;
	while(n--) {
		ll a;
		cin >> a;
		if(!a) continue;
		T.pb(a);
		rep(i, 60) if(a&(1ll<<i)) ++ile[i];
	}
	rep(i, LIM) if(ile[i]>2) {
		cout << 3 << '\n';
		return;
	}
	n=T.size();
	if(!n) {
		cout << -1 << '\n';
		return;
	}
	rep(i, n) rep(j, i) if(T[i]&T[j]) {
		V[i].pb(j);
		V[j].pb(i);
	}
	ll ans=INF;
	rep(i, n) ans=min(ans, cykl(i));
	if(ans==INF) ans=-1;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}