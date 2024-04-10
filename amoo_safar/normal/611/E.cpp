#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll pw[4];
ll A[Maxn];

bool check(ll r1, ll r2, ll r3, ll X){
	ll d, x;
	x = X;
	d = min(r3, x);
	x -= d;
	r3 -= d;
	d = min(r2, x);
	x -= d;
	r2 -= d;
	d = min(r1, x);
	x -= d;
	r1 -= d;
	
	x = X;
	d = min(r2, x);
	x -= d;
	r2 -= d;
	d = min(r1, x);
	x -= d;
	r1 -= d;
	
	x = X;
	d = min(r1, x);
	x -= d;
	r1 -= d;
	return max({r1, r2, r3}) == 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < 3; i++) cin >> pw[i];
	sort(pw, pw + 3);
	ll a, b, c;
	a = pw[2]; b = pw[1]; c = pw[0];
	ll pre_ans = 0;
	for(int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	if(A[n - 1] > a + b + c) return cout << -1, 0;
	if(A[0] > a + b) return cout << n, 0;
	while(A[n - 1] > a + b) n--, pre_ans ++;
	
	ll ans = n;
	if(a > b + c){
		ll rb = 0, rc = 0, ra = 0;
		ll Rc, Rb, Ra;
		ll cc, cb, cbc;
		ll d;
		
		for(int i = n - 1; i >= 0; i--){
			if(A[i] > a + c) rc ++;
			else if(A[i] > a) rb ++;
			else ra ++;
			
			if(i > 0 && A[i - 1] > b + c) continue;
			cc = upper_bound(A, A + i, c) - A;
			cb = upper_bound(A, A + i, b) - A;
			cb -= cc;
			cbc = i - cb - cc;
			if(ra < cbc) continue;
			
			
			Rc = rc;
			Rb = rb;
			Ra = ra;
			
			d = min(Rc, cc);
			cc -= d;
			Rc -= d;
			
			d = min(Rb, cb);
			cb -= d;
			Rb -= d;
			
			d = min(Rb, cc);
			cc -= d;
			Rb -= c;
			
			Ra -= cbc;
			if(cc <= cb){
				if(Ra >= cb) ans = min(ans, n - i);
			} else {
				if(Ra >= ((cb + cc + 1) / 2)) ans = min(ans, n - i);
			}
		}
	} else {
		
		ll rb = 0, rc = 0, ra = 0;
		ll Rc, Rb, Ra;
		ll cc, cb, ca;
		ll d;
		for(int i = n; i >= 0; i--){
			if(i!=n){
				if(A[i] > a + c) rc ++;
				else if(A[i] > b + c) rb ++;
				else ra ++;
			}
			if(i > 0 && A[i - 1] > a) continue;
			cc = upper_bound(A, A + i, c) - A;
			cb = upper_bound(A, A + i, b) - A;
			cb -= cc;
			ca = i - cb - cc;
			//cerr << i << ' ' << cc << ' ' << cb << ' ' << ca << '\n';
			Rc = rc;
			Rb = rb;
			Ra = ra;
			
			d = min(Rc, cc);
			cc -= d;
			Rc -= d;
			/////
			d = min(Rb, cb);
			cb -= d;
			Rb -= d;
			
			d = min(Rb, cc);
			cc -= d;
			Rb -= d;
			////////
			
			d = min(Ra, ca);
			ca -= d;
			Ra -= d;
			
			d = min(Ra, cb);
			cb -= d;
			Ra -= d;
			
			d = min(Ra, cc);
			cc -= d;
			Ra -= d;
			
			//cerr << i << ' ' << cc << ' ' << cb << ' ' << ca << '\n';
			
			ll L = -1, R = n + 1, mid;
			while(L + 1 < R){
				mid = (L + R) >> 1;
				if(check(cc, cb, ca, mid)) R = mid;
				else L = mid;
			}
			//cerr << i << ' ' << R<<'\n';
			ans = min(ans, n - i + R);
		}
	}
	//cerr << check(4, 0, 0, 1) << '\n';
	//cerr << pre_ans << '\n';
	cout << ans + pre_ans;
	return 0;
}