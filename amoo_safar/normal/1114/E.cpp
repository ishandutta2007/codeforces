#include <bits/stdc++.h>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
 
const ld PI = 3.14159265359;
 
const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

set<ll> st;
vector<ll> num;
ll ans;

ll q = 60;
ll ask(ll x){
	q--;
	cout << "> " << x << endl;
	cin >> ans;
	return ans;
}
ll get(ll i){
	if(q <= 0) return 0;
	q --;
	cout << "? " << i << endl;
	cin >> ans;
	st.insert(ans);
	return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) num.pb(i);
    shuffle(all(num), rng);
	//q = 59;
    
    ll l = -1;
    ll r = 1000000001;
    ll mid;
    while(l + 1 < r){
		mid = (l + r) / 2;
		if(ask(mid) == 1) l = mid;
		else r = mid;
	}
	for(auto x : num) get(x);
	st.insert(r);
	vector<ll> nm;
	for(auto x : st){
		nm.pb(x);
	}
	ll d = 0;
	for(int i = 1; i< nm.size(); i++){
		d = __gcd(d, nm[i] - nm[i - 1]);
	}
	cout << "! " << r - (d * (n - 1)) << " " << d << endl;
	return 0;
}