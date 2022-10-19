#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=5e5+7;
vector<int>V[LIM], T[LIM], maski[LIM], pref[LIM];
int p[LIM], k[LIM], r[LIM], l;
void DFS(int x, int o) {
	++l;
	p[x]=l;
	T[o].pb(p[x]);
	maski[o].pb(1<<r[x]);
	for(auto i : V[x]) DFS(i, o+1);
	k[x]=l;
}
int ile(int x) {
	int ans=0;
	while(x) {
		ans+=x%2;
		x/=2;
	}
	return ans;
}
void solve() {
	int n, m;
	cin >> n >> m;
	rep(i, n-1) {
		int a;
		cin >> a; --a;
		V[a].pb(i+1);
	}
	string x;
	cin >> x;
	rep(i, n) r[i]=x[i]-'a';
	DFS(0, 0);
	rep(i, n) {
		for(auto j : maski[i]) {
			if(!pref[i].size()) pref[i].pb(j);
			else pref[i].pb(pref[i].back()^j);
		}
	}
	while(m--) {
		int v, h;
		cin >> v >> h; --v; --h;
		auto it1=upper_bound(all(T[h]), k[v]);
		auto it2=lower_bound(all(T[h]), p[v]);
		int b=it1-T[h].begin(), a=it2-T[h].begin();
		--a; --b;
		if(b==-1) {
			cout << "Yes\n";
			continue;
		}
		int c=0;
		if(a>=0) c=pref[h][a];
		c^=pref[h][b];
		cout << (ile(c)>1?"No":"Yes") << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}