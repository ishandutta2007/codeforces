#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,int> pii;

ll calc(int len, int pieces){
	if(pieces > len)
		return (ll)(len+100);
	int lng = len % pieces;
	int sht = pieces - lng;
	ll shtlen = len / pieces;
	return shtlen * shtlen * sht + (shtlen + 1) * (shtlen + 1) * lng;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;

	vi a(n), cur(n, 1);
	trav(x, a) cin >> x;

	auto dif = [&](int i){
		return calc(a[i], cur[i])
		     - calc(a[i], cur[i]+1);
	};

	priority_queue<pii> gain;
	rep(i,0,n){
		gain.push({dif(i), i});
	}

	rep(_,0,k-n){
		pii p = gain.top(); gain.pop();
		int i = p.second;
		++cur[i];
		gain.push({dif(i), i});
	}
	ll ans = 0;
	rep(i,0,n) ans += calc(a[i], cur[i]);
	cout << ans << endl;
}