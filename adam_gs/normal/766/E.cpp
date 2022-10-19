#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, LG=20;
vector<int>V[LIM], q;
ll T[LIM], ile[LIM], ma[LIM], zdj[LIM], ans, zcent, bity[LG][2];
void DFS(int x, int o) {
	q.pb(x);
	ile[x]=1;
	ma[x]=0;
	for(auto i : V[x]) if(!zdj[i] && i!=o) DFS(i, x);
	for(auto i : V[x]) if(!zdj[i] && i!=o) {
		ma[x]=max(ma[x], ile[i]);
		ile[x]+=ile[i];
	}
}
int znajdz(int x) {
	DFS(x, -1);
	for(auto i : q) {
		ma[i]=max(ma[i], ile[x]-ile[i]);
		if(ma[i]<=ile[x]/2) {
			q.clear();
			return i;
		}
	}
	return 2137;
}
void licz(int x, int o, ll p, ll d) {
	rep(i, LG) {
		if(p&(1<<i)) bity[i][1]+=d;
		else bity[i][0]+=d;
	}
	for(auto i : V[x]) if(!zdj[i] && i!=o) licz(i, x, p^T[i], d);
}
void licz2(int x, int o, ll p) {
	rep(i, LG) {
		if(p&(1<<i)) {
			ans+=bity[i][0]*(1<<i);
		} else ans+=bity[i][1]*(1<<i);
	}
	for(auto i : V[x]) if(!zdj[i] && i!=o) licz2(i, x, p^T[i]);
}
void licz3(int x, int o, ll p) {
	zcent+=p;
	for(auto i : V[x]) if(!zdj[i] && i!=o) licz3(i, x, p^T[i]);
}
void cd(int x) {
	int p=znajdz(x);
	zdj[p]=1;
	rep(i, LG) bity[i][0]=bity[i][1]=0;
	licz3(p, -1, T[p]);
	for(auto i : V[p]) if(!zdj[i]) licz(i, p, T[i], 1);
	for(auto i : V[p]) if(!zdj[i]) {
		licz(i, p, T[i], -1);
		licz2(i, p, T[i]^T[p]);
		licz(i, p, T[i], 1);
	}
	for(auto i : V[p]) if(!zdj[i]) cd(i);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	cd(0);
	ans/=2; ans+=zcent;
	cout << ans << '\n';
}