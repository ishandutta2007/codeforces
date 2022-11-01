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

const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, m, d[xn], par[xn], H[xn], col[xn], ptr, last, ted, sts, dist[xn];
pii mn;
vector <int> adj[xn], ans, vec, vc2, dgs;
queue <int> q;
bool mark[xn], flag, f[xn];

void DFS3(int v, int c){
	mark[v] = true;
	vec.push_back(v);
	col[v] = c;
	for (int u : adj[v]){
		if (u == par[v] || d[u] % 3 == 1)
			continue;
		par[u] = v;
		H[u] = H[v] + 1;
		DFS3(u, c);
	}
}
void DFS2(int v){
	if (d[v] % 3 == 1 && par[v] + 1 && !flag){
		flag = true;
		int res = v;
		while (par[res] + 1)
			ans.push_back(res), res = par[res];
		ans.push_back(res);
	}
	mark[v] = true;
	for (int u : adj[v])
		if (!mark[u])
			par[u] = v, DFS2(u);
}
void DFS(int v){
	mark[v] = true;
	for (int u : adj[v]){
		if (u == par[v] || d[u] % 3 == 1)
			continue;
		if (mark[u]){
			if (H[v] < H[u] + 2)
				continue;
			if (mn.A == - 1 || H[v] - H[u] < H[mn.A] - H[mn.B])
				mn = {v, u};
			continue;
		}
		par[u] = v;
		H[u] = H[v] + 1;
		DFS(u);
	}
}
void add(int v, int u){
	if (H[u] < H[v])
		swap(v, u);
	while (H[v] < H[u])
		ans.push_back(u), u = par[u];
	while (v != u){
		ans.push_back(v);
		ans.push_back(u);
		v = par[v], u = par[u];
	}
	ans.push_back(v);
}
void check(){
	if (SZ(ans) == 0 || SZ(ans) == n){
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	fill(f, f + n + 1, false);
	for (int v : ans)
		f[v] = true;
	cout << n - SZ(ans) << endl;
	for (int i = 1; i <= n; ++ i)
		if (!f[i])
			cout << i << sep;
	for (int i = 1; i <= n; ++ i){
		if (!f[i])
			continue;
		int x = 0;
		for (int u : adj[i])
			x += f[u];
		if (x % 3 != d[i] % 3 && ptr == 2 && sts == - 1)
			assert(0);
	}
	cout << endl;
}

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i)
			adj[i].clear(), d[i] = 0;
		ans.clear();
		dgs.clear();
		sts = - 1;
		while (m --){
			int v, u;
			cin >> v >> u;
			adj[v].push_back(u);
			adj[u].push_back(v);
			++ d[v], ++ d[u];
		}
		last = - 1;
		for (int i = 1; i <= n; ++ i)
			if (d[i] % 3 == 0)
				last = i;
		if (last + 1){
			ans.push_back(last);
			check();
			continue;
		}
		fill(mark, mark + n + 1, false);
		fill(par, par + n + 1, - 1);
		flag = false;
		fill(H, H + n + 1, 0);
		mn = {- 1, - 1};
		for (int i = 1; i <= n; ++ i)
			if (!mark[i] && d[i] % 3 == 2)
				DFS(i);
		if (mn.A + 1){
			int res = mn.A;
			while (res != mn.B)
				ans.push_back(res), res = par[res];
			ans.push_back(res);
			sts = 2;
			check();
			continue;
		}
		last = - 1, ted = 0;
		for (int i = 1; i <= n; ++ i)
			if (d[i] % 3 == 1)
				last = i, ++ ted;
		fill(par, par + n + 1, - 1);
		fill(mark, mark + n + 1, false);
		fill(dist, dist + n + 1, - 1);
		dist[last] = 0, q.push(last);
		while (SZ(q)){
			int v = q.front();
			q.pop();
			if (v != last && d[v] % 3 == 1 && !flag){
				flag = true;
				int res = v;
				while (res != last)
					ans.push_back(res), res = par[res];
				ans.push_back(res);
			}
			for (int u : adj[v])
				if (dist[u] == - 1)
					q.push(u), dist[u] = dist[v] + 1, par[u] = v;
		}
		if (flag){
			check();
			continue;
		}
		fill(f, f + n + 1, false);
		for (int u : adj[last])
			f[u] = true;
		fill(par, par + n + 1, - 1);
		fill(mark, mark + n + 1, false);
		fill(col + 1, col + n + 1, 0);
		ptr = 0;
		sts = 1;
		for (int i = 1; i <= n; ++ i){
			if (mark[i] || i == last)
				continue;
			H[i] = 0;
			++ ptr;
			vec.clear();
			DFS3(i, ptr);
			ted = 0;
			for (int v : vec)
				ted += f[v];
			dgs.push_back(ted);
			if (ted % 3 == 1){
				flag = true;
				for (int v : vec)
					ans.push_back(v);
				ans.push_back(last);
				break;
			}
			if (ted % 3 == 0){
				fill(f, f + n + 1, false);
				for (int v : vec)
					f[v] = true;
				for (int j = 1; j <= n; ++ j)
					if (!f[j])
						ans.push_back(j);
				flag = true;
				break;
			}
			if (2 < ted){ 
				vc2.clear();
				for (int v : vec)
					if (f[v])
						vc2.push_back(v);
				add(vc2[0], vc2[1]);
				fill(f, f + n + 1, false);
				for (int v : vec)
					f[v] = true;
				for (int j = 1; j <= n; ++ j)
					if (!f[j])
						ans.push_back(j);
				flag = true;
				break;
			}
		}
		if (flag){
			check();
			continue;
		}
		if (2 < ptr){
			ans.push_back(last);
			for (int i = 1; i <= n; ++ i)
				if (col[i] < 3 && i != last)
					ans.push_back(i);
			check();
			continue;
		}
		cout << "No" << endl;
	}

	return 0;
}