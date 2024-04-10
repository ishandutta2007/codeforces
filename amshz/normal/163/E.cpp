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

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
const int SIG = 26;

int n, k, F[xn], nxt[SIG][xn], ptr, fen[xn];
int stm[xn], ftm[xn], TM, Q[xn], col[xn];
string S, T;
vector <int> adj[xn];
bool mark[xn];

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

int main(){
	InTheNameOfGod;

	cin >> n >> k;
	for (int i = 1; i <= k; ++ i){
		cin >> S;
		int v = 0;
		for (int j = 0; j < SZ(S); ++ j){
			int c = S[j] - 'a';
			if (!nxt[c][v])
				nxt[c][v] = ++ ptr;
			v = nxt[c][v];
		}
		col[i] = v;
	}
	build_aho(), preDFS(0);
	for (int i = 1; i <= k; ++ i){
		mark[i] = true;
		mofen(stm[col[i]], 1);
		mofen(ftm[col[i]], - 1);
	}
	for (int i = 1; i <= n; ++ i){
		cin >> T;
		if (T[0] == '+'){
			int ind = 0;
			for (int j = 1; j < SZ(T); ++ j)
				ind = ind * 10 + (T[j] - '0');
			if (mark[ind])
				continue;
			mark[ind] = true;
			ind = col[ind];
			mofen(stm[ind], 1), mofen(ftm[ind], - 1);
		}
		else if (T[0] == '-'){
			int ind = 0;
			for (int j = 1; j < SZ(T); ++ j)
				ind = ind * 10 + (T[j] - '0');
			if (!mark[ind])
				continue;
			mark[ind] = false;
			ind = col[ind];
			mofen(stm[ind], - 1), mofen(ftm[ind], 1);
		}
		else{
			ll ans = 0;
			int v = 0;
			for (int j = 1; j < SZ(T); ++ j){
				v = nxt[T[j] - 'a'][v];
				if (v)
					ans += gefen(stm[v]);
			}
			cout << ans << endl;
		}
	}

	return 0;
}