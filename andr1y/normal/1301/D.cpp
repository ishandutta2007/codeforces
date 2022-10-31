#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 2e5+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

python solve(){
	FAST;
	ll n, m, k;
	cin >> n >> m >> k;
	ll ee = 4*n*m - 2*n - 2*m;
	if(ee < k) cout << "NO\n";
	else{
		if(n == 1 || m == 1){
			if(n == 1){
				if(k <= m-1){
					cout << "YES\n1\n" << k << " R\n";
				}else{
					cout << "YES\n2\n" << m-1 << " R\n" << k-m+1 << " L\n";
				}
			}else{
				if(k <= n-1){
					cout << "YES\n1\n" << k << " D\n";
				}else{
					cout << "YES\n2\n" << n-1 << " D\n" << k-n+1 << " U\n";
				}
			}
			return;
		}
		vector<pair<ll, string>> ops, ae;
		ll yt = 0;
		if(2*n-2 >= k){
			if(n-1 >= k){
				ops.pb({k, string("D")});
				yt+=k;
			}else{
				ops.pb({n-1, string("D")});
				ops.pb({k-n+1, string("U")});
				yt+=k;
			}
		}else{
			ops.pb({n-1, string("D")});
			ops.pb({n-1, string("U")});
			yt = 2*n-2;
			for(ll im = 1;im<m && yt < k;im++){
				if(yt+1 == k){
					ops.pb({1, string("R")});
					yt++;
				}else{
					ops.pb({1, string("R")});
					//ae.pb({1, string("L")});
					yt++;
					if(yt+3*(n-1) >= k){
						ll hm = (k-yt)/3;
						if(hm > 0) ops.pb({hm, string("DLR")});
						yt+=hm*3;
						if(yt+1 == k){
							ops.pb({1, string("D")});
							yt++;
						}else if(yt+2 == k){
							ops.pb({1, string("DL")});
							yt+=2;
						}
					}else{
						ops.pb({n-1, string("DLR")});
						yt+=3*n-3;
						if(yt+n-1 >= k){
							ops.pb({k-yt, string("U")});
							yt = k;
						}else{
							ops.pb({n-1, string("U")});
							yt+=n-1;
						}
					}
				}
			}
			if(yt < k){
				ops.pb({k-yt, string("L")});
			}
		}
		cout << "YES\n" << ops.size()+ae.size() << "\n";
		for(auto i : ops) cout << i.x << " " << i.y << '\n';
		//for(auto i : ae) cout << i.x << " " << i.y << '\n';
	}
}

signed main(){
	FAST;
	ll q = 1;
	//cin >> q;
	while(q--){
		solve();
	}
}