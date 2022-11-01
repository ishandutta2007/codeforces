# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 3e5+10;
const int xm = 1e6+10;
const int xk = 1e4+10;
const int SQ = 500;
const int sq = 6e2+10;
const ll inf = 1e18+10;


int D[xm], n, m, par[xn], R[xm];
ll a[xn], b[sq];
bool flag[xn], p[xm];

int get_D(int x){
	int ans = 1;
	while (x > 1){
		int k = R[x], t = 0;
		while (x%k == 0) x /= k, t++;
		ans *= (t+1);
	}
	return ans;
}

int get_root(int v){
	if (v == par[v]) return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u) return;
	par[v] = u;
}
void Build(){
	for (int i = 0; i < n; i++) b[i/SQ] += a[i];
}

void update(int l, int r){
	l = get_root(l);
	for (int i = l; i <= r;){
		b[i/SQ] -= a[i], a[i] = D[a[i]], b[i/SQ] += a[i];
		if (a[i] <= 2) merge(i, i+1);
		i = get_root(i + 1);
	}
}
ll get(int l, int r){
	ll ans = 0;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r) ans += b[i/SQ], i += SQ;
		else ans += a[i], i++;
	}
	return ans;
}

 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i], par[i] = i;
	par[n] = n;
	
	for (int i = 1; i <= 1e6; i++) R[i] = i;
	
	for (int i = 2; i <= 1e6; i++){
		if (p[i]) continue;
		for (int j = i+i; j <= 1e6; j += i) p[j] = true, R[j] = min(R[j], i);
	}
	
	for (int i = 1; i <= 1e6; i++) D[i] = get_D(i);
	
	
	Build();
	
	while (m--){
		int x, y, z;
		cin >> x >> y >> z;
		y--, z--;
		if (x == 1) update(y, z);
		else cout << get(y, z) << endl;
	}
	
	
	return 0;
}