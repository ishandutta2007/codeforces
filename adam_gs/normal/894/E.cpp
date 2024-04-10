#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e6+7;
vector<pair<int,ll>>V[LIM], Vp[LIM], S[LIM];
int sp[LIM], l, in[LIM];
ll dp[LIM], su[LIM];
stack<int>q;
void DFS(int x) {
	sp[x]=1;
	for(auto i : V[x]) if(!sp[i.st]) DFS(i.st);
	q.push(x);
}
void DFS2(int x) {
	sp[x]=l;
	for(auto i : Vp[x]) if(!sp[i.st]) DFS2(i.st);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(ll i=1; i<LIM; ++i) {
		su[i]=su[i-1]+i*(i+1)/2;
	}
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		V[a].pb({b, c});
		Vp[b].pb({a, c});
	}
	rep(i, n) if(!sp[i]) DFS(i);
	rep(i, n) sp[i]=0;
	while(!q.empty()) {
		int p=q.top(); q.pop();
		if(sp[p]) continue;
		++l;
		DFS2(p);
	}
	rep(i, n) for(auto j : V[i]) {
		if(sp[i]==sp[j.st]) {
			j.nd*=2;
			ll z=sqrt(j.nd);
			if(z*(z+1)>j.nd) --z;
			j.nd/=2;
			dp[sp[i]]+=(z+1)*j.nd-su[z];
		}
		else {
			S[sp[i]].pb({sp[j.st], j.nd});
			++in[sp[j.st]];
		}
	}
	vector<int>topo;
	queue<int>ko;
	rep(i, l) if(!in[i+1]) ko.push(i+1);
	while(!ko.empty()) {
		int p=ko.front(); ko.pop();
		topo.pb(p);
		for(auto i : S[p]) {
			--in[i.st];
			if(!in[i.st]) ko.push(i.st);
		}
	}
	reverse(all(topo));
	for(auto i : topo) {
		ll ma=0;
		for(auto j : S[i]) ma=max(ma, j.nd+dp[j.st]);
		dp[i]+=ma;
	}
	int s;
	cin >> s; --s;
	cout << dp[sp[s]] << '\n';
}