# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, c[xn], sz[xn], par[xn], a[xn], sum;
pair <int, pii> E[xn];

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	a[v] += a[u];
}

bool check(int x){
	for (int i = 1; i <= n; ++ i)
		sz[i] = 1, par[i] = i, a[i] = c[i];
	for (int i = 1; i <= n - 1; ++ i)
		if (E[i].A < x)
			merge(E[i].B.A, E[i].B.B);
	for (int i = 1; i <= n; ++ i)
		if (get_root(i) == i && sum - a[i] < sz[i])
			return false;
	return true;
}

int main(){
    InTheNameOfGod;
    
	cin >> n;
	for (int i = 1; i <= n - 1; ++ i)
		cin >> E[i].B.A >> E[i].B.B >> E[i].A;
	for (int i = 1; i <= n; ++ i)
		cin >> c[i], sum += c[i];
	int l = 0, r = inf;
	while (r - l > 1){
		int mid = l + r >> 1;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << endl;
 
    return 0;
}