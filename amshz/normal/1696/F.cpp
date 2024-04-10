//khodaya khodet komak kon
# include <bits/stdc++.h>

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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, d[xn][xn], f[xn], H[xn][xn];
bool flag[xn][xn][xn], mark[xn];
set <pii> st;
vector <int> adj[xn];
vector <pii> E;

void solve(){
	if (!SZ(st))
		return;
	int v = st.begin() -> B;
	st.erase(st.begin());
	//cout << "barg : " << v << endl;
	//cout << f[v] << endl;
	mark[v] = true;
	for (int i = 1; i <= n; ++ i){
		if (mark[i])
			continue;
		for (int j = 1; j <= n; ++ j){
			if (mark[j])
				continue;
			st.erase({- f[i], i});
			f[i] -= !d[i][j];
			d[i][j] -= flag[i][j][v];
			f[i] += !d[i][j];
			st.insert({- f[i], i});
		}
	}
	solve();
	int last = - 1, cnt = 0, lst;
	for (int i = 1; i <= n; ++ i){
		cnt += !mark[i];
		if (!mark[i])
			lst = i;
		if (mark[i] || !SZ(adj[i]))
			continue;
		int u = adj[i][0];
		if (flag[i][v][u])
			last = i;
	}
	if (cnt == 1)
		last = lst;
	mark[v] = false;
	//cout << v << " : " << last << endl;
	if (last == - 1)
		return;
	adj[v].push_back(last);
	adj[last].push_back(v);
	E.push_back({v, last});
}
void DFS(int rt, int v, int p = - 1){
	for (int u : adj[v]){
		if (u == p)
		 	continue;
		H[rt][u] = H[rt][v] + 1;
		DFS(rt, u, v);
	}
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				for (int k = 1; k <= n; ++ k)
					flag[i][j][k] = (j == k);
		for (int i = 1; i <= n; ++ i){
			for (int j = i + 1; j <= n; ++ j){
				string S;
				cin >> S;
				for (int k = 1; k <= n; ++ k)
					flag[k][i][j] = flag[k][j][i] = (S[k - 1] - '0');
			}
		}
		st.clear();
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= n; ++ j)
				d[i][j] = - 1;
			f[i] = 0;
			for (int j = 1; j <= n; ++ j){
				for (int k = 1; k <= n; ++ k){
					d[i][j] += flag[i][j][k];
				}
				if (!d[i][j])
					++ f[i];
			}
			st.insert({- f[i], i});
			mark[i] = false;
			adj[i].clear();
		}
		E.clear();
		solve();
		if (SZ(E) != n - 1){
			cout << "No" << endl;
			continue;
		}
		for (int i = 1; i <= n; ++ i){
			H[i][i] = 0;
			DFS(i, i);
		}
		bool is_ans = true;
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= n; ++ j){
				for (int k = 1; k <= n; ++ k){
					is_ans &= (flag[i][j][k] == (H[i][j] == H[i][k]));
				}
			}
		}
		if (is_ans){
			cout << "Yes" << endl;
			for (pii e : E)
				cout << e.A << sep << e.B << endl;
		}
		else{
			cout << "No" << endl;
		}
	}

	return 0;
}