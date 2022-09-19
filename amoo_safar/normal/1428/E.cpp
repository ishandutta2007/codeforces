// I'll Crush you !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N], p[N];

ll n, k;

ll Calc(ll x, ll y){
	ll d = x / y;
	ll cnt2 = (x % y);
	ll cnt = y - cnt2;
	return (d * d * cnt) + ((d + 1) * (d + 1) * cnt2);
}
ll Cost(ll i){
	if(p[i] == a[i]) return Inf;
	return Calc(a[i], p[i] + 1) - Calc(a[i], p[i]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	set<pll> st;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		p[i] = 1;
		ans += a[i] * a[i];
		st.insert({Cost(i), i});
	}
	while(k != n){
		ll fr = st.begin() -> S;
		ans += st.begin() -> F;
		p[fr] ++;
		st.erase(st.begin());
		st.insert({Cost(fr), fr});
		k --;
	}
	cout << ans << '\n';
	return 0;
}