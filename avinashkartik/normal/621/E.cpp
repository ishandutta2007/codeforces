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
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k, x, b, ct[12];

struct matrix{
	vector <vll> mat;
	int n, m;
	matrix(): mat(), n(), m() {}
	matrix(vector <vll> v): mat(v), n(v.size()), m(v[0].size()) {}
	matrix operator *(matrix b){
		vector <vll> v(n, vll(m, 0));
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

matrix fastmod(matrix mat, ll y = mod - 2){
	vector <vll> v(x, vll(x, 0));
	for(int i = 0; i < x; i++) v[i][i] = 1;
	matrix res(v);
	while(y){
		if(y&1) res = res * mat;
		mat = mat * mat;
		y /= 2;
	}
	return res;
}

void solve(){
	cin >> n >> b >> k >> x;
	for(int i = 0; i < n; i++){
		int y; cin >> y;
		ct[y % x]++;
	}
	vector <vll> v(x, vll(x, 0));
	for(int i = 0; i < x; i++){
		for(int j = 0; j < min(10ll, x); j++){
			v[i][(10 * i + j) % x] += ct[j];
		}
	}
	matrix res(v);
	res = fastmod(res, b);
	deb1(res.mat[0][k])
	
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}