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

ll n, k;

ll p[100], l[100], pc = 0;

python solve(){
	FAST;
	ll n;
	cin >> n;
	ll on = n;
	memset(p, 0, sizeof(p));
	memset(l, 0, sizeof(l));
	pc = 0;
	// set<ll> rs;
	for(ll i = 2;i*i<=n;i++){
		if(on%i == 0){
			p[pc++] = i;
			while(on%i == 0){
				l[pc-1]++;
				on/=i;
			}
		}
	}
	if(on!=1) p[pc++] = on, l[pc-1] = 1;
	if(pc == 1){
		if(l[0] < 6) cout << "NO\n";
		else cout << "YES\n" << p[0] << " " << p[0]*p[0] << " " << n/(p[0]*p[0]*p[0])<<'\n';
	}else if(pc == 2){
		ll a1 = p[0], a2 = p[1], a3 = 0;
		ll xp = n/(a1*a2);
		if(xp >= 2 && xp != a1 && xp != a2){
			a3 = xp;
			cout << "YES\n"<<a1<<" " << a2 << " " << a3 << '\n';
		}else cout << "NO\n";
	}else{
		cout << "YES\n"<<p[0] << " " << p[1] << " " << (n/(p[0]*p[1])) << '\n';
	}
}

signed main(){
	FAST;
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}