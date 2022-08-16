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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, k, b[N];

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
					res.mat[i][j] %= (mod - 1);
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
	vector <vll> v(1, vll(k, 0));
	v[0][k - 1] = 1;
	matrix res(v);
	while(y){
		if(y&1) res = res * x;
		x = x * x;
		y /= 2;
	}
	return res;
}

ll powmod(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return res;
}

ll bsgs(ll a, ll b, ll m) {
    a %= m, b %= m;
    int n = sqrt(m) + 1;
    map<ll, ll> vals;
    for (int p = 1; p <= n; ++p)
        vals[powmod(a, p * n, m)] = p;
    for (int q = 0; q <= n; ++q) {
        ll cur = (powmod(a, q, m) * 1ll * b) % m;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}

void solve(){
	cin >> k;
	for(int i = 0; i < k; i++) cin >> b[i];
	cin >> n >> m;
	vector <vll> v(k, vll(k, 0));
	for(int i = 0; i < k - 1; i++) v[i + 1][i] = 1;
	for(int i = 0; i < k; i++) v[i][k - 1] = b[k - i - 1];
	matrix res(v);
	res = fastmod(res, n - k);
	ll x = res.mat[0][k - 1];
	ll y  = bsgs(powmod(3, x, mod), m, mod);
	if(y != -1) deb1(powmod(3, y, mod))
	else deb1(-1)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}