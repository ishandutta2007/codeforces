#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 1e9+7;

ll inv(ll a, ll b = md){
	return a-1 ? b - b*inv(b%a, a)/a : 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<ll> vs(n);
	trav(x, vs) cin >> x;
	bool bo = 0;
	while(n%4 != 1){
		vector<ll> us(n-1);
		rep(i,0,n-1){
			if(bo) us[i] = vs[i] - vs[i+1];
			else us[i] = vs[i] + vs[i+1];
			bo = !bo;
		}
		n--;
		vs = us;
	}
	trav(x, vs) x %= md;
	ll ans = 0, c = 1;
	ll m = (n+1)/2;
	rep(i,0,m){
		ans += c*vs[2*i] % md;
		c = c * (m-i-1) % md;
		c = c * inv(i+1) % md;
	}
	ans %= md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}