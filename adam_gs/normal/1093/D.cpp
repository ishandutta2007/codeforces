#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=3e5+7, INF=1e9+7;
const ll MOD=998244353;
vector<int>V[LIM];
int odl[LIM];
ll pot[LIM];
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		odl[i]=INF;
		V[i].clear();
	}
	rep(i, m) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	ll ans=1;
	rep(i, n) if(odl[i]==INF) {
		odl[i]=0;
		queue<int>q;
		q.push(i);
		ll ile[2]; ile[0]=ile[1]=0;
		while(!q.empty()) {
			int p=q.front(); q.pop();
			++ile[odl[p]%2];
			for(auto i : V[p]) {
				if(odl[i]==INF) {
					odl[i]=odl[p]+1;
					q.push(i);
				} else if(odl[i]%2==odl[p]%2) {
					cout << "0\n";
					return;
				}
			}
		}
		ll akt=(pot[ile[0]]+pot[ile[1]])%MOD;
		ans=(ans*akt)%MOD;
	}
	cout << ans << '\n';
}
int main() {
	pot[0]=1;
	for(int i=1; i<LIM; ++i) pot[i]=(2*pot[i-1])%MOD;
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}