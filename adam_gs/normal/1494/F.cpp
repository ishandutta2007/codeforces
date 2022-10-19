#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e3+7;
vector<int>euler;
vector<pair<int,int>>V[LIM];
pair<int,int>kraw[LIM];
int deg[LIM], T[LIM], F[LIM], odw[LIM], spojne;
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
	if(fnd(a)==fnd(b)) return;
	F[fnd(b)]=fnd(a);
	--spojne;
}
void DFS(int x) {
	while(V[x].size()) {
		int a=V[x].back().st, b=V[x].back().nd;
		V[x].pop_back();
		if(odw[b]) continue;
		odw[b]=1;
		DFS(a);
		euler.pb(x);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		cin >> kraw[i].st >> kraw[i].nd;
		--kraw[i].st; --kraw[i].nd;
	}
	rep(i, n) {
		rep(j, n) deg[j]=T[j]=0;
		rep(j, m) {
			++deg[kraw[j].st];
			++deg[kraw[j].nd];
		}
		rep(j, m) {
			if(kraw[j].nd==i) swap(kraw[j].st, kraw[j].nd);
			if(kraw[j].st==i) {
				if(deg[kraw[j].nd]%2) {
					--deg[kraw[j].nd];
					--deg[i];
					T[kraw[j].nd]=1;
				}
			}
		}
		int sum=0;
		rep(j, n) if(j!=i) sum+=deg[j]%2;
		if(sum>1) continue;
		vector<int>A;
		spojne=n;
		rep(j, n) {
			V[j].clear();
			F[j]=j;
			if(!deg[j]) --spojne;
		}
		rep(j, m+2) odw[j]=0;
		rep(j, m) {
			if(kraw[j].st==i && T[kraw[j].nd]) A.pb(kraw[j].nd);
			else {
				V[kraw[j].st].pb({kraw[j].nd, j});
				V[kraw[j].nd].pb({kraw[j].st, j});
				uni(kraw[j].st, kraw[j].nd);
			}
		}
		if(spojne>2) continue;
		if(!deg[i] || spojne==2) {
			if(sum==1) continue;
			rep(j, m) if(kraw[j].st==i && deg[kraw[j].nd] && fnd(i)!=fnd(kraw[j].nd)) {
				uni(i, kraw[j].nd);
				++deg[kraw[j].nd];
				++deg[i];
				V[i].pb({kraw[j].nd, j});
				V[kraw[j].nd].pb({i, j});
				vector<int>B;
				for(auto l : A) if(l!=kraw[j].nd) B.pb(l);
				A=B;
				break;
			}
		}
		if(spojne>1) continue;
		if(deg[i]%2==0) {
			DFS(i);
			reverse(all(euler));
			euler.pb(i);
		} else {
			V[n].clear();
			V[n].pb({i, m});
			V[i].pb({n, m});
			rep(j, n) if(i!=j && deg[j]%2==1) {
				V[n].pb({j, m+1});
				V[j].pb({n, m+1});
			}
			DFS(n);
			euler.pop_back();
			reverse(all(euler));
		}
		if(!euler.size()) euler.pb(i);
		ll k=euler.size();
		if(A.size()) k+=2*A.size()+1;
		cout << k << '\n';
		for(auto j : euler) cout << j+1 << " ";
		if(A.size()) cout << -1 << " ";
		for(auto j : A) cout << j+1 << " " << i+1 << " ";
		cout << '\n';
		return 0;
	}
	cout << 0 << '\n';
}