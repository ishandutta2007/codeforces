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

const ll md = 998244353;

const ll inv(ll a, ll b = md){
	return a>1 ? b - inv(b%a,a)*b/a : 1LL;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n, m, k;
	cin >> n >> m >> k;

	ll ans = m;
	rep(_,0,k) ans = ans * (m-1) % md;
	rep(i,0,k) ans = ans * (n-1-i) % md;
	ll denom = 1;
	rep(i,1,k+1) denom = denom * i % md;
	ans = ans * inv(denom) % md;
	cout << ans << endl;
}