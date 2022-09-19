// I'll Crush you !
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

const ll Mod = 1000000007LL;
const int N = 1048576 + 10;
const int Inf = 1e9;
const ll Log = 30;

vector<pair<int, int> > G[N];
int n;

struct node {
	int a, b, c, A, C;
	int ab, Ab;
	int bc, bC;
	int abc, AbC;
	int lz;
	node(){
		a = b = c = A = C = -Inf;
		ab = Ab = bc = bC = -Inf;
		abc = AbC = -Inf;
		lz = 0;
	}
};

int A[N], p = 0;
int dep[N], dep2[N], st[N], fn[N];
void DFS(int u, int pr, int d = 0, int d2 = 0){
	//cerr << "! " << u << ' ' << p << '\n';
	dep[u] = d;
	dep2[u] = d2;
	st[u] = p;
	A[p] = u; p ++;
	
	for(auto [adj, w] : G[u]){
		//cerr << "# " << adj << ' ' << u << '\n';
		if(adj == pr) continue;
		DFS(adj, u, d + 1, d2 + w);
		A[p] = u; p ++;
	}
	fn[u] = p;
}

node seg[2*N];
void Apply(int id){
	seg[id].lz ^= 1;
	swap(seg[id].A, seg[id].a);
	swap(seg[id].C, seg[id].c);
	swap(seg[id].Ab, seg[id].ab);
	swap(seg[id].bC, seg[id].bc);
	swap(seg[id].AbC, seg[id].abc);
}
void Shift(int id){
	if(seg[id].lz){
		Apply(id << 1);
		Apply(id << 1|1);
		seg[id].lz = 0;
	}
}
void Build(int id, int L, int R){
	if(L + 1 == R){
		if(dep2[A[L]] % 2 == 0){
			seg[id].A = dep[A[L]];
			seg[id].C = dep[A[L]];
			seg[id].Ab = -dep[A[L]];
			seg[id].bC = -dep[A[L]];
		} else {
			seg[id].a = dep[A[L]];
			seg[id].c = dep[A[L]];
			seg[id].ab = -dep[A[L]];
			seg[id].bc = -dep[A[L]];
		}
		seg[id].b = -2*dep[A[L]];
		return ;
	}

	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id << 1 | 1, mid, R);

	seg[id].A = max(seg[id << 1].A, seg[id << 1 | 1].A);
	seg[id].C = max(seg[id << 1].C, seg[id << 1 | 1].C);
	seg[id].a = max(seg[id << 1].a, seg[id << 1 | 1].a);
	seg[id].c = max(seg[id << 1].c, seg[id << 1 | 1].c);
	seg[id].b = max(seg[id << 1].b, seg[id << 1 | 1].b);

	seg[id].Ab = max({seg[id << 1].Ab, seg[id << 1 | 1].Ab, seg[id << 1].A + seg[id << 1 | 1].b});
	seg[id].ab = max({seg[id << 1].ab, seg[id << 1 | 1].ab, seg[id << 1].a + seg[id << 1 | 1].b});
	seg[id].bC = max({seg[id << 1].bC, seg[id << 1 | 1].bC, seg[id << 1].b + seg[id << 1 | 1].C});
	seg[id].bc = max({seg[id << 1].bc, seg[id << 1 | 1].bc, seg[id << 1].b + seg[id << 1 | 1].c});

	seg[id].AbC = max({seg[id << 1].AbC, seg[id << 1 | 1].AbC, seg[id << 1].A+seg[id <<1|1].bC, seg[id << 1].Ab+seg[id <<1|1].C});	
	seg[id].abc = max({seg[id << 1].abc, seg[id << 1 | 1].abc, seg[id << 1].a+seg[id <<1|1].bc, seg[id << 1].ab+seg[id <<1|1].c});

}
void Rev(int id, int l, int r, int L, int R){
	if(r <= L || R <= l) return ;
	if(l <= L && R <= r){
		Apply(id);
		return ;
	}

	Shift(id);
	int mid = (L + R) >> 1;
	Rev(id << 1, l, r, L, mid);
	Rev(id << 1 | 1, l, r, mid, R);

	seg[id].A = max(seg[id << 1].A, seg[id << 1 | 1].A);
	seg[id].C = max(seg[id << 1].C, seg[id << 1 | 1].C);
	seg[id].a = max(seg[id << 1].a, seg[id << 1 | 1].a);
	seg[id].c = max(seg[id << 1].c, seg[id << 1 | 1].c);
	seg[id].b = max(seg[id << 1].b, seg[id << 1 | 1].b);

	seg[id].Ab = max({seg[id << 1].Ab, seg[id << 1 | 1].Ab, seg[id << 1].A + seg[id << 1 | 1].b});
	seg[id].ab = max({seg[id << 1].ab, seg[id << 1 | 1].ab, seg[id << 1].a + seg[id << 1 | 1].b});
	seg[id].bC = max({seg[id << 1].bC, seg[id << 1 | 1].bC, seg[id << 1].b + seg[id << 1 | 1].C});
	seg[id].bc = max({seg[id << 1].bc, seg[id << 1 | 1].bc, seg[id << 1].b + seg[id << 1 | 1].c});

	seg[id].AbC = max({seg[id << 1].AbC, seg[id << 1 | 1].AbC, seg[id << 1].A+seg[id <<1|1].bC, seg[id << 1].Ab+seg[id <<1|1].C});
	
	seg[id].abc = max({seg[id << 1].abc, seg[id << 1 | 1].abc, seg[id << 1].a+seg[id <<1|1].bc, seg[id << 1].ab+seg[id <<1|1].c});
}

int U[N], V[N];

int main(){
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//cin >> n;
	scanf("%d", &n);
	int u, v, w;
	for(int i = 1; i < n; i++){
		//cin >> u >> v >> w;
		
		scanf("%d%d%d", &u, &v, &w);
		G[u].pb({v, w});
		G[v].pb({u, w});
		U[i] = u;
		V[i] = v;
	}
	DFS(1, -1);
	int m, id;
	scanf("%d", &m);
	int x;



	Build(1, 0, p);
	//printf("! %d\n", max(seg[1].abc, seg[1].AbC));
	for(int i = 0; i < m; i++){
		scanf("%d", &id);
		if(dep[U[id]] > dep[V[id]]) x = U[id];
		else x = V[id];
		Rev(1, st[x], fn[x], 0, p);
		printf("%d\n", max({0, seg[1].abc, seg[1].AbC}));
		//cout <<  <<'\n';
	}
	return 0;
}
/*
5
1 2 0
1 3 0
3 5 1
3 4 1
5
3
4
1
3
4

*/