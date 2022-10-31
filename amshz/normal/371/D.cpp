# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 2e5+10;
const int xk = 1e2+10;

int par[xn], sz[xn];
ll a[xn], b[xn];

int get_root(int v){
	if (par[v] == v) return v;
	return par[v] = get_root(par[v]);
}

void merge(int v, int u){
	v = get_root(v), u = get_root(u);
	
	if (v == u) return;
	//if (sz[v] < sz[u]) swap(v, u);
	
	par[v] = u;
	sz[u] += sz[v];
}


int main(){
	fast_io;
	
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=0; i<=n+1; i++) par[i] = i, sz[i] = 1;
	int q;
	cin >> q;
	while (q--){
		int t;
		cin >> t;
		if (t == 1){
			int p;
			ll x;
			cin >> p >> x;
			int i = par[p];
			while (true){
				if (i > n || x == 0) break;
				if (a[i]-b[i] > x){
					b[i] += x;
					break;
				}
				if (a[i]-b[i] == x){
					b[i] = a[i];
					merge(i, i+1);
					x = 0;
					break;
				}
				if (a[i]-b[i] < x){
					x -= (a[i]-b[i]);
					b[i] = a[i];
					merge(i, i+1);
					i = par[i];
				}
			}
		}
		if (t == 2){
			int x;
			cin >> x;
			cout << b[x] << endl;
		}
	}
	
	return 0;
}