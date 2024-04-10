#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
vector<int>V[LIM];
int odl[LIM];
void DFS(int x, int o) {
	for(auto i : V[x]) if(i!=o) {
		odl[i]=odl[x]+1;
		DFS(i, x);
	}
}
void solve() {
	int n, x, y, da, db;
	cin >> n >> x >> y >> da >> db; --x; --y;
	rep(i, n) V[i].clear();
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	odl[0]=0;
	DFS(0, 0);
	int ma=-1, jaki=-1;
	rep(i, n) if(odl[i]>ma) {
		ma=odl[i];
		jaki=i;
	}
	odl[jaki]=0;
	DFS(jaki, jaki);
	int sr=0;
	rep(i, n) sr=max(sr, odl[i]);
	if(min(sr, db)<=2*da) {
		cout << "Alice\n";
		return;
	}
	odl[x]=0;
	DFS(x, x);
	cout << (odl[y]<=da?"Alice":"Bob") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}