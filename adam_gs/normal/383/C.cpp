#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
vector<int>V[LIM];
int T[LIM], odl[LIM], pre[LIM], post[LIM], tr[4*LIM], N=1, lpre;
void DFS(int x, int o) {
	++lpre;
	pre[x]=lpre;
	for(auto i : V[x]) if(i!=o) {
		odl[i]=-odl[x];
		DFS(i, x);
	}
	post[x]=lpre;
}
void upd(int l, int r, int x) {
	l+=N; r+=N;
	tr[l]+=x;
	if(l!=r) tr[r]+=x;
	while(l/2!=r/2) {
		if(l%2==0) tr[l+1]+=x;
		if(r%2==1) tr[r-1]+=x;
		l/=2; r/=2;
	}
}
int cnt(int v) {
	v+=N;
	int ans=0;
	while(v) {
		ans+=tr[v];
		v/=2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	while(N<=n) N*=2;
	rep(i, n) cin >> T[i];
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	odl[0]=1;
	DFS(0, 0);
	rep(i, n) upd(pre[i], pre[i], T[i]*odl[i]);
	while(m--) {
		int t, x;
		cin >> t >> x; --x;
		if(t==1) {
			int a;
			cin >> a;
			upd(pre[x], post[x], a*odl[x]);
		} else cout << cnt(pre[x])*odl[x] << '\n';
	}
}