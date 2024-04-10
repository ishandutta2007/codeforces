#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
const int LIM=3e5+7;
vector<pair<int,ll>>V[LIM];
ll T[LIM], dp[LIM], ans;
void DFS(int x, int o) {
	for(auto i : V[x]) if(i.st!=o) {
		DFS(i.st, x);
		dp[x]=max(dp[x], dp[i.st]+T[i.st]-i.nd);
	}
}
void DFS2(int x, int o, ll p) {
	p=max(p, 0ll);
	pair<ll,ll>ma={-1, -1};
	for(auto i : V[x]) if(i.st!=o) ma=max(ma, {dp[i.st]+T[i.st]-i.nd, i.st});
	ans=max(ans, max(p, ma.st)+T[x]);
	for(auto i : V[x]) if(i.st!=o) {
		if(i.st!=ma.nd) DFS2(i.st, x, max(p, ma.st)+T[x]-i.nd);
		else {
			ll ma2=p;
			for(auto j : V[x]) if(i.st!=o && i.st!=ma.nd) ma2=max(ma2, dp[i.st]+T[i.st]-i.nd);
			DFS2(i.st, x, ma2+T[x]-i.nd);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	rep(i, n-1) {
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		V[a].pb({b, c});
		V[b].pb({a, c});
	}
	DFS(0, 0);
	DFS2(0, 0, 0);
	cout << ans << '\n';
}