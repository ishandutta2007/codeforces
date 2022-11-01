# include <bits/stdc++.h>
 
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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e6 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, a[xn], b[xn], mx, ptr, d[xn], cnt, Tab[xn], H[xn];
vector <pii> adj[xn], compress;
queue <int> q;
bool f[xn], mark[xn];

void DFS(int v){
	f[v] = true;
	for (pii u : adj[v]){
		if (mark[u.B])
			continue;
		if (f[u.A]){
			cnt += H[u.A] < H[v];
			continue;
		}
		mark[u.B] = true;
		H[u.A] = H[v] + 1;
		DFS(u.A);
	}
}
bool check(int x){
	for (int i = 1; i <= ptr; ++ i)
		f[i] = bool(i > x);
	while (SZ(q)) q.pop();
	for (int i = 1; i <= n; ++ i){
		d[i] = 2 - f[b[i]];
		mark[i] = false;
		if (d[i] == 1)
			q.push(i), mark[i] = true;
	}
	while (SZ(q)){
		int i = q.front();
		q.pop();
		if (f[a[i]] && f[b[i]])
			return false;
		if (f[a[i]]){
			for (pii j : adj[b[i]])
				if (!mark[j.B] && -- d[j.B] == 1)
					q.push(j.B), mark[j.B] = true;	
		}
		else{
			for (pii j : adj[a[i]])
				if (!mark[j.B] && -- d[j.B] == 1)
					q.push(j.B), mark[j.B] = true;
			
		}
		f[a[i]] = f[b[i]] = true;
	}
	for (int i = 1; i <= ptr; ++ i){
		if (f[i]) continue;
		cnt = 0;
		DFS(i);
		if (cnt > 1)
			return false;
	}
	return true;
}

int main(){
	InTheNameOfGod;
    
    cin >> n;
    for (int i = 1; i <= n; ++ i){
    	cin >> a[i] >> b[i];
    	compress.push_back({a[i], i});
    	compress.push_back({b[i], i});
	}
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i){
		if (!i || compress[i].A != compress[i - 1].A)
			++ ptr;
		if (a[compress[i].B] == compress[i].A)
			a[compress[i].B] = ptr;
		else
			b[compress[i].B] = ptr;
		Tab[ptr] = compress[i].A;
	}
	for (int i = 1; i <= n; ++ i){
		adj[a[i]].push_back({b[i], i});
		adj[b[i]].push_back({a[i], i});
		mx = max(mx, a[i]);
	}
	int l = mx - 1, r = ptr + 1, mid;
	while (r - l > 1){
		mid = l + r >> 1;
		if (check(mid))	r = mid;
		else l = mid;
	}
	if (r > ptr) kill(- 1);
	cout << Tab[r] << endl;
	
    return 0;
}