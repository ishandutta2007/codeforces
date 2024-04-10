# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pair <int, int> , int> ppi;
 
# define endl 		'\n'
# define sep 		' '
# define F 			first
# define S 			second
# define pb 		push_back
# define fast_io 			ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const int xn = 2e5+10;
 
int par[xn], sz[xn], c[xn];
 
int get_root(int v){
	if (par[v] == v) return v;
	return par[v] = get_root(par[v]);
}
 
void merge(int v, int u){
	int pv = get_root(v), pu = get_root(u);
	if (pv == pu) return;
	if (sz[pv] < sz[pu]) swap(v, u), swap(pv, pu);
	par[pu] = pv;
	sz[pv] += sz[pu];
}
 
int main(){
	fast_io;
	
	int n, q;
	cin >> n >> q;
	
	for (int i=0; i<=n; i++) par[i] = i, c[i] = i, sz[i] = 1;
	bool fl1 = false;
	
	
	while (q--){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) merge(x, y);
		if (t == 2) {
			int i = x;
			int ls = y;
			while (i < y){
				c[i] = max(c[i], i+1);
				merge(i, c[i]);
				int d = i;
				i = c[i];
				c[d] = max(c[d], y);
			}
		}
		if (t == 3){
			if (get_root(x) == get_root(y)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}