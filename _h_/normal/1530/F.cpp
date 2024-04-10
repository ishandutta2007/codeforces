#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int md = 31607, ii = 3973;

int inv(int a, int b = md){
	return a>1 ? b - inv(b%a, a) * b / a : 1;
}

void solve(){
	int n;
	cin >> n;

	vector<vi> ps(n, vi(n)), ips(n, vi(n));
	trav(v, ps) trav(x, v){
		cin >> x;
		x = x * ii % md;
	}
	rep(i,0,n) rep(j,0,n) ips[i][j] = inv(ps[i][j]);

	

	vector<pii> is = { {0, n/2}, {n/2, n} };
	vector<vector<vi>> precalc(2);
	rep(t,0,2){
		int len = is[t].second - is[t].first;
		precalc[t].resize(1 << len, vi(n));
		rep(msk,0,1<<len) rep(j,0,n){
			precalc[t][msk][j] = 1;
			rep(i,is[t].first,is[t].second)
				if(! (msk & (1 << (i-is[t].first))) )
					precalc[t][msk][j] = precalc[t][msk][j] * ps[i][j] % md;
		}
	}

	int ans = 0;

	vi roprob(n, 1);

	rep(i,0,n) rep(j,0,n) roprob[i] = roprob[i] * ps[i][j] % md;

	rep(msk,0,1<<(n+2)){
		int cur = 1;
		rep(i,0,n) if(msk & (1<<i)) cur = cur * roprob[i] % md;

		//cerr << msk << endl;

		if( msk & (1<<n) ) rep(j,0,n) if(! (msk & (1 << j)) ) cur = cur * ps[j][j] % md;
		if( msk & (1<<(n+1)) ) rep(j,0,n) if(! (msk & (1 << (n-1-j))) ) cur = cur * ps[n-1-j][j] % md;

		if((msk & (1<<n)) && (msk & (1<<(n+1))) && n%2 && !(msk & (1<<(n/2)))) cur = cur * ips[n/2][n/2] % md;

		//cerr << cur << endl;

		int i1 = msk & ((1 << (is[0].second))-1);
		int i2 = (msk >> is[1].first) & ((1<<(is[1].second-is[1].first))-1);

		rep(j,0,n){
			int x = precalc[0][i1][j] * precalc[1][i2][j] % md;
			bool boo1 = (msk & (1<<n)) && !(msk & (1<<j));
			bool boo2 = (msk & (1<<(n+1))) && !(msk & (1<<(n-1-j)));
			if(boo1) x = x * ips[j][j] % md;
			if(boo2) x = x * ips[n-1-j][j] % md;
			if(n == 2 * j + 1 && boo1 && boo2) x = x * ps[n/2][n/2] % md;
			cur = cur * (1 - x) % md;	
		}

		//cerr << cur << endl << endl;

		int sig = __builtin_popcount(msk) % 2 ? -1 : 1;
		ans += sig * cur;
		ans %= md;
	}
	ans = 1 - ans;
	ans %= md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	solve();
}