#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const ll md = 1e9+7;

ll inv(ll a, ll b = md){
	return a>1 ? b - inv(b%a,a)*b/a : 1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;

	vector<vi> ch(n);
	rep(i,1,n){
		int p;
		cin >> p;
		ch[p-1].push_back(i);
	}
	vector<vector<ll>> ways(n, vector<ll>(n+1));

	rrep(i,0,n){
		rep(x,1,n+1){
			ll prod	= 1;
			trav(j, ch[i]) prod = prod * ways[j][x] % md;
			ways[i][x] = (ways[i][x-1] + prod)%md;
		}
	}

	vector<ll> poly(n+2);
	poly[0] = 1;
	rep(x,0,n+1){
		rrep(i,1,n+2) poly[i] = (poly[i-1] - x*poly[i])%md;
		poly[0] = (-x*poly[0])%md;
	}

	vector<ll> ans(n+1);

	rep(x,0,n+1){
		vector<ll> pol = poly;
		vector<ll> lag(n+1);
		rrep(i,0,n+1){
			lag[i] = pol[i+1];
			pol[i] = (pol[i] + x*pol[i+1])%md;
		}
		assert(pol[0] == 0);
		ll res = 0;
		rrep(i,0,n+1)
			res = (res*x + lag[i])%md;
		
		if(res < 0) res += md;
		ll c = ways[0][x] * inv(res) % md;
		
		rep(i,0,n+1) ans[i] = (ans[i] + c*lag[i])%md;
	}

	ll val = 0;
	rrep(i,0,n+1) val = (val*d + ans[i])%md;
	if(val < 0) val += md;
	cout << val << endl;
}