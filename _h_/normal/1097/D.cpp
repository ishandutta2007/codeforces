#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const ll md = 1e9+7;

ll inv(ll a, ll b = md){
	return a>1 ? b - inv(b%a, a)*b/a : 1LL;
}

const int mx = 50;

vector<vl> mul(vector<vl> &a, vector<vl> &b){
	int n = sz(a);

	vector<vl> res(n, vl(n));

	rep(i,0,n) rep(j,0,n) rep(k,0,n)
		res[i][j] += a[i][k] * b[k][j] % md;
	rep(i,0,n) rep(j,0,n) res[i][j] %= md;
	return res;
}

vector<vl> res(mx, vl(mx));

ll calc(ll p, ll e){
	ll ans = 0;
	ll q = 1;
	rep(i,0,e+1){
		ans += q * res[e][i] % md;
		q = q * p % md;
	}
	ans %= md;
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n;
	int k;
	cin >> n >> k;

	vector<vl> mat(mx, vl(mx));

	rep(i,0,mx) res[i][i] = 1;
	rep(i,0,mx) rep(j,0,i+1)
		mat[i][j] = inv(i+1);
	
	while(k){
		if(k&1) res = mul(res, mat);
		mat = mul(mat, mat);
		k /= 2;
	}

	ll s = sqrtl(n);
	while(s*s > n) --s;
	while(s*s <= n) ++s;
	int to = s;
	vi ls;
	rep(i,1,to) if(n%i == 0){
		ls.push_back(i);	
	}

	ll ans = 1;
	trav(d, ls) if(d > 1 && n%d==0){
		int e = 0;	
		while(n%d==0){
			++e;
			n /= d;
		}
		ans = ans * calc(d, e) % md;
	}
	if(n > 1) ans = ans * calc(n, 1) % md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}