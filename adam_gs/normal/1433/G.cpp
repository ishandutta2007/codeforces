#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e3+7, INF=1e9+7;
vector<pair<int,int>>V[LIM], kraw, sciezki;
int odl[LIM][LIM];
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		V[a].pb({b, c});
		V[b].pb({a, c});
		kraw.pb({a, b});
	}
	rep(i, n) {
		rep(j, n) odl[i][j]=INF;
		priority_queue<pair<int,int>>q;
		q.push({0, i});
		while(!q.empty()) {
			int o=-q.top().st, p=q.top().nd; q.pop();
			if(odl[i][p]!=INF) continue;
			odl[i][p]=o;
			for(auto j : V[p]) if(odl[i][j.st]==INF) {
				q.push({-o-j.nd, j.st});
			}
		}
	}
	int ans=0;
	rep(i, k) {
		int a, b;
		cin >> a >> b; --a; --b;
		sciezki.pb({a, b});
		ans+=odl[a][b];
	}
	for(auto i : kraw) {
		int akt=0;
		for(auto j : sciezki) {
			int p=odl[j.st][j.nd];
			p=min(p, odl[j.st][i.st]+odl[i.nd][j.nd]);
			p=min(p, odl[j.st][i.nd]+odl[i.st][j.nd]);
			akt+=p;
		}
		ans=min(ans, akt);
	}
	cout << ans << '\n';
}