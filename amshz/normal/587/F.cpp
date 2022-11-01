//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize ("O2")
# pragma GCC optimize ("unroll-loops")

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 300;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
const int SIG = 26;

int n, q, col[xn], F[xn], nxt[SIG][xn], TM;
int stm[xn], ftm[xn], ptr, Q[xn], fen[xn];
ll ps[2][xn], ans[xn];
string S[xn];
vector <int> adj[xn], vec[xn], vrt[xn];
vector <pii> query[2][xn];
vector <ppi> que[xn];

void build_aho(){
	int L = 0, R = 0;
	for (int i = 0; i < SIG; ++ i)
		if (nxt[i][0])
			Q[R ++] = nxt[i][0];
	while (L < R){
		int v = Q[L ++];
		adj[F[v]].push_back(v);
		for (int i = 0; i < SIG; ++ i){
			if (nxt[i][v])
				F[nxt[i][v]] = nxt[i][F[v]], Q[R ++] = nxt[i][v];
			else
				nxt[i][v] = nxt[i][F[v]];
		}
	}
}
void preDFS(int v){
	stm[v] = TM ++;
	for (int u : adj[v])
		preDFS(u);
	ftm[v] = TM;
}
void mofen(int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[pos] += val;
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; pos > 0; pos -= pos & - pos)
		res += fen[pos];
	return res;
}
void DFS(int v){
	for (int u : adj[v])
		DFS(u), ps[0][v] += ps[0][u];
	for (int id : vrt[v])
		ps[1][id] += ps[0][v];
}

int main(){
	InTheNameOfGod;

	cin >> n >> q;
	for (int i = 1; i <= n; ++ i){
		cin >> S[i];
		int v = 0;
		for (int j = 0; j < SZ(S[i]); ++ j){
			int c = S[i][j] - 'a';
			if (!nxt[c][v])
				nxt[c][v] = ++ ptr;
			v = nxt[c][v];
			vec[i].push_back(v);
		}
		vrt[v].push_back(i);
		col[i] = v;
	}
	build_aho(), preDFS(0);
	for (int i = 0; i < q; ++ i){
		int l, r, k;
		cin >> l >> r >> k;
		if (SZ(S[k]) <= sq){
			query[0][r].push_back({k, i});
			query[1][l - 1].push_back({k, i});
		}
		else
			que[k].push_back({{l, r}, i});
	}
	for (int i = 0; i <= n; ++ i){
		mofen(stm[col[i]], 1);
		mofen(ftm[col[i]], - 1);
		for (pii id : query[0][i])
			for (int v : vec[id.A])
				ans[id.B] += gefen(stm[v]);
		for (pii id : query[1][i])
			for (int v : vec[id.A])
				ans[id.B] -= gefen(stm[v]);
	}
	for (int i = 1; i <= n; ++ i){
		if (SZ(S[i]) <= sq)
			continue;
		for (int v : vec[i])
			++ ps[0][v];
		DFS(0);
		for (int j = 1; j <= n; ++ j)
			ps[1][j] += ps[1][j - 1];
		for (ppi x : que[i])
			ans[x.B] = ps[1][x.A.B] - ps[1][x.A.A - 1];
		memset(ps, 0, sizeof ps);
	}
	for (int i = 0; i < q; ++ i)
		cout << ans[i] << endl;

	return 0;
}