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

const ll md = 1e9+7;

ll tv[60];

void solve(){
	int n;
	cin >> n;
	vector<ll> xs(n);
	trav(x, xs) cin >> x;
	vi cnt(60);
	trav(x, xs) rep(i,0,60) if(x & (1LL << i)) ++cnt[i];
	ll ans = 0;
	trav(j, xs){
		ll f1 = 0, f2 = 0;
		rep(t,0,60){
			if(j & (1LL << t)){
				f2 = (f2 + n * tv[t]) % md;
				f1 = (f1 + cnt[t] * tv[t]) % md;
			} else f2 = (f2 + cnt[t] * tv[t]) % md;
		}
		ans = (ans + f1 * f2) % md;
	}
	cout << ans << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	tv[0] = 1;
	rep(i,1,60) tv[i] = tv[i-1] * 2 % md;

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}