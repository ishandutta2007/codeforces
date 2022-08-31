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
 
typedef  int             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const int  INFi  =  1e8;

ll n, m;

struct matrix{
	vector <vll> mat;
	int n, m;
	matrix(): mat(), n(), m() {}
	matrix(vector <vll> v): mat(v), n(v.size()), m(v[0].size()) {}
	matrix operator *(matrix b){
		vector <vll> v(n, vll(m, -INFi));
		matrix res(v);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < m; k++){
					res.mat[i][j] = max({res.mat[i][j], mat[i][k] + b.mat[k][j], b.mat[i][j]});
				}
			}
		}
		return res;
	}
	void print(){
		for(auto it : mat){ debv(it) }
	}
};

matrix res[10];

matrix fastmod(ll y){
	vector <vll> v(n, vll(n, -INFi));
	for(int i = 0; i < n; i++) v[i][i] = 0;
	matrix mat(v);
	for(int i = 0; i < 9; i++){
		if((y >> i)&1){
			mat = mat * res[i];
		}
	}
	return mat;
}

void solve(){
	cin >> n >> m;
	vector <vll> c(n, vll(n, -INFi));
	for(int i = 1; i <= m; i++){
		int u, v, cij, cji; cin >> u >> v >> cij >> cji;
		c[u - 1][v - 1] = cij;
		c[v - 1][u - 1] = cji;
	}
	res[0] = c;
	for(int i = 1; i < 9; i++) res[i] = res[i - 1] * res[i - 1];
	int l = 1, r = n + 1, ans = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		matrix mat = fastmod(mid);
		int f = 0;
		for(int i = 0; i < n; i++) f |= (mat.mat[i][i] > 0);
		if(f){
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
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