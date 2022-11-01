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

const int xn = 2e2 + 10;
const int xm = - 20 + 10;
const int sq = 300;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e6 + 7;//998244353;
const int base = 257;
const int SIG = 26;

struct matrix{
    ll n, m, a[xn][xn];
    matrix(int n1, int m1, ll x = - INF){
        n = n1; m = m1;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                a[i][j] = x;
    }
    matrix operator * (const matrix &t){
        matrix r = matrix(n, t.m);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < t.m; j ++)
                for (int k = 0; k < m; k ++)
                    r.a[i][j] = max(r.a[i][j], a[i][k] + t.a[k][j]);
        return r;
    }
    matrix operator = (const int &t){
    	for (int i = 0; i < n; ++ i)
    		for (int j = 0; j < m; ++ j)
    			a[i][j] = t;
	}
};
matrix Pow(matrix a, ll b){
    matrix res = matrix(a.n, a.m);
    for (int i = 0; i < a.n; i ++)
    	res.a[i][i] = 0;
    for (; b; b = b >> 1){
        if (b & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}

int n, a[xn], F[xn], nxt[SIG][xn];
int ahoq[xn], ptr, ps[xn], par[xn];
ll l, ans;
string S;
vector <int> vec[xn], adj[xn];

void build_aho(){
	int L = 0, R = 0;
	for (int i = 0; i < SIG; ++ i)
		if (nxt[i][0])
			ahoq[R ++] = nxt[i][0];
	while (L < R){
		int v = ahoq[L ++];
		adj[F[v]].push_back(v);
		for (int i = 0; i < SIG; ++ i){
			if (nxt[i][v])
				F[nxt[i][v]] = nxt[i][F[v]], ahoq[R ++] = nxt[i][v];
			else
				nxt[i][v] = nxt[i][F[v]];
		}
	}
}
void DFS(int v){
	vec[v].push_back(v);
	for (int u : adj[v]){
		ps[u] += ps[v];
		DFS(u);
		for (int x : vec[u])
			vec[v].push_back(x);
	}
}

int main(){
	InTheNameOfGod;

	cin >> n >> l;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i){
		cin >> S;
		int v = 0;
		for (int j = 0; j < SZ(S); ++ j){
			int c = S[j] - 'a';
			if (!nxt[c][v])
				nxt[c][v] = ++ ptr;
			par[nxt[c][v]] = v;
			v = nxt[c][v];
		}
		ps[v] += a[i];
	}
	matrix m(ptr + 1, 1), c(ptr + 1, ptr + 1);
	build_aho(), DFS(0);
	for (int i = 0; i <= ptr; ++ i)
		for (int v : vec[par[i]])
			c.a[i][v] = ps[i];
	m.a[0][0] = 0;
	m = Pow(c, l) * m;
	for (int i = 0; i <= ptr; ++ i)
		ans = max(ans, m.a[i][0]);
	cout << ans << endl;

	return 0;
}