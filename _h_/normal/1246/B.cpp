// written by aitch
// on 2019 10/26 at 17:47:34
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

const int mx = 1e5+1;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vi pf(mx);
	rep(p,2,mx) if(!pf[p]){
		for(int q = p; q < mx; q += p)
			pf[q] = p;
	}

	map<ll, int> cnt;
	ll ans = 0;

	rep(_,0,n){
		int a;
		cin >> a;
		int conj = 1, res = 1;
		while(a>1){
			int p = pf[a];
			int e = 0;
			while(a % p == 0){
				++e;
				a /= p;
			}
			e %= k;
			if(e){
				rep(_,e,k){
					if(ll(conj * p) >= mx) conj = 0;
					conj *= p;
				}
				rep(_,0,e) res *= p;
			}
		}
		ans += cnt[res];
		++cnt[conj];
	}
	cout << ans << endl;
}