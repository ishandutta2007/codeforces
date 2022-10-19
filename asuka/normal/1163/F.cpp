#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;
int n, m, T, U[N], V[N], W[N], from[N], L[N], R[N], ord[N], tot;
ll dis[2][N], Min[N];
priority_queue<pair<ll, int>> q;
VI e[N];
vector<ll> add[N], del[N];
bool used[N];
int get(int E, int u) {return u ^ U[E] ^ V[E];}
void dij(int s, ll dis[]) {
	fill(dis + 1, dis + n + 1, infll);
	dis[s] = 0;
	q.push(mp(0, s));
	while(SZ(q)) {
		int u = q.top().se;
		q.pop();
		for(auto E : e[u]) {
			int v = get(E, u), w = W[E];
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				from[v] = E;
				q.push(mp(-dis[v], v));
				if(s == 1) L[v] = used[v] ? ord[E] : L[u];
				if(s == n) R[v] = used[v] ? ord[E] : R[u];
			}
		}
	}
}
void getpath(int u) {
	used[u] = 1;
	// printf("path: %d\n", u);
	if(u == 1) return;
	getpath(get(from[u], u));
	ord[from[u]] = ++tot;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &T);
	rep(i, 1, m) {
		scanf("%d%d%d", &U[i], &V[i], &W[i]);
		e[U[i]].pb(i);
		e[V[i]].pb(i);
	}
	dij(1, dis[0]);
	getpath(n);
	L[1] = 0; R[n] = tot + 1;
	dij(1, dis[0]);
	dij(n, dis[1]);
	rep(i, 1, m) {
		if(ord[i] > 0) continue;
		int u = U[i], v = V[i];
		rep(_, 0, 1) {
			ll w = W[i] + dis[0][u] + dis[1][v];
			if(L[u] + 1 < R[v]) {
				add[L[u] + 1].pb(w);
				del[R[v]].pb(w);
			}
			swap(u, v);
		}
	}	
	multiset<ll> S;
	rep(i, 1, tot) {
		for(auto x : add[i]) S.insert(x);
		for(auto x : del[i]) S.erase(S.find(x));
		Min[i] = SZ(S) ? *S.begin() : infll;
	}
	while(T --> 0) {
		int t, x;
		scanf("%d%d", &t, &x);
		ll ans = min({dis[0][U[t]] + dis[1][V[t]] + x, dis[1][U[t]] + dis[0][V[t]] + x, ord[t] > 0 ? Min[ord[t]] : dis[0][n]});
		printf("%lld\n", ans);
	}
	return 0;
}