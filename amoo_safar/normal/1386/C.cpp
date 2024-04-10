// Null
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef pair<int, int> pii;

const int N = 2e5 + 10;

int n, m, q;
int par[N], sz[N], w[N], fr[N], to[N];

pii helper;
pii Find(int u){
	int co = 0;
	while(u != par[u]){
		co ^= w[u];
		u = par[u];
	}
	return pii(u, co);
}

vector<int> His;
void Merge(int u, int v){
	pii U = Find(u), V = Find(v);
	if(U.F == V.F){
		His.pb(-1);
		assert(U.S != V.S);
		return ;
	}
	if(sz[U.F] > sz[V.F]) swap(U, V);

	His.pb(U.F);
	par[U.F] = V.F;
	w[U.F] = 1 ^ U.S ^ V.S;
	sz[V.F] += sz[U.F];
}
void Undo(){
	assert(!His.empty());
	int u = His.back(); His.pop_back();
	if(u == -1) return ;
	sz[par[u]] -= sz[u];
	par[u] = u;
	w[u] = 0;
}
bool CanMerge(int u, int v){
	return Find(u) != Find(v);
}
void Reset(){
	while(!His.empty()) Undo();	
}


int opt[N];

void Solve(int l, int r, int la){
	if(r - l <= 0) return ;
	int mid = (l + r) >> 1;
	for(int i = l; i < mid; i++) Merge(fr[i], to[i]);
	if(mid + 1 < r){
		Merge(fr[mid], to[mid]);
		Solve(mid + 1, r, la);
		Undo();
	}
	opt[mid] = la;
	while(CanMerge(fr[opt[mid] - 1], to[opt[mid] - 1])){
		opt[mid] --;
		Merge(fr[opt[mid]], to[opt[mid]]);
	}
	int cnt = (mid - l) + (la - opt[mid]);
	for(int i = 0; i < cnt; i++) Undo();

	for(int i = opt[mid]; i < la; i++) Merge(fr[i], to[i]);
	Solve(l, mid, opt[mid]);
	cnt = (la - opt[mid]);
	for(int i = 0; i < cnt; i++) Undo();
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	iota(par, par + N, 0);
	fill(sz, sz + N, 1);

	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++){
		cin >> fr[i] >> to[i];
	}

	int mxl = 0;
	for(int j = 1; j <= m; j++){
		if(!CanMerge(fr[j], to[j])){
			break;
		}
		Merge(fr[j], to[j]);
		mxl = j;
	}
	if(mxl == m){
		for(int i = 0; i < q; i++) cout << "NO\n";
		return 0;
	}
	Reset();

	Solve(1, mxl + 2, m + 1);
	for(int i = 1; i <= mxl; i++) assert(i < opt[i]);
	int l, r;
	for(int i = 1; i <= q; i++){
		cin >> l >> r; r++;
		assert(l < r);
		if(mxl + 1 < l) cout << "YES\n";
		else if(r < opt[l]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}