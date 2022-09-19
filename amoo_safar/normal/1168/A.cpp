#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 10939;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 1e17;
const ll LOG = 30;

ll a[MAXN], n, m;

bool check(ll x){
	ll last = 0;
	for(int i = 0; i < n; i++){
		if(a[i] <= last){
			ll d = last - a[i];
			if(x >= d) last = last;
			else return false;	
		} else {
			ll d = a[i] - last;
			ll r = m - d;
			if(r <= x) last = last;
			else last = a[i];
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//ll n, m;
	cin >> n >> m;	
	for(int i = 0; i< n; i++) cin >> a[i];
	ll l = -1, r = MAXN, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << r;
	return 0;
}