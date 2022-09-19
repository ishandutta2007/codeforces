// That's How much we have in common
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n, m, q;
int p[N];

int del[N];
int u[N], v[N];

vector<int> C[N];
int com[N];
bool Unite(int u, int v){
	u = com[u]; v = com[v];
	if(u == v) return false;
	if(com[u] > com[v]) swap(u, v);
	for(auto x : C[u]){
		C[v].pb(x);
		com[x] = v;
	}
	C[u].clear();
	return true;
}
int ty[N], qu[N];

int idx[N];
pii sts[N];


pii seg[N << 2];
void Set(int id, int idx, int v, int L, int R){
	if(L + 1 == R){
		seg[id] = {v, L};
		return ;
	}
	int mid = (L + R) >> 1;
	if(idx < mid)
		Set(id << 1, idx, v, L, mid);
	else
		Set(id << 1 | 1, idx, v, mid, R);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
pii Get(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return pii(-1, 0);
	if(l <= L && R <= r) return seg[id];
	int mid = (L + R) >> 1;
	return max(Get(id << 1, l, r, L, mid), Get(id << 1 | 1, l, r, mid, R));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fill(seg, seg + (N << 2), pii(0, 0));

	for(int i = 0; i < N; i++){
		com[i] = i;
		C[i] = {i};
	}
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	for(int i = 1; i <= m; i++)
		cin >> u[i] >> v[i];

	vector<int> ord;
	for(int i = 1; i <= q; i++){
		cin >> ty[i] >> qu[i];
		if(ty[i] == 2){
			ord.pb(qu[i]);
			del[qu[i]] = 1;
		}
	}

	for(int i = 1; i <= m; i++){
		if(del[i] == 0){
			ord.pb(i);
		}		
	}
	reverse(all(ord));
	for(auto i : ord){
		if(com[u[i]] != com[v[i]]){
			sts[i] = {C[com[u[i]]][0], C[com[v[i]]][0]};
			Unite(u[i], v[i]);
		} else {
			sts[i] = {-1, -1};
		}
	}
	set<pii> st;
	int la = 0;
	for(int i = 1; i <= n; i++){
		if(!C[i].empty()){
			int L = la;
			for(auto x : C[i])
				idx[x] = la ++;
			st.insert({L, la});
		}
	}

	//for(auto x : st) cerr << "! " << x.F << ' ' << x.S << '\n';
	st.insert({n + 1, n + 1});
	for(int i = 1; i <= n; i++){
		Set(1, idx[i], p[i], 0, n);
	}
	int pos;
	for(int i = 1; i <= q; i++){
		/*
		cerr << '\n';
		for(auto x : st) cerr << "! " << x.F << ' ' << x.S << '\n';
		cerr << '\n';
		*/
		if(ty[i] == 1){
			pos = idx[qu[i]];
			pii sg = *prev(st.lower_bound({pos, n + 10}));
			pii res = Get(1, sg.F, sg.S, 0, n);
			cout << res.F << '\n';
			Set(1, res.S, 0, 0, n);
		} else {
			if(sts[qu[i]] == pii(-1, -1)) continue;
			int lf = min(idx[sts[qu[i]].F], idx[sts[qu[i]].S]);
			int rt = max(idx[sts[qu[i]].F], idx[sts[qu[i]].S]);
			pii sg = *st.lower_bound({lf, -1});
			st.erase(sg);
			//cerr << "# " << lf << ' ' << rt << ' ' << sg.F << ' ' << sg.S << '\n';
			st.insert({sg.F, rt});
			st.insert({rt, sg.S});
		}
	}
	return 0;
}