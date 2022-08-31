#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e5+5;
const ll   mod   =  1e9+6;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, c, p, q, r, A[5];
set <int> s;

struct matrix{
	vector <vll> mat;
	int n, m;
	matrix(vector <vll> v): mat(v), n(v.size()), m(v[0].size()) {}
	matrix operator *(matrix b){
		vector <vll> v(n);
		for(int i = 0; i < n; i++) v[i].resize(m, 0);
		matrix res(v);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < m; k++){
					res.mat[i][j] += mat[i][k] * b.mat[k][j];
					res.mat[i][j] %= mod;
				}
			}
		}
		return res;
	}
	void print(){
		for(auto it : mat){ debv(it) }
	}
};

matrix fastmod(matrix x, ll y = mod - 2){
	vector <vll> v(1, vll(3, 0));
	for(int i = 0; i < 3; i++) v[0][i] = A[i];
	matrix res(v);
	while(y){
		if(y&1) res = res * x;
		x = x * x;
		y /= 2;
	}
	return res;
}

ll fastmod(ll x, ll y = 1e9+5){
	ll mod = 1e9+7;
	ll res = 1;
	while(y){
		if(y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

ll fact(ll x, ll p){
	ll ct = 0;
	while(x % p == 0){
		x /= p;
		ct++;
	}
	return ct;
}

ll calc(ll pr){
	vector <vll> adj(3, vll(3, 0));
	adj[1][0] = adj[2][1] = 1;
	adj[0][2] = adj[1][2] = adj[2][2] = 1;
	matrix res(adj);
	ll ct = fact(c, pr);
	A[0] = fact(p, pr) + ct;
	A[1] = fact(q, pr) + 2 * ct;
	A[2] = fact(r, pr) + 3 * ct;
	res = fastmod(res, n - 3);
	//deb1(res.mat[0][2])
	return res.mat[0][2];
}

void factorise(ll x){
	for(ll i = 2; i*i <= x; i++){
		if(x%i == 0){
			s.insert(i);
			while(x%i == 0) x /= i;
		}
	}
	if(x > 1) s.insert(x);
}

void solve(){
	cin >> n >> p >> q >> r >> c;
	factorise(p);
	factorise(q);
	factorise(r);
	factorise(c);
	ll ans = 1;
	for(auto i : s){
		ans = ans * fastmod(i, calc(i)) % (mod + 1);
	}
	ans = ans * fastmod(fastmod(c, n)) % (mod + 1);
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}