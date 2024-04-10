#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, INF=1e9+7;
vector<int>V[LIM];
int odl[LIM], ile[LIM];
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[b].pb(a);
		++ile[a];
	}
	rep(i, n) odl[i]=INF;
	priority_queue<pair<int,int>>q;
	q.push({0, n-1});
	while(!q.empty()) {
		int o=-q.top().st, p=q.top().nd; q.pop();
		if(odl[p]<=o) continue;
		odl[p]=o;
		for(auto i : V[p]) {
			--ile[i];
			q.push({-o-1-ile[i], i});
		}
	}
	cout << odl[0] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}