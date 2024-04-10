#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1e9 + 9;
const int Maxn = 5e5 + 10;
const ll Inf = 1000000000000000LL;
ll b1 = 101;
ll b2 = 47;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}

stack< pair<pll, ll> > st;
map<pll, ll> mp;

void add(){
	if(st.empty()) mp[{-1, -1}]++;
	else mp[st.top().F] ++;
}

int MAIN(){
	ll n;
	cin >> n;
	while(st.size()){
		st.pop();
	}
	mp.clear();
	mp[{-1, -1}] ++;
	ll v;
	pair<pll, ll> pp;
	ll V1, V2;
	for(int i = 1; i <= n; i++){
		cin >> v;
		V1 = v + n;
		V2 = 2 * v + n - 1;
		if(st.empty()){
			st.push({{V1, V2}, v});
			add();
			continue;
		}
		if(v == st.top().S){
			st.pop();
			add();
		}else{
			pp.S = v;
			pp.F.F = (mul(st.top().F.F, b1) + V1) % Mod;
			pp.F.S = (mul(st.top().F.S, b2) + V2) % Mod;
			st.push(pp);
			add();
		}
	}
	ll ans = 0;
	for(auto x : mp){
		//cerr << x.S << '\n';
		ans += (x.S * (x.S - 1));
	}
	cout << ans / 2 << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}